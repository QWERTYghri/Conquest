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

void display ( WINDOW* winSpot, uint32_t ch, char** optList, uint32_t attr )
{
	int32_t YS, XS;
	
	getmaxyx ( winSpot, YS, XS );
	
}
