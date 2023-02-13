/*
 * Main Program File
 *
 * @QWERTYghri
*/

/* libc */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>
#include <string.h>
#include <signal.h>

/* Posix */
#include <unistd.h>
#include <getopt.h>

/* Curses */
#include <ncurses.h>

/* Macros */
#define GAME_WINDOW_X ( COLS - 10 )
#define GAME_WINDOW_Y ( LINES - 10 )

#define HELP ("About:\n\tConquest is a Grand Strategy type game in which you invade other countries and increase your economy through trade and more.\n\n")
#define VERS ("Version: 1.0R\n\n")

/* Size index */
#define TITLE_ARR       ( 9 )
#define EXPLOSION_ARR   ( 11 )
#define OPT_ARR         ( 3 )

#define TITLE_OFFSET     ( 6 )
#define MENU_OFFSET      ( TITLE_OFFSET + 10 )
#define EXPLOSION_OFFSET ( 15 )

/* Enums */
enum { 
        CursInvis,
        CursVis
};

enum {
        ColorBlack,
        ColorBlue,
        ColorGrey,
        
        ColorTextRed,
        ColorSelect,
};

/* Global Vars */
WINDOW* fWin, *bWin;

/* Functions */
static int32_t
initColor ( void )
{
        if ( has_colors () )
                start_color ();
        else
                return -1;

        init_pair ( ColorBlack, COLOR_BLACK, COLOR_BLACK );
        init_pair ( ColorBlue, COLOR_BLUE, COLOR_BLUE );
        init_pair ( ColorGrey, COLOR_BLACK, COLOR_WHITE );
        init_pair ( ColorTextRed, COLOR_RED, COLOR_BLACK );

        init_pair ( ColorSelect, COLOR_PAIR ( ColorGrey ), COLOR_RED );
       
        return 0;
}

static void
exitNc ( void )
{
        erase ();
        refresh ();
        endwin ();
}

static void
errMsg ( const char* msg, int32_t code )
{
        exitNc ();
        fprintf ( stderr, "%s",  msg );
        exit ( code );
}

static void
initNc ( void )
{
        initscr ();
        //raw ();
        noecho ();
        nonl ();
        keypad ( stdscr, TRUE );
        curs_set ( CursInvis );

        if ( initColor () != 0 )
                errMsg ( "Error: Colors are not supported by terminal\nExitting...\n", EXIT_FAILURE );
}

static void
readInput ( int argc, char** argv )
{
        int32_t optIndex        = 0;
        int32_t retVal          = 0;
        static struct option lngOpt[] =
        {
                { "help", no_argument, 0, 'h' },
                { "version", no_argument, 0, 'v' },
                { 0, 0, 0, 0 }
        };

        while ( ( retVal = getopt_long ( argc, argv, "hv", lngOpt, &optIndex ) ) != EOF )
        {
                if ( retVal == - 1 )
                        break;

                switch ( retVal )
                {
                        case 'h':
                                errMsg ( HELP, EXIT_SUCCESS );
                                break;
                        case 'v':
                                errMsg ( VERS, EXIT_SUCCESS );
                                break;
                        default:
                                errMsg ( "Unknown argument\n\nArgs:\n\t--help\n\t--Version\n", EXIT_SUCCESS );
                                break;
                }
        }

        if ( optind < argc )
                errMsg ( "No argument or unformatted argument\n\n", EXIT_SUCCESS );
}

static void
baseSetUp ( void )
{
        fWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, ( LINES - GAME_WINDOW_Y ) / 2, ( COLS - GAME_WINDOW_X ) / 2 );
        bWin = newwin ( GAME_WINDOW_Y, GAME_WINDOW_X, ( LINES - GAME_WINDOW_Y ) / 2 + 1, ( COLS - GAME_WINDOW_X ) / 2 + 1 );

        wbkgd ( bWin, COLOR_PAIR ( ColorBlack ) );
        wbkgd ( fWin, COLOR_PAIR ( ColorGrey ) );
        bkgd ( COLOR_PAIR ( ColorBlue ) );

        box ( fWin, 0, 0 );

        refresh ();
        wrefresh ( bWin );
        wrefresh ( fWin );
}

static int32_t
centerStr ( WINDOW* win, char* str, int32_t offset )
{
        int32_t yLen, xLen;

        getmaxyx ( win, yLen, xLen );

        return ( xLen / 2 ) - ( strlen ( str ) / 2 ) - offset;
}

static void
titleMenu ( void )
{
        char* title[TITLE_ARR] =
        { 
		"---------------------------------------------------------------",
		" ____                                  _  ",
		"/ ___|___  _ __   __ _ _   _  ___  ___| |_",
		"| |   / _ \\| '_ \\ / _` | | | |/ _ \\/ __| __|",
		"| |__| (_) | | | | (_| | |_| |  __/\\__ \\ |_ ",
         	" \\____\\___/|_| |_|\\__, |\\__,_|\\___||___/\\__|",
        	"                     |_|                    ",
        	"Made by QWERTYghri",
        	"---------------------------------------------------------------"
        };

        char* explosion[EXPLOSION_ARR] =
        {
		"     _.-^^---....,,--       ",
		" _--                  --_   ",
		"<                        >) ",
		"|                         | ",
		" \\._                   _./  ",
		"    ```--. . , ; .--'''     ",
	        "	  | |   |            ",
		"       .-=||  | |=-.        ",
		"       `-=#$%&%$#=-'        ",
		"	  | ;  :|            ",
		"  _____.,-#%&$@%#&#~,._____ "
        };

        char* optNames[OPT_ARR] =
        {
                "Play Game",
                "End Game",
                "test"
        };

        int32_t winY,
                winX;

        int32_t xInc    = 0,
                inVal,
                optInc  = 0;

        getmaxyx ( fWin, winY, winX );

        for ( int32_t i = 0; i < TITLE_ARR; i++ ) {
                mvwprintw ( fWin,  TITLE_OFFSET + xInc, centerStr ( stdscr, title[i], TITLE_OFFSET ), "%s", title[i] );
                xInc++;
        }
        xInc = 0;
        for ( int32_t i = 0; i < EXPLOSION_ARR; i++ ) {
                mvwprintw ( fWin, EXPLOSION_OFFSET + xInc, centerStr ( stdscr, explosion[i], EXPLOSION_OFFSET ), "%s", explosion[i] );
                xInc++;
        }

        wrefresh ( fWin );

        /* Menu Stuff */
        for ( int32_t i = 0; i < OPT_ARR; i++ ) {
                if ( i == optInc )
                        attron ( COLOR_PAIR ( ColorSelect ) );

                mvwprintw ( fWin, MENU_OFFSET + i, centerStr ( stdscr, optNames[i], TITLE_OFFSET ), "%s", optNames[i] );
                attroff ( COLOR_PAIR ( ColorSelect ) );
        }
        wrefresh ( fWin );

        while ( ( inVal = getch () ) != EOF )
        {

                for ( int32_t i = 0; i < OPT_ARR; i++ ) {
                        if ( i == optInc )
                                attron ( COLOR_PAIR ( ColorSelect ) );

                        mvwprintw ( fWin, MENU_OFFSET + i, centerStr ( stdscr, optNames[i], TITLE_OFFSET ), "%s", optNames[i] );
                        attroff ( COLOR_PAIR ( ColorSelect ) );
                }

                wrefresh ( fWin );

                switch ( inVal )
                {
                        case KEY_UP:
                                optInc--;
                                break;
                        case KEY_DOWN:
                                optInc++;
                                break;
                }

                if ( optInc < 0 )
                        optInc = 1;
                else if ( optInc > 2 )
                        optInc = 2;
        }

}

static void
game ( void )
{
        baseSetUp ();
        titleMenu ();
        

        getch ();

        delwin ( fWin );
        delwin ( bWin );
}

int
main ( int argc, char** argv )
{
        setlocale ( LC_ALL, "" );
        initNc ();
        
        readInput ( argc, argv );
        game ();

        exitNc ();

        return 0;
}
