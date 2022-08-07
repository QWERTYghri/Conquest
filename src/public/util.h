/*
 *
 * Util.h for ncurses simplifications and stuff*
 *
 * @QWERTYghri
 *
*/


#ifndef UTIL_H
#define UTIL_H

#include <ncurses.h>
#include <stdint.h>

typedef struct HOIWIN
{
	WINDOW* fWin, bWin;
	uint32_t fWinCl, bWinCl, box;
} HOIWIN;


/* Requires start_color to be called */
void drawHoiWin ( HOIWIN* win );

HOIWIN* initHoiWin ( WINDOW* fWin, WINDOW* bWin,
		  uint32_t fWinCl, uint32_t bWinCl,
		  uint32_t box );

void delHoiWin ( HOIWIN* win );

#endif
