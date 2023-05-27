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
	Country* cntObj = calloc ( 1, sizeof ( GameStat ) );

	return cntObj;
}

GameStat*
initGame ( char* playerName, int32_t difficulty )
{
	GameStat* curGame = calloc ( 1, sizeof ( GameStat ) );
	
	if ( playerName == NULL )
		errMsg ( EXIT_FAILURE, "Username could not be found" );
	
	snprintf ( curGame -> playerName, NAME_MAX, "%s", playerName );
	curGame -> difficulty = difficulty;
	
	/* zero out the countries flag */
	for ( int32_t i = 0; i < MAX_COUNTRY; i++ )
		curGame -> countries[i] = initCountry ();
	
	return curGame;
}
