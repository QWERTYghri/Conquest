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
#include "./src/public/util.h"

/*=========Definitions=========*/

/* Cursor options | curs_set () */
#define INIVS ( ( int32_t ) 0 )
#define CLEAR ( ( int32_t ) 1 )

/* Window size */
#define MLINES   ( ( int32_t ) LINES - 4 );
#define MCOLUMN  ( ( int32_t ) COLS - 2 );

/*=========Types and stuff=========*/
typedef enum Color
{
         GREY = 1,
         BLUE = 2,
         BLACK = 3
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
                 clear
        
        WINDOW* fWin, *bWin;
        
        /* Init WINDOW */
        fWin = newwin ( MLINES, MCOLUMN, ( LINES - MLINES ) / 2, ( COLS - MCOLUMN ) / 2 );

        HOIWIN* wMain   = initHoiWin ( fWin, bWin, GREY, BLACK, 1 );
        uint32_t ch     = 0;
        uint32_t inCh   = 0;

        while ( ch = getch () )
        {
                switch ( ch )
                {
                        case KEY_UP:
                                inCh++;
                                break;
                        case KEY_DOWN:
                                inCh--;
                                break;
                }
                
                /* Movement set */
                if ( inCh > 2 )
                        inCh = 0;
                else if ( inCh < 0 )
                        inCh = 2;
        }

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
        init_pair ( BLACK, COLOR_BLACK, COLOR_BLACK );
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
        keypad ( stdscr, true );
        curs_set ( INVIS );

        if ( initColors () )
                exitHandle ();

        mainMenu ();
        
        getch ();
        endwin ();

	return 0;
}

