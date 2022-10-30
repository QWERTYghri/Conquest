/*
 * util.c C file
 *
 *
 * Util definitions from util.h
 *
 * @QWERTYghri
*/

#include <ncurses.h>
#include <stdlib.h>
#include "../public/util.h"

void drawHoiWin ( HOIWIN* win )
{
        wbkgd ( win -> bWin, COLOR_PAIR ( win -> bWinCl ) );
        wbkgd ( win -> fWin, COLOR_PAIR ( win -> fWinCl ) );

        if ( win -> box > 0 )
                box ( win -> fWin, 0, 0 );

        wrefresh ( win -> bWin );
        wrefresh ( win -> fWin );
}

HOIWIN* initHoiWin (  WINDOW* fWina, WINDOW* bWina,
                      uint32_t fWinCla, uint32_t bWinCla, 
                      uint32_t boxa )
{

	HOIWIN* hWin = calloc ( 1, sizeof ( HOIWIN ) );
	
	hWin -> fWin	= fWina;
	hWin -> bWin	= bWina;
	hWin -> fWinCl	= fWinCla;
	hWin -> bWinCl	= bWinCla;
	hWin -> box	= boxa;
	
	return hWin;
}

void delHoiWin ( HOIWIN* win ) {
	free ( win );
}

void display ( WINDOW* winSpot, uint32_t posY, uint32_t posX,
                char** optList, uint32_t strAmt, uint32_t attr )
{
        uint32_t y, x, valIn, opt = 0;

        getmaxyx ( winSpot, y, x );

        if ( strAmt > y )
                return -1; /* Error since window overlap, BUT I AIN'T DOING THE STR LEN FOR EACH ONE */

        while ( valIn = wgetch ( winSpot ) )
        {
                if ( valIn == KEY_UP || valIn == 'k' ) {
                        if ( opt <= 0 )
                                opt = strAmt;
                        else
                                opt--;
                } else if ( valIn == KEY_DOWN || valIn == 'j' ) {
                        if ( opt >= strAmt )
                                opt = 0;
                        else
                                opt++;
                }
        }
}
