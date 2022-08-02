/*
 * main.c
 *
 * The main file for the game.
 *
 * @QWERTYghri
 */

/*=========INCLUDES=========*/

/* libc */
#include <locale.h>
#include <stdint.h>
#include <stdlib.h>

/* posix */
#define _POSIX_C_SOURCE 200809L

#include <pthreads.h>

/* ncurses*/
#include <ncurses.h>
#include <panel.h>

/* local */
#include "./src/public/resource.h"
#include "./src/public/handler.h"


/*=========Definitions=========*/

/* Cursor options | curs_set () */
#define INIVS ( ( int32_t ) 0 )
#define CLEAR ( ( int32_t ) 1 )

/*=========Types and stuff=========*/
typedef enum Color
{
        GREY = 1,
        BLUE = 2
} Color;

/*=========Functions=========*/

/* mainMenu Functions */
void mainMenu ( void )
{
       const char* optList[3] =
                {
                        "Play",
                        "Help",
                        "Exit"
                };

       WINDOW* fWin, bWin;
}

/* gamePlay function */

/* Function close for endwin given an error */
void exitHandle ( const char* msg, int32_t exFlag )
{
        perror ( msg );
        endwin ();
        exit ( exFlag );
}

/* init color ids */
int initColors ( void )
{
        if ( !has_colors () )
                return -1;
        
        start_color ();

        init_pair ( GREY, COLOR_WHITE, COLOR_BLACK );
        init_pair ( BLUE, COLOR_BLUE, COLOR_BLUE );

        return 0;
}

/*=========MAIN=========*/

int main ( void )
{
	setlocale ( LC_ALL, "c" );
        
        /* Ncurses init */
        initscr ();
        noecho ();
        raw ();
        curs_set ( INVIS );

        initColors ();
        
        getch ();
        endwin ();

	return 0;
}

