/*
 * Main Program File
 *
 * btw if your kinda pedantic, don't mind possible memory leaks and weird includes...
 * @QWERTYghri
*/

/* libc */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* Posix */
#include <unistd.h>
#include <getopt.h>
#include <pthread.h>

/* Curses */
#include <ncurses.h>

/* Local Includes */
#include "./Public/game.h"
#include "./Public/util.h"
#include "./Public/decal.h"

/* Types */


/* Global Vars */
WINDOW* fWin, *bWin;
GameState* curGame;

WINDOW* optPlay, *gameWin;

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

char* star[STAR_ARR] =
{
".",
",O,",
",OOO,",
"\'oooooOOOOOooooo\'",
"`OOOOOOOOOOO`",
"`OOOOOOO`",
"OOOO\'OOOO",
"OOO\'   \'OOO",
"O\'         \'O"
};

char* floppy[FLOPPY_ARR] =
{
	"==================================",
	" _________________",
	"|# :           : #|",
	"|  : Conquest  :  |",
	"|  :           :  |",
	"|  : 1981: 45  :  |",
	"|  :___________:  |",
	"|     _________   |",
	"|    | __      |  |",
	"|    ||  |     |  |",
	"\\____||__|_____|__|",
	"==================================",
	"Enter the path of a .scon file or press esc to return",
	"Search the ~/.conquest folder in your home directory"
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
                "Load Game",
                "About",
                "End Game"
        };
        
	return menuOption ( fWin, MENU_Y_OFFSET, optNames, OPT_ARR );
}

static void
gameInit ( void )
{
	char name[NAME_MAX];

	getlogin_r ( name, NAME_MAX );
	curGame = initGame ( name, 0 );
}

/*Set up back windows */
static void
windowInit ( void )
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

/* Actual game part */
/*************************************************************************/

static void
editVal ( float modifier )
{
	
}

static void*
valueUpdate ( void* arg )
{	
	float modifier;

	switch ( curGame -> difficulty )
	{
		case 0:
			modifier = 0.00f;
			break;
		case 1:
			modifier = 0.25f;
			break;
		case 2:
			modifier = 0.50f;
			break;
	}
	
	while ( 1 )
	{
		editVal ( modifier );
		napms ( VAL_DELAY );
	}
	
	return NULL;
}

static void*
thInput ( void* arg )
{
	char* optList[GAME_OPT] =
	{
		"Country",
		"Diplomacy",
		"Economy",
		"Technology",
		"Military",
		"View Other Countries",
		"Status",
		"Save Game",
		"Exit Game"
	};
	int32_t retVal = 0;
	
	while ( 1 )
	{
		wprintw ( gameWin, "%d", curGame -> countries[1].General.money );
		wrefresh ( gameWin );
		
		retVal = menuOption ( optPlay, GAME_Y_OFFSET, optList, GAME_OPT );
	}
	
	return NULL;
}

static void
playGame ( void )
{
	optPlay = newwin ( GAME_WINDOW_Y, OPTION_X , POS_PLAY, POS_PLAY );
	gameWin	= newwin ( GAME_WINDOW_Y, GAME_WINDOW_X - OPTION_X, POS_PLAY, OPTION_X + 5 );
	
	pthread_t	inputObj,
			valUpdate;
	
	werase ( fWin );
	box ( optPlay, 0, 0 );
	box ( gameWin, 0, 0 );
	
	printArt ( optPlay, ICON_Y_OFFSET, star, STAR_ARR );
	
	wbkgd ( gameWin, COLOR_PAIR ( ColorGrey ) );
	wbkgd ( optPlay, COLOR_PAIR ( ColorGrey ) );
	
	wrefresh ( fWin );
	wrefresh ( optPlay );
	wrefresh ( gameWin );

	pthread_create ( &inputObj, NULL, thInput, NULL );
	pthread_create ( &valUpdate, NULL, valueUpdate, NULL );
	pthread_join ( inputObj, NULL );
	pthread_join ( inputObj, NULL );
	
	delwin ( optPlay );
	delwin ( gameWin );
}

/* Menu Handler functions */
/*************************************************************************/

/* Sets up windows and levels to play game */
static int32_t
levelMenu ( void )
{
	char* optName[LVL_MENU_MAX] =
	{
		"Easy",
		"Medium",
		"Hard",
		"Return to Menu"
	};
	
	int32_t retVal = 0;
	WINDOW* levelWin = newwin ( DIFF_WINDOW_Y, DIFF_WINDOW_X, centerPos ( LINES, DIFF_WINDOW_Y ), centerPos ( COLS, DIFF_WINDOW_X ) );
	
	werase ( fWin );
 	wbkgd ( levelWin, COLOR_PAIR ( ColorGrey ) );
	box ( levelWin, 0, 0 );
	box ( fWin, 0, 0 );
	printArt ( levelWin, 2, tank, TANK_ARR );
	
	wrefresh ( fWin );
	wrefresh ( levelWin );	
	
	retVal = menuOption ( levelWin, ( DIFF_WINDOW_Y / 2 ) - ( LVL_MENU_MAX - 1 ), optName, LVL_MENU_MAX );
	if ( retVal == 3 )
		return EXIT_RET; // exit to return back to the menu
		
	curGame -> difficulty = retVal;
	playGame ();
	delwin ( levelWin );
	
        return 0;
}

static int32_t
loadMenu ( void )
{
	WINDOW* loadWin = newwin ( DIFF_WINDOW_Y, DIFF_WINDOW_X, centerPos ( LINES, DIFF_WINDOW_Y ), centerPos ( COLS, DIFF_WINDOW_X ) );
	char	buf[MAX_STRING];
	int32_t retGetch;
	int32_t retAcc = -3; // Set to not anger the error code
	
	/* While the file name isn't correct */
	do {
	werase ( fWin );
	werase ( loadWin );
	wbkgd ( loadWin, COLOR_PAIR ( ColorGrey ) );
	printArt ( loadWin, 2, floppy, FLOPPY_ARR );
	
	box ( loadWin, 0, 0 );
	box ( fWin, 0, 0 );

	/* Invalid file */
	if ( retAcc == -1 )
		mvwaddstr ( loadWin, GETSTR_Y_OFFSET + 2, xCenterStr ( loadWin, INVALID_FILE ), INVALID_FILE );
	
	wrefresh ( fWin );
	wrefresh ( loadWin );

	/* Input string for save file */
	echo ();
	nl ();

	/* Zero out buffer */
	for ( int64_t i = 0; i < MAX_STRING; i++ )
		buf[i] = 0;
		
	/* Input to buffer */
	if ( ( retGetch = getch () ) == ESC )
	{
		nonl ();
		noecho ();
		return EXIT_RET;
	}
	
	mvwgetnstr ( loadWin, GETSTR_Y_OFFSET, xCenterStrBuf ( loadWin, MAX_STRING ), buf, MAX_STRING  ); // temp
	buf[strcspn ( buf, "\r\n" )] = 0; // being paranoid
	retAcc = fileCheck ( buf );
	
	} while ( retAcc != 0 );
	curGame = loadGame ( buf );
	
	nonl ();
	noecho ();
	
	delwin ( loadWin );
	playGame ();		// Exit load and enter levelMenu after loading game
	
	return 1;
}

/* Display an about msg */
static int32_t
aboutMenu ( void )
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
        
        // Ew
        while ( ( ret = getch () ) != ENTER && ret != EOF && ret != KEY_ENTER && ret != 'e' );
        
        return EXIT_RET;
}

/* Exit the game */
static int32_t
endGame ( void )
{
	delwin ( fWin );
        delwin ( bWin );

        exitNc ();
        errMsg ( EXIT_SUCCESS, THANK_YOU );
        
        return 3;
}

static void
game ( void )
{
	int32_t ( *optList[OPT_ARR] ) ( void ) = { levelMenu, loadMenu, aboutMenu, endGame };
 	
        do {
                windowInit ();
        } while ( optList[menuHandler ()] () == EXIT_RET );

        delwin ( fWin );
        delwin ( bWin );
}

int
main ( int argc, char** argv )
{
        readInput ( argc, argv );
        
        initNc ();
        gameInit ();
        game ();
             
        exitNc ();
        return 0;
}
