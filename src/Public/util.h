/* Utility declration functions for main.c */

#ifndef UTIL_H
#define UTIL_H

#include <stdint.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

enum {
        ColorBlack,
        ColorBlue,
        ColorGrey,
        
        ColorTextRed,
        ColorSelect,
};

enum { 
        CursInvis,
        CursVis
};

/* Calculates an appropriate offset for a string to be placed in the center */
extern int32_t xCenterStr ( WINDOW* win, char* str );

/* Used in menuhandler to switch between highlighting different choices */
extern void printMenuDp (   WINDOW* win,
                int32_t y,
                int32_t hlSize,
                char* optName[], int32_t optLen,
                int32_t optIndex );

/* Functions used in setting up ncurses and errors */
int32_t initColor ( void );
void exitNc ( void );
void errMsg ( const char* msg, int32_t code );
void initNc ( void );

#endif /* END */
