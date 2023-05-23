/*
 * Main Program File
 *
 * @QWERTYghri
*/

/* libc */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>
#include <signal.h>

/* Posix */
#include <unistd.h>
#include <getopt.h>

/* Curses */
#include <ncurses.h>

/* Local Includes */
#include "./Public/game.h"
#include "./Public/util.h"
#include "./Public/decal.h"

/* Types */


/* Global Vars */
WINDOW* fWin, *bWin;

char* title[TITLE_ARR] =
{ 
	"---------------------------------------------------------------",
	" ____                                  _  ",
	"/ ___|___  _ __   __ _ _   _  ___  ___| |_",
	"| |   / _ \\| '_ \\ / _` | | | |/ _ \\/ __| __|",
	"| |__| (_) | | | | (_| | |_| |  __/\\__ \\ |_ ",
        " \\____\\___/|_| |_|\\__, |\\__,_|\\___||___/\\__|",
        "                     |_|                    ",
        "Made by QWERTYghri",
        "---------------------------------------------------------------"
};

char* nuke[NUKE_ARR] =
{
	"     _.-^^---....,,--       ",
	" _--                  --_   ",
	"<                        >) ",
	"|                         | ",
	" \\._                   _./  ",
	"    ```--. . , ; .--'''     ",
	"          | |   |            ",
	"       .-=||  | |=-.        ",
	"       `-=#$%&%$#=-'        ",
	"          | ;  :|            ",
	"  _____.,-#%&$@%#&#~,._____ "
};

char* tank[TANK_ARR] =
{
	"============================",
	"_____",
	"         ___(  *  )=======:: =>",
	"/~~~~T-72~~~~\\",
	"\\O.O.O.O.O.O/",
	"============================",
	"Choose a level difficulty"
};

/* Functions */

/* Handles argument inputs */
static void
readInput ( int argc, char** argv )
{
        int32_t optIndex        = 0;
        int32_t retVal          = 0;
        static struct option lngOpt[] =
        {
                { "help", no_argument, 0, 'h' },
                { "version", no_argument, 0, 'v' },
                { 0, 0, 0, 0 }
        };

        while ( ( retVal = getopt_long ( argc, argv, "hv", lngOpt, &optIndex ) ) != EOF )
        {
                if ( retVal == - 1 )
                        break;

                switch ( retVal )
                {
                        case 'h':
                                errMsg ( EXIT_SUCCESS, HELP );
                                break;
                        case 'v':
                                errMsg ( EXIT_SUCCESS, VERS );
                                break;
                        default:
                                errMsg ( EXIT_SUCCESS, UKN_ARG );
                                break;
                }
        }

        if ( optind < argc )
                errMsg ( EXIT_FAILURE, NO_ARG );
}

/* Handles the initial menu option choices  * Perhaps we can change this to something more portable instead * */
static int32_t
menuHandler ()
{
        char* optNames[OPT_ARR] =
        {
                "Play Game",
                "About",
                "End Game"
        };
                        
	return menuOption ( fWin, MENU_Y_OFFSET, optNames, OPT_ARR );
}

/*Set up back windows */
static void
baseSetUp ( void )
{
        fWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, centerPos ( LINES, GAME_WINDOW_Y ), centerPos ( COLS, GAME_WINDOW_X ) );
        bWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, centerPos ( LINES, GAME_WINDOW_Y ) + 1, centerPos ( COLS, GAME_WINDOW_X ) + 1 );

        wbkgd ( bWin, COLOR_PAIR ( ColorBlack ) );
        wbkgd ( fWin, COLOR_PAIR ( ColorGrey ) );
        bkgd ( COLOR_PAIR ( ColorBlue ) );

        box ( fWin, 0, 0 );
	printArt ( fWin, TITLE_Y_OFFSET, title, TITLE_ARR );
	printArt ( fWin, NUKE_Y_OFFSET, nuke, NUKE_ARR );

        refresh ();
        wrefresh ( bWin );
        wrefresh ( fWin );
}

static void
levelSetUp ( int32_t lvl )
{

}

static void
playGame ( void )
{
	WINDOW* optPlay = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, 0, 0 );

	werase ( fWin );
	
	box ( optPlay, 0, 0 );
	wbkgd ( optPlay, COLOR_PAIR ( ColorGrey ) );
	wrefresh ( fWin );
	wrefresh ( optPlay );
	
	delwin ( optPlay );
	getch ();
}

/* Sets up windows and levels to play game */
static int32_t
playLvl ()
{
	char* optName[LVL_MAX] =
	{
		"Easy",
		"Medium",
		"Hard",
		"Return to Menu"
	};
	
	int32_t retVal = 0;
	WINDOW* playWin	= newwin ( DIFF_WINDOW_Y, DIFF_WINDOW_X, centerPos ( LINES, DIFF_WINDOW_Y ), centerPos ( COLS, DIFF_WINDOW_X ) );
	
	werase ( fWin );
 	wbkgd ( playWin, COLOR_PAIR ( ColorGrey ) );
	box ( playWin, 0, 0 );
	box ( fWin, 0, 0 );
	
	printArt ( playWin, 2, tank, TANK_ARR );
	
	wrefresh ( fWin );
	wrefresh ( playWin );	
	
	retVal = menuOption ( playWin, ( DIFF_WINDOW_Y / 2 ) - ( LVL_MAX - 1 ), optName, LVL_MAX );
	if ( retVal == 3 )
		return 1;
		
	levelSetUp ( retVal );
	playGame ();
	delwin ( playWin );
	
        return 0;
}

/* Display an about msg */
static int32_t
aboutMsg ()
{
	WINDOW* aboutWin = newwin ( ABOUT_WINDOW_Y, ABOUT_WINDOW_X, centerPos ( LINES, ABOUT_WINDOW_Y ), centerPos ( COLS, ABOUT_WINDOW_X ) );
	int32_t ret;
	
        werase ( fWin );
        wbkgd ( aboutWin, COLOR_PAIR ( ColorGrey ) );
        mvwprintw ( aboutWin, 1, 1, ABOUTSTR );
        
        box ( fWin, 0, 0 );
        box ( aboutWin, 0, 0 );
        
        wrefresh ( fWin );
        wrefresh ( aboutWin );
        delwin ( aboutWin );
        
        while ( ( ret = getch () ) != 'e' && ret != EOF );
        
        return 1;
}

/* Exit the game */
static int32_t
endGame ()
{
	delwin ( fWin );
        delwin ( bWin );

        exitNc ();
        errMsg ( EXIT_SUCCESS, THANK_YOU );
        
        return 2;
}

static void
game ( void )
{
	int32_t ( *optList[OPT_ARR] ) ( void ) = { playLvl, aboutMsg, endGame };
_reset:
        baseSetUp ();
        if ( optList[menuHandler ()] () == 1 )
        	goto _reset;
        
        getch ();

        delwin ( fWin );
        delwin ( bWin );
}

int
main ( int argc, char** argv )
{
        initNc ();
        
        readInput ( argc, argv );
        game ();
        
        exitNc ();

        return 0;
}
