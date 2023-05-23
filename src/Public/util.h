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
int32_t xCenterStr ( WINDOW* win, char* str );

/* Used in menuhandler to switch between highlighting different choices */
void printMenu ( WINDOW* win,
                int32_t y,
                char* optName[],
                int32_t optLen,
                int32_t optIndex );
                
int32_t menuOption ( WINDOW* obj,
		     int32_t yPos,
		     char* optName[],
		     int32_t maxName );

/* Functions used in setting up ncurses and errors */
int32_t initColor ( void );
void exitNc ( void );
void errMsg ( int32_t code, const char* format, ... );
void initNc ( void );

#endif /* END */
