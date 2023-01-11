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

/* Posix */
#include <unistd.h>

/* Curses */
#include <ncurses.h>

/* Macros */

/* Enums */
enum {
        CursVis, 
        CursInvis
};

static void
exitNc ( void )
{
        erase ();
        refresh ();
        endwin ();
}

static void
initNc ( void )
{
        initscr ();
        raw ();
        noecho ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );
}

int
main ( int argc, char** argv )
{
        setlocale ( LC_ALL, "" );
        initNc ();



        exitNc ();

        return 0;
}
