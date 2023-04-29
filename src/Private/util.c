/*
 * Defined functions for util.h
 *
 */

#include <stdint.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "../Public/util.h"
#include "../Public/decal.h"

/* Calculates an appropriate offset for a string to be placed in the center */
extern int32_t
xCenterStr ( WINDOW* win, char* str )
{
        int32_t yLen, xLen;
        getmaxyx ( win, yLen, xLen );

        return ( xLen / 2 ) - ( strlen ( str ) / 2 );
}

/* Used in menuhandler to switch between highlighting different choices */
extern void
printMenuDp (   WINDOW* win,
                int32_t y,
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

extern int32_t
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

        init_pair ( ColorSelect, COLOR_WHITE, COLOR_GREEN );
       
        return 0;
}

extern void
exitNc ( void )
{
        erase ();
        refresh ();
        endwin ();
}

extern void
errMsg ( const char* msg, int32_t code )
{
        exitNc ();
        fprintf ( stderr, "%s",  msg );
        exit ( code );
}

extern void
initNc ( void )
{
        initscr ();
        //raw ();
        noecho ();
        nonl ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );

        if ( initColor () != 0 )
                errMsg ( ERR_COLOR, EXIT_FAILURE );
}

