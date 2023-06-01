/*
 *	Handler functions for the game menu
 *
 */

#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>

#include "../Public/decal.h"
#include "../Public/util.h"
#include "../Public/handler.h"

GameState* curGame = NULL;
WINDOW* optPlay = NULL, *gameWin = NULL;
WINDOW* fWin = NULL, *bWin = NULL;

void
clearWins ( void )
{
	delwin ( optPlay );
	delwin ( gameWin );
	delwin ( fWin );
	delwin ( bWin );
	
	free ( curGame );
}


void
country ( void )
{
	
}
void
diplomacy ( void )
{

}

void
economy ( void )
{

}
void
technology ( void )
{

}

void
military ( void )
{

}
void
viewCountries ( void )
{

}
void
status ( void )
{

}

void
save ( void )
{

}
void
exitGame ( void )
{
	errMsg ( EXIT_FAILURE, THANK_YOU );
}

