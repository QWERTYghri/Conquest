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
        s_oil     = 1000,
        s_iron    = 500,
        s_conGood = 250,
        
        /* Initial rate increase */
        s_oilInc  = 10,
        s_ironInc = 5,
        s_conInc  = 10,

        /* Stat init */
        s_money           = 1000000,
        s_stable          = 50,
        s_population      = 5000000,
        s_cities          = 5,
        s_motivation      = 15, /* Percent of of the population */
        
        /* war */
        s_Personnel       = 100000,
        s_unitPower      = 50, /* Percentage damage */ 
        s_units           = 5, /* Units are divided into 5 and splitted into all cities */
};

typedef struct {
        uint32_t x, y;
} BorderPoint;

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
