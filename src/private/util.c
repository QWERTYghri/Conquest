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
	wbkgd ( ( WINDOW* ) win -> fWin, win -> fWinCl );
	wbkgd ( ( WINDOW * ) win -> bWin, win -> bWinCl );
	
	/* wtf  eh doesn't matter for now, it'd be annoying to use panels.h*/	
	if ( win -> box == 0 )
		box ( win -> fWin );
	
	wrefresh ( fWin );
	wrefresh ( bWin );
}

HOIWIN* initHoiWin (  WINDOW* fWina, WINDOW* bWina, uint32_t fWinCla, uint32_t bWinCla, uint32_t boxa )
{
	HOIWIN* hWin = malloc ( sizeof ( HOIWIN ) );
	
	hWin -> fWin	= fWina;
	hWin -> bWin	= bWina;
	hWin -> fWinCl	= fWinCla;
	hWin -> bWinCl	= bWinCla;
	hWin -> box	= boxa;
	
	return hWin;
}

void delHoiWin ( HOIWIN* win )
{
	free ( win );
}
