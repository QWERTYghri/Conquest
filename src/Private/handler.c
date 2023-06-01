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

GameState* curGame;
WINDOW* optPlay, *gameWin;
WINDOW* fWin, *bWin;

WINDOW* prompt;

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
promptMenu ( char* title )
{
	prompt = newwin ( 
			PROMPT_WINDOW_Y,
			PROMPT_WINDOW_X,
			centerPos ( LINES, PROMPT_WINDOW_Y ),
			centerPos ( COLS, PROMPT_WINDOW_X ) + 10
			);
	
	wbkgd ( prompt, COLOR_PAIR ( ColorGrey ) );
	box ( prompt, 0, 0 );
	mvwprintw ( prompt, 0, xCenterStr ( prompt, title ) - 1, "||%s||", title );
	
	wrefresh ( prompt );
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
	promptMenu ( "save" );
}

void
exitGame ( void )
{
	delwin ( prompt );
	errMsg ( EXIT_FAILURE, THANK_YOU );
}

