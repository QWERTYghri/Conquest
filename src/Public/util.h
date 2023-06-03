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
int32_t xCenterStrBuf ( WINDOW* win, int64_t buffer );
int32_t centerPos ( int64_t baseVal, int64_t size );

/* Used in menuhandler to switch between highlighting different choices */
void printMenu ( WINDOW* win,
                int32_t y,
                char* optName[],
                int32_t optLen,
                int32_t optIndex );

int32_t menuOption ( WINDOW* obj,
		     int32_t yPos,
		     char* optName[],
		     int64_t maxName );

int32_t getStr ( WINDOW* obj, int32_t posY, int32_t posX, char buf[], int64_t len );

/* Misc for drawing stuff art */
void printArt ( WINDOW* obj, int32_t yPos, char* str[], int64_t strMax );
void windowFmt ( WINDOW* obj );
void windowPrint ( WINDOW* obj, int32_t artOffset, char* art[], int64_t len );

/* Functions used in setting up ncurses and errors */
int32_t initColor ( void );
void exitNc ( void );
void errMsg ( int32_t code, const char* format, ... );
void initNc ( void );

#endif /* END */
