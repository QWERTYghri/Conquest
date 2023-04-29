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
#include "./Public/util.h"
#include "./Public/decal.h"

/* Macros */
#define GAME_WINDOW_Y ( LINES - 10 )
#define GAME_WINDOW_X ( COLS - 10 )

#define ABOUT_WINDOW_Y ( GAME_WINDOW_Y - 30 )
#define ABOUT_WINDOW_X ( GAME_WINDOW_X - 30 )

/* Size index */
#define OPT_ARR         ( 3 )

/* Y offsets */
#define TITLE_Y_OFFSET  ( 6 )
#define MENU_Y_OFFSET   ( TITLE_Y_OFFSET + 10 )
#define NUKE_Y_OFFSET   ( 25 )

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

/* Functions */
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
                                errMsg ( HELP, EXIT_SUCCESS );
                                break;
                        case 'v':
                                errMsg ( VERS, EXIT_SUCCESS );
                                break;
                        default:
                                errMsg ( UKN_ARG, EXIT_SUCCESS );
                                break;
                }
        }

        if ( optind < argc )
                errMsg ( NO_ARG, EXIT_SUCCESS );
}

static int32_t
menuHandler ()
{
        char* optNames[OPT_ARR] =
        {
                "Play Game",
                "About",
                "End Game"
        };

        int32_t         optInc  = 0,
                        input   = 0;

        printMenuDp ( fWin, MENU_Y_OFFSET, optNames, OPT_ARR, optInc );
        while ( ( input = getch () ) != EOF )
        {
                switch ( input )
                {
                        case KEY_DOWN:
                                optInc++;
                                if ( optInc == OPT_ARR )
                                        optInc = 0;

                                break;
                        case KEY_UP:
                                if ( optInc <= 0 ) {
                                        optInc = 2;
                                        break;
                                }

                                optInc--;
                                break;
                        case 'e':
                        	return optInc;
                }
                printMenuDp ( fWin, MENU_Y_OFFSET, optNames, OPT_ARR, optInc );
        }
        
        return 0; /* That way if something fails it just exits with no description*/
}

static void
titleMenu ( void )
{
        int32_t yInc    = 0;

        /* xCenterStr's offsets don't make sense but I was lazy */
        /* Printing Title Arr */
        for ( int32_t i = 0; i < TITLE_ARR; i++ ) {
                mvwaddstr ( fWin,  TITLE_Y_OFFSET + yInc, xCenterStr ( fWin, title[i] ), title[i] );
                yInc++;
        }

        yInc = 0;

        /* Print Nuke */
        for ( int32_t i = 0; i < NUKE_ARR; i++ ) {
                mvwaddstr ( fWin, NUKE_Y_OFFSET + yInc, xCenterStr ( fWin, nuke[i] ), nuke[i] );
                yInc++;
        }

        wrefresh ( fWin );
}

/* change to inline once you can fix the problem with it */
int32_t
centerPos ( int32_t baseVal, int32_t size )
{
	return ( baseVal - size ) / 2;
}

static void
baseSetUp ( void )
{
        fWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, centerPos ( LINES, GAME_WINDOW_Y ), centerPos ( COLS, GAME_WINDOW_X ) );
        bWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, centerPos ( LINES, GAME_WINDOW_Y ) + 1, centerPos ( COLS, GAME_WINDOW_X ) + 1 );

        wbkgd ( bWin, COLOR_PAIR ( ColorBlack ) );
        wbkgd ( fWin, COLOR_PAIR ( ColorGrey ) );
        bkgd ( COLOR_PAIR ( ColorBlue ) );

        box ( fWin, 0, 0 );

        refresh ();
        wrefresh ( bWin );
        wrefresh ( fWin );
}

static void
playGame ()
{
        
}

static void
aboutMsg ()
{
	WINDOW* aboutWin = newwin ( ABOUT_WINDOW_Y, ABOUT_WINDOW_X, centerPos ( LINES, ABOUT_WINDOW_Y ), centerPos ( COLS, ABOUT_WINDOW_X ) );
	
        werase ( fWin );
        box ( fWin, 0, 0 );
        box ( aboutWin, 0, 0 );
        wbkgd ( aboutWin, COLOR_PAIR ( ColorGrey ) );
        
        wprintw ( aboutWin, "help" );
        
        wrefresh ( fWin );
        wrefresh ( aboutWin );
        delwin ( aboutWin );
}

static void
endGame ()
{
        exitNc ();
        errMsg ( THANK_YOU, EXIT_SUCCESS );
}

static void
game ( void )
{
	void ( *optList[OPT_ARR] ) ( void ) = { playGame, aboutMsg, endGame };

        baseSetUp ();
        titleMenu ();
        optList[menuHandler ()] ();
        

        delwin ( fWin );
        delwin ( bWin );
}

int
main ( int argc, char** argv )
{
        setlocale ( LC_ALL, "" );
        initNc ();
        
        readInput ( argc, argv );
        game ();
        
        exitNc ();

        return 0;
}
