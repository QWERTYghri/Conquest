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
	char* resource;
	char* recipient;
	int32_t amount;
} Trade;

typedef struct
{
	char* resourceType;
	uint32_t production;
} Factory;

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

        struct Economy
        {
                Trade* tradeList[MAX_TRADES];
                Factory* factoryList[MAX_TRADES];
                
                uint32_t	titanium,
                		oil,
                		electronics,
                		phosphate,
                		fertilizer,
                		steel,
                		copper,
                		gold,
                		aluminium,
                		motorParts,
                		planeParts;
        } Economy;

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

// Definitions for different  types.
enum {
	IDEO_NATIONALISM,
	IDEO_FACISM,
	
	IDEO_LIBERALISM,
	IDEO_DEMORACY,
	
	IDEO_SOCIALISM,
	IDEO_COMMUNISM,
	
	IDEO_NEUTRAL
};

// Increases manpower amount / lowers skills
enum {
	CON_VOLUNTEER,
	CON_DRAFT,
	CON_REQUIRED
};



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

void		editVal ( Country* obj, float modifier );

#endif /* END */
