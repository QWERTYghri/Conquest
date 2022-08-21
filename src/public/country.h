/*
 * Country.h to store structs and other functions
 * to set up resources
 *
 * @QWERTYghri
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdint.h>

typedef struct Country
{
	uint32_t Ideology;
	
	typedef struct Resources
	{
		int32_t Oil,
			Iron,
			ConGoods;
	} Resources;
	
	typedef struct Stat
	{
		int32_t Money,
			Stability,
			Population,
			Cities,
			Motivation,
			PolPower;
	} Stat;
	
	typedef struct War
	{
		int32_t milPersonnel,
			unitPower,
			units;
	} War;
} Country;


#endif
