/*
 * handler.h
 *
 * Header for handling menu options
 * @QWERTYghri
 */

#ifndef HANDLER_H
#define HANDLER_H

#include <ncurses.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* Defs */
#define MENU_MAX ( 3 )

/* Types */
typedef void (*pFunc ) ( void );

/* Function defs */

/* Menu */
void exitGame ( void );

/* Glob Vars */
pFunc menuJmpTab[1] =
{
        exitGame,
};

#endif /* END */
