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

/*
Order:
	"Pasternak"
	"Atifa"
	"Oceania"
	"Kubo"
	"Zanton"
*/

typedef struct
{
	char playerName[NAME_MAX];
	int32_t playerCountry;
	
	Country countries[MAX_COUNTRY];
	
	int32_t difficulty,
		score;
} GameState;

Country*	initCountry ();
GameState*	initGame ( char* playerName, int32_t difficulty );

/* Save/load functions */
int32_t		fileCheck ( char* fileName ); //Check if a filename is valid to save

GameState*	loadGame ( char* fileName );
void		saveGame ( GameState* obj, char* saveName );
#endif /* END */
