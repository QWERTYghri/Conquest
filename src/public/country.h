/*
 * Country.h to store structs and other functions
 * to set up resources
 *
 * @QWERTYghri
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdint.h>

enum Satania {
        /* Start off goods */
        Oil     = 1000,
        Iron    = 500,
        ConGood = 250,
        
        /* Initial rate increase */
        OilInc  = 10,
        IronInc = 5,
        ConInc  = 10,

        /* Stat init */
        Money           = 1000000,
        Stable          = 50,
        Population      = 5000000,
        Cities          = 5,
        Motivation      = 15, /* Percent of of the population */
        
        /* war */
        Personnel       = 100000,
        Unit Power      = 50, /* Percentage damage */ 
        Units           = 5, /* Units are divided into 5 and splitted into all cities */
};

typedef struct BorderPoint {
        uint32_t x, y;
};

typedef struct Country
{
	uint32_t Ideology;
	
	struct Resources
	{
		int32_t Oil,
			Iron,
			ConGoods;
	} Res;
	
	struct Stat
	{
		int32_t Money,
			Stability,
			Population,
			Cities,
			Motivation,
			PolPower;
	} Stat;
	
	struct War
	{
		int32_t milPersonnel,
			unitPower,
			units;
	} War;
} Country; 

Country* cntryInit ( void );

#endif
