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
#include "./Public/handler.h"

/* Macros */
#define GAME_WINDOW_X ( COLS - 10 )
#define GAME_WINDOW_Y ( LINES - 10 )

#define HELP            ( "About:\n\tConquest is a Grand Strategy type game in which you invade other countries and increase your economy through trade and more.\n\n" )
#define VERS            ( "Version: 1.0R\n\n" )

/* Size index */
#define TITLE_ARR       ( 9 )
#define NUKE_ARR        ( 11 )
#define OPT_ARR         ( 3 )

/* Y offsets */
#define TITLE_Y_OFFSET  ( 6 )
#define MENU_Y_OFFSET   ( TITLE_Y_OFFSET + 10 )
#define NUKE_Y_OFFSET   ( 25 )

/* Enums */
enum { 
        CursInvis,
        CursVis
};

enum {
        ColorBlack,
        ColorBlue,
        ColorGrey,
        
        ColorTextRed,
        ColorSelect,
};

/* Global Vars */
WINDOW* fWin, *bWin;

/* Functions */
static int32_t
initColor ( void )
{
        if ( has_colors () )
                start_color ();
        else
                return -1;

        init_pair ( ColorBlack, COLOR_BLACK, COLOR_BLACK );
        init_pair ( ColorBlue, COLOR_BLUE, COLOR_BLUE );
        init_pair ( ColorGrey, COLOR_BLACK, COLOR_WHITE );
        init_pair ( ColorTextRed, COLOR_RED, COLOR_BLACK );

        init_pair ( ColorSelect, COLOR_WHITE, COLOR_BLUE );
       
        return 0;
}

static void
exitNc ( void )
{
        erase ();
        refresh ();
        endwin ();
}

static void
errMsg ( const char* msg, int32_t code )
{
        exitNc ();
        fprintf ( stderr, "%s",  msg );
        exit ( code );
}

static void
initNc ( void )
{
        initscr ();
        //raw ();
        noecho ();
        nonl ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );

        if ( initColor () != 0 )
                errMsg ( "Error: Colors are not supported by terminal\nExitting...\n", EXIT_FAILURE );
}

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
                                errMsg ( "Unknown argument\n\nArgs:\n\t--help\n\t--Version\n", EXIT_SUCCESS );
                                break;
                }
        }

        if ( optind < argc )
                errMsg ( "No argument or unformatted argument\n\n", EXIT_SUCCESS );
}

static void
baseSetUp ( void )
{
        fWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, ( LINES - GAME_WINDOW_Y ) / 2, ( COLS - GAME_WINDOW_X ) / 2 );
        bWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, ( LINES - GAME_WINDOW_Y ) / 2 + 1, ( COLS - GAME_WINDOW_X ) / 2 + 1 );

        wbkgd ( bWin, COLOR_PAIR ( ColorBlack ) );
        wbkgd ( fWin, COLOR_PAIR ( ColorGrey ) );
        bkgd ( COLOR_PAIR ( ColorBlue ) );

        box ( fWin, 0, 0 );

        refresh ();
        wrefresh ( bWin );
        wrefresh ( fWin );
}

/* Calculates an appropriate offset for a string to be placed in the center */
static int32_t
xCenterStr ( WINDOW* win, char* str )
{
        int32_t yLen, xLen;
        getmaxyx ( win, yLen, xLen );

        return ( xLen / 2 ) - ( strlen ( str ) / 2 );
}

static void
printMenuDp (   WINDOW* win,
                int32_t y,
                int32_t hlSize,
                char* optName[], int32_t optLen,
                int32_t optIndex )
{
        for ( int32_t i = 0; i < optLen; i++ )
        {
                if ( i == optIndex )
                        wattron ( win, COLOR_PAIR ( ColorSelect ) );

                mvwaddstr ( win, y + i, xCenterStr ( win, optName[i] ), optName[i] );
                wattroff ( win, COLOR_PAIR ( ColorSelect ) );
        }

        wrefresh ( win );
}

static void
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

        printMenuDp ( fWin, MENU_Y_OFFSET, 10, optNames, OPT_ARR, optInc );

        while ( ( input = getch () ) != EOF )
        {
                switch ( input )
                {
                        case KEY_DOWN:
                                optInc++;
                                if ( optInc == 3 )
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
                                wprintw ( fWin, "test" );
                                wrefresh ( fWin );
                                menuJmpTab[optInc] ();

                                break;
                }

                printMenuDp ( fWin, MENU_Y_OFFSET, 10, optNames, OPT_ARR, optInc );
        }
}

static void
titleMenu ( void )
{
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
        menuHandler ();
}

static void
game ( void )
{
        baseSetUp ();
        titleMenu ();
        
        getch ();

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
