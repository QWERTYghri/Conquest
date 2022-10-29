/*
 *
 * Util.h for ncurses simplifications and stuff*
 * 
 *  * 3D Window table display
 *  * print menu input display function
 * @QWERTYghri
 *
*/


#ifndef UTIL_H
#define UTIL_H

#include <ncurses.h>
#include <stdint.h>


/*============="3d" WIN SET=============*/

typedef struct HOIWIN
{
	WINDOW* fWin, *bWin;
	uint32_t fWinCl, bWinCl, box;
} HOIWIN;

typedef void ( *func ) ( void );

/* Requires start_color to be called */
void drawHoiWin ( HOIWIN* win );

HOIWIN* initHoiWin ( WINDOW* fWin, WINDOW* bWin,
		  uint32_t fWinCl, uint32_t bWinCl,
		  uint32_t box );

void delHoiWin ( HOIWIN* win );

/*=================END================*/
/*===============MENUOPT==============*/


/* Menu option function to display a certain part of a option list given a set of arguments */
/* char* scary */
void display ( WINDOW* winSpot, uint32_t posY, uint32_t posX,
                uint32_t ch, char** optList, func* list[], uint32_t attr, uint32_t strn );

#endif
