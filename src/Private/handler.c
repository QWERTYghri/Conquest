/*
 *	Handler functions for the game menu
 *
 */

#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <time.h>

#include "../Public/decal.h"
#include "../Public/game.h"
#include "../Public/handler.h"
#include "../Public/util.h"

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
	delwin ( prompt );
	
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
	mvwprintw ( prompt, 0, xCenterStr ( prompt, title ) - 1, "┤%s├", title );
	
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
	int32_t retVal = 0;
	char buf[FNAME_BUF];
	char* opt[YES_OPT] =
	{
		"No",
		"Yes"
	};
	
	time_t timeUnix = time ( NULL );
	struct tm timeSet = *localtime ( &timeUnix );
	
	
	srand ( time ( NULL ) );
	snprintf ( buf,
	   	   FNAME_BUF,
		   DEFAULT_SAVE,
		   rand () % RAND_HIGH,
		   timeSet.tm_sec );
	
	promptMenu ( "save" );
	mvwaddstr ( prompt, ICON_Y_OFFSET, xCenterStr ( prompt, SAVE_PROMPT ), SAVE_PROMPT );
	wrefresh ( prompt );
	
	if ( ( retVal = menuOption ( prompt, ICON_Y_OFFSET + 2, opt, YES_OPT ) ) == 1 )
		saveGame ( curGame, buf );
	
	werase ( prompt );
	wrefresh ( prompt );
}

void
exitGame ( void )
{
	delwin ( prompt );
	errMsg ( EXIT_FAILURE, THANK_YOU );
}

