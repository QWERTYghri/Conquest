/*
 * Country.h
 *
 * File describing the countries in the game.
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <stdint.h>


typedef struct
{
        struct War
        {
                uint32_t        deaths,
                                soldiers,
                                tanks,
                                planes,
                                conscriptMode,
                                skill,
                                manPower;
                
                /* Pedantic error rn */
                char*           warCountries[];
        } War;

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
                char*           tradeCountries;
        } Trade;
} Country;

#endif /* END */
