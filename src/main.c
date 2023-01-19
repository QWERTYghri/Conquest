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

/* Macros */
#define GAME_WINDOW_X ( COLS - 10 )
#define GAME_WINDOW_Y ( LINES - 10 )

/* Enums */
enum {
        CursVis, 
        CursInvis
};

enum {
        ColorBlack,
        ColorBlue,
        ColorGrey
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
        perror ( msg );
        exit ( code );
}

static void
initNc ( void )
{
        initscr ();
        raw ();
        noecho ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );

        if ( initColor () != 0 )
                errMsg ( "Error: Colors are not supported by terminal\nExitting...\n", EXIT_FAILURE );
}

static void
readInput ( int argc, char** argv )
{
        
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
baseMenu ( void )
{
        int32_t winY, winX;
        char* tmp = "set";

        getmaxyx ( fWin, winY, winX );

        mvwprintw ( fWin, winY / 2, winX - strlen ( tmp ), "%s", tmp );
        refresh ();
        wrefresh ( fWin );
}

static void
game ( void )
{
        baseSetUp ();

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
