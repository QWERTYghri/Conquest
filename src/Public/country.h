/*
 * Country.h
 *
 * File describing the countries in the game.
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdint.h>

/* Represent current trade */
typedef struct
{
        
} Trade;

typedef struct
{
        typedef struct
        {
                char*           warCountries[];
                uint32_t        deaths,
                                soldiers,
                                tanks,
                                planes,
                                conscriptMode,
                                skill,
                                manPower;
        } War;

        typedef struct
        {
                uint32_t        money,
                                income,
                                expense,
                                stability,
                                polPower,
                                polIdeo,
                                taxIncome
        } General;

        typedef struct
        {
                char*           tradeCountries
        } Trade;
} Country;

#endif /* END */
