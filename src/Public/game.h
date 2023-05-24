/*
 * Country.h
 *
 * File describing the countries in the game.
 */

#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#include "./decal.h"

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
                char*           tradeCountries;
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
	Country* countries[MAX_COUNTRY];
} GameStat;

#endif /* END */
