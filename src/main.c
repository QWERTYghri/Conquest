/*
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
#define INIVS 0
#define CLEAR 0

/* Window size */
#define MLINES   ( LINES - 4 )
#define MCOLUMN  ( COLS - 2 )

/* Array sizes */
#define MOPTMAX	 ( 3 )
#define GMOPTMAX ( 10 )
/*=========Types and stuff=========*/

enum Color
{
         GREY = 1,
         BLUE = 2,
         BLACK = 3
};

/*=========Functions=========*/

/* mainMenu Functions */
void mainMenu ( void )
{
        const char* optList[MOPTMAX] =
                 {
                         "Play",
                         "Help",
                         "Exit"
                 };
        
        WINDOW* fWin, *bWin;
        HOIWIN* set;
        
        /* Init WINDOW */
        fWin = newwin ( MLINES, MCOLUMN, ( LINES - MLINES ) / 2, ( COLS - MCOLUMN ) / 2 );
        bWin = newwin ( MLINES, MCOLUMN, ( LINES - MLINES + 1 ) / 2, ( COLS - MCOLUMN + 1 ) / 2 );

        set = initHoiWin ( fWin, bWin, GREY, BLACK, 1 );

        drawHoiWin ( set );
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
	setlocale ( LC_ALL, "" );
        
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

