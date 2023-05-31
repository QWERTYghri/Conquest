/*
 * Country.h
 *
 * File describing the countries in the game and initializing
 * different objects.
 */

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#include "./decal.h"

/*
typedef struct
{

} factory;
*/
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
                char* test;
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

typedef struct
{
	char playerName[NAME_MAX];
	Country countries[MAX_COUNTRY];
	
	int32_t difficulty,
		score;
} GameState;

Country*	initCountry ();
GameState*	initGame ( char* playerName, int32_t difficulty );

/* Save/load functions */
int32_t		fileCheck ( char* fileName );

Country*	loadCountry ( FILE* fObj, Country* cntObj );
GameState*	loadGame ( char* fileName );

void		saveCountry ( FILE* fObj, Country* cntObj  );
void		saveGame ( GameState* obj, char* saveName );
#endif /* END */
