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
#define GAME_WINDOW_X ( COLS - 10 )
#define GAME_WINDOW_Y ( LINES - 10 )

#define HELP            ( "About:\n\tConquest is a Grand Strategy type game in which you invade other countries and increase your economy through trade and more.\n\n" )
#define VERS            ( "Version: 1.0R\n\n" )

/* Size index */
#define OPT_ARR         ( 3 )

/* Y offsets */
#define TITLE_Y_OFFSET  ( 6 )
#define MENU_Y_OFFSET   ( TITLE_Y_OFFSET + 10 )
#define NUKE_Y_OFFSET   ( 25 )

/* Global Vars */
WINDOW* fWin, *bWin;

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
                                errMsg ( "Unknown argument\n\nArgs:\n\t--help\n\t--version\n", EXIT_SUCCESS );
                                break;
                }
        }

        if ( optind < argc )
                errMsg ( "No argument or unformatted argument\n\n", EXIT_SUCCESS );
}

static void
playGame ()
{
        wprintw ( fWin, "test" );
}

static void
aboutMsg ()
{
        wprintw ( fWin, "test1" );
}

static void
endGame ()
{
        exitNc ();
        exit ( EXIT_SUCCESS );
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
                                switch ( optInc )
                                {
                                        case 0:
                                                playGame ();
                                                break;
                                        case 1:
                                                aboutMsg ();
                                                break;
                                        case 2:
                                                endGame ();
                                                break;
                                }

                                break;
                }
                printMenuDp ( fWin, MENU_Y_OFFSET, 10, optNames, OPT_ARR, optInc );
        }
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

static void
game ( void )
{
        baseSetUp ();
        titleMenu ();
        menuHandler ();
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
