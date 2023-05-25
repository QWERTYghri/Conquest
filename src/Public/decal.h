/*
 * Houses definitions for buffer sizes or just important numbers
 *
 */

#ifndef DECAL_H
#define DECAL_H

typedef int _;
/* Macros */


/**********************************************************************/


/* WINDOW BUFFER SIZES */
#define GAME_WINDOW_Y	( LINES - 10 )
#define GAME_WINDOW_X	( COLS - 10 )

#define ABOUT_WINDOW_Y	( GAME_WINDOW_Y - 30 )
#define ABOUT_WINDOW_X	( GAME_WINDOW_X - 30 )

#define DIFF_WINDOW_Y	( GAME_WINDOW_Y - 15 )
#define DIFF_WINDOW_X	( GAME_WINDOW_X - 120 )

#define OPTION_X	( 30 )
#define POS_PLAY	( 5 )

/**********************************************************************/

/* Y offsets: Used to offset a position to an object */
#define TITLE_Y_OFFSET  ( 6 )
#define MENU_Y_OFFSET   ( TITLE_Y_OFFSET + 10 )
#define NUKE_Y_OFFSET   ( 25 )
#define TANK_Y_OFFSET	( 2 )
#define STAR_Y_OFFSET	( 2 )

#define GAME_Y_OFFSET	( 15 )

/**********************************************************************/


/* Definitions for sizes */
#define TITLE_ARR       ( 9 )
#define NUKE_ARR        ( 11 )
#define TANK_ARR	( 7 )
#define STAR_ARR	( 9 )

#define LVL_MAX		( 4 )
#define OPT_ARR         ( 3 )

#define MIN_LINES	( 50 )
#define MIN_COLS	( 190 )

#define MAX_COUNTRY	( 5 )
#define NAME_MAX	( 50 )

#define GAME_OPT	( 8 )
/**********************************************************************/

/* Text Info and Sets */
#define HELP            ( "About:\n\tConquest is a Grand Strategy type game in which you invade other countries and increase your economy through trade and more. btw please have a big screen. \n\n" )
#define VERS            ( "Version: 1.0R\n\n" )

#define UKN_ARG		( "Error: Unknown argument\n\nArgs:\n\t--help\n\t--version\n" )
#define NO_ARG		( "Error: No argument or unformatted argument\n" )
#define ERR_COLOR	( "Error: Colors are not supported by terminal\nExitting...\n" )
#define WIN_SIZE	( "Error: LINES and COLS are less than the requirement ( 62, 239 ). Can't use other screens because of the ASCII art. Try to lower terminal font\n" )
#define THANK_YOU	( "Thanks for playing, I need to stop doing projects like these and start doing like ones that I can actually get something in return.\n\n * Visit my Roblox, \"mrgameybean17\"\n" )
#define MENU_FAIL	( "Possible failure in menuHandler function\n" )

#define ABOUTSTR	( "Conquest:\n\tThis is a grand strategy type of game based on the game Hearts of Iron. It's focused on making it towards world domination by invading\n\tother countries. " \
			  "You can control where to place troops in the area and also work on trade between other countries. Use the cursor\n\tto click on troops to move them to a point in the map " \
			  "Use the arrow keys and the enter key to navigate the screen." )

#endif /* End file */
