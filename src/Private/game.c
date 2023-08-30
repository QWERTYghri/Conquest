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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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


typedef struct
{
	char playerName[NAME_MAX];
	Country countries[MAX_COUNTRY];
	
	int32_t difficulty,
		score;
} GameState;
*/

/* init a country */
Country*
initCountry ()
{
	Country* cntObj = calloc ( 1, sizeof ( Country ) );

	return cntObj;
}

/* init a gameState object */
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
		curGame -> countries[i] = *initCountry ();
	
	curGame -> countries[1].General.money = 54;
	
	return curGame;
}

/* check if a file does exist and if the filename matches */
int32_t
fileCheck ( char* fileName )
{
	int32_t retAcc = access ( fileName, F_OK );
	char* ext;
	
	if ( retAcc == -1 )
		return retAcc;
	
	/*
		Pain, using file extension
		if no file extension then return -1
		else then compare to the default file extension
	*/
	if ( !( ext = strrchr ( fileName, '.' ) ) )
		return -1;
	else
	{
		if ( strncmp ( ext, SAVE_EXT, CMP_BUF ) != 0 )
			return -1;
	}
	return 0;
}

/* load a file to the game as curGame */
GameState*
loadGame ( char* fileName )
{
	FILE* fObj;
	GameState* curGame = calloc ( 1, sizeof ( GameState ) );
	
	if ( ( fObj = fopen ( fileName, "r+" ) ) == NULL )
		errMsg ( EXIT_FAILURE, SAVE_FAIL );
	
	// Deserialization
	fread ( &(*curGame), sizeof ( *curGame ), 1, fObj );
	fclose ( fObj );
	return curGame;
}

/* Save the current game state to a file in .conquest */
void
saveGame ( GameState* obj, char* saveName )
{
	FILE *fObj;
	char fName[FNAME_BUF];
	char saveDir[NAME_MAX];
	struct stat stObj = { 0 };
	
	// makes path /home/[USER]/.conquest
	snprintf ( saveDir, DIR_MAX, SAVE_DIR, obj -> playerName );
	
	// Make directory if not already existing
	if ( stat ( saveDir, &stObj ) == -1 )
	{
		if ( mkdir ( saveDir, 0700 ) != 0 ) {
			errMsg ( EXIT_FAILURE, SAVE_FAIL );
		}
	}
	
	// Make a file name and extension
	snprintf ( fName, FNAME_BUF, "%s/%s.scon", saveDir, saveName );
	
	// Make that save file
	if ( ( fObj = fopen ( fName, "w+" ) ) == NULL )
		errMsg ( EXIT_FAILURE, SAVE_FAIL );
	
	// Serialization
	fwrite ( &(*obj), sizeof ( *obj ), 1, fObj );
	fclose ( fObj );
	
}


void
editVal ( Country* obj, float modifier )
{
	
}

