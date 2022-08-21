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
	wbkgd ( win -> fWin, win -> fWinCl );
	wbkgd ( win -> bWin, win -> bWinCl );
	
	/* wtf  eh doesn't matter for now, it'd be annoying to use panels.h*/	
	if ( win -> box == 0 )
		box ( win -> fWin, 0, 0 );
	
	wrefresh ( win -> fWin );
	wrefresh ( win -> bWin );
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

void display ( WINDOW* winSpot, uint32_t ch, char* optList, uint32_t attr )
{
	int32_t YS, XS;
	
	getmaxyx ( winSpot, YS, XS );
	
}
