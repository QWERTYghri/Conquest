/*
 * Defined functions for util.h
 *
 */

/* lib */
#include <stdint.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* local */
#include "../Public/util.h"
#include "../Public/decal.h"

/* Calculates an appropriate offset for a string to be placed in the center */
int32_t
xCenterStr ( WINDOW* win, char* str )
{
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
        int32_t yLen, xLen;
        getmaxyx ( win, yLen, xLen );

        return ( xLen / 2 ) - ( strlen ( str ) / 2 );
}

int32_t
xCenterStrBuf ( WINDOW* win, int64_t buffer )
{
	#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
        int32_t yLen, xLen;
        getmaxyx ( win, yLen, xLen );	
        
        return ( xLen / 2 ) - ( buffer / 2  );
}

/* wtf inline not inline?*/
int32_t
centerPos ( int64_t baseVal, int64_t size )
{
	return ( baseVal - size ) / 2;
}

/* Used in menuhandler to switch between highlighting different choices */
void
printMenu (   WINDOW* win,
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

int32_t 
menuOption ( WINDOW* obj,
	     int32_t yPos,
	     char* optName[],
	     int64_t maxName )
{
	int32_t		optInc = 0,
			input = 0;
	
	printMenu ( obj, yPos, optName, maxName, optInc );
	while ( ( input = getch () ) != EOF )
	{
		switch ( input )
		{
			case KEY_DOWN:
				optInc++;
				if ( optInc == maxName )
					optInc = 0;
				break;
			case KEY_UP:
				if ( optInc <= 0 ) {
					optInc = maxName - 1;
					break;
				}
				
				optInc--;
				break;
			case KEY_ENTER:
			case ENTER:
			case 'e':
				return optInc;
		}
		printMenu ( obj, yPos, optName, maxName, optInc );
	}
	
	return 0;
}

void
printArt ( WINDOW* obj, int32_t yPos, char* str[], int64_t strMax )
{
	int32_t yInc = 0;
	
	for ( int32_t i = 0; i < strMax; i++ ) {
		mvwaddstr ( obj, yPos + yInc, xCenterStr ( obj, str[i] ), str[i] );
		yInc++;
	}
}

int32_t
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

void
exitNc ( void )
{
        erase ();
        refresh ();
        endwin ();
}

void
errMsg ( int32_t code, const char* format, ... )
{
	va_list set;
	va_start ( set, format );
	vfprintf ( stderr, format, set );

	exitNc ();
	va_end ( set );
	exit ( code );
}

void
initNc ( void )
{		
        setlocale ( LC_ALL, "" );
        initscr ();
        
        if ( LINES < MIN_LINES && COLS < MIN_COLS )
		errMsg ( EXIT_FAILURE, WIN_SIZE );
	 
        //raw ();
        noecho ();
        nonl ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );

        if ( initColor () != 0 )
                errMsg ( EXIT_FAILURE, ERR_COLOR );
}

