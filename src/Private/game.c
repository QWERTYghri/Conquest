/*
 * Country.h
 *
 * File describing the countries in the game and initializing
 * different objects.
 */
 
/* lib */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Local */
#include "../Public/decal.h"
#include "../Public/game.h"
#include "../Public/util.h"

/*
typedef struct
{
        struct General
        {
                uint32_t        money,
                                income,
                                expense,
                                stability,
                                polPower,
                                polIdeo,
                                taxIncome;
        } General;

        struct Trade
        {
                char*           tradeCountries[MAX_COUNTRY];
        	
        } Trade;

        struct War
        {
                uint32_t        deaths,
                                soldiers,
                                tanks,
                                planes,
                                conscriptMode,
                                skill,
                                manPower;
        } War;
} Country;
*/

Country*
initCountry ()
{
	Country* cntObj = calloc ( 1, sizeof ( Country ) );

	return cntObj;
}

GameState*
initGame ( char* playerName, int32_t difficulty )
{
	GameState* curGame = calloc ( 1, sizeof ( GameState ) );
	
	if ( playerName == NULL )
		errMsg ( EXIT_FAILURE, USERN_FAIL );
	
	snprintf ( curGame -> playerName, NAME_MAX, "%s", playerName );
	curGame -> difficulty = difficulty;
	
	/* zero out the countries flag */
	for ( int32_t i = 0; i < MAX_COUNTRY; i++ )
		curGame -> countries[i] = initCountry ();
	
	return curGame;
}


GameState* loadGame ( char* fileName )
{
	return NULL;
}
void saveGame ( GameState* obj )
{
	
}
