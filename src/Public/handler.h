/*
 *	Handler functions for the game menu
 *
 */
 
#ifndef HANDLER_H
#define HANDLER_H

#include "./decal.h"
#include "./game.h"

extern GameState* curGame;
extern WINDOW* optPlay, *gameWin;
extern WINDOW* fWin, *bWin;

void clearWins ( void );

void country ( void );
void diplomacy ( void );
void economy ( void );
void technology ( void );
void military ( void );
void viewCountries ( void );
void status ( void );

void save ( void );
void exitGame ( void );

#endif /* end */
