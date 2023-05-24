/*
 * Utility declration functions for main.c
 * Functions for initialization ncurses or calculating window positions.
 */

#ifndef UTIL_H
#define UTIL_H

/* lib */
#include <stdint.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

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

/* Used to calculate positions to center out a strings or windows*/
int32_t xCenterStr ( WINDOW* win, char* str );
int32_t centerPos ( int32_t baseVal, int32_t size );

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

/* Misc for drawing ascii art */
void printArt ( WINDOW* obj, int32_t yPos, char* str[], int32_t strMax );

/* Functions used in setting up ncurses and errors */
int32_t initColor ( void );
void exitNc ( void );
void errMsg ( int32_t code, const char* format, ... );
void initNc ( void );

#endif /* END */
