/*
 * Houses definitions for buffer sizes or just important numbers
 *
 */

#ifndef DECAL_H
#define DECAL_H

#include <ncurses.h>

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
#define GETSTR_Y_OFFSET	( 17 )
/**********************************************************************/


/* Definitions for sizes */
#define TITLE_ARR       ( 9 )
#define NUKE_ARR        ( 11 )
#define TANK_ARR	( 7 )
#define STAR_ARR	( 9 )
#define FLOPPY_ARR	( 14 )

#define LVL_MAX		( 4 )
#define OPT_ARR         ( 4 )

#define MIN_LINES	( 50 )
#define MIN_COLS	( 190 )

#define MAX_COUNTRY	( 5 )
#define NAME_MAX	( 50 )
#define DIR_MAX		( 100 )

#define GAME_OPT	( 9 )
#define MAX_STRING	( 40 )
#define FNAME_BUF	( 100 )
#define CMP_BUF		( 25 )
/**********************************************************************/

/* Text Info and Sets */
#define HELP            ( "About:\n\tConquest is a Grand Strategy type game in which you invade other countries and increase your economy through trade and more. btw please have a big screen. \n\n" )
#define VERS            ( "Version: 1.0R\n\n" )

#define UKN_ARG		( "Error: Unknown argument\n\nArgs:\n\t--help\n\t--version\n" )
#define NO_ARG		( "Error: No argument or unformatted argument\n" )
#define ERR_COLOR	( "Error: Colors are not supported by terminal\nExitting...\n" )
#define WIN_SIZE	( "Error: LINES and COLS are less than the requirement ( 62, 239 ). Can't use other screens because of the ASCII art. Try to lower terminal font\n" )
#define USERN_FAIL	( "Error: Username could not be found\n" )
#define MENU_FAIL	( "Error: Possible failure in menuHandler function\n" )
#define INVALID_FILE	( "Error: Invalid file or file doesn't exist" )
#define SAVE_FAIL	( "Error: Failed to save or load file\n" )

#define ABOUTSTR	( "Conquest:\n\tThis is a grand strategy type of game based on the game Hearts of Iron. It's focused on making it towards world domination by invading\n\tother countries. " \
			  "You can control where to place troops in the area and also work on trade between other countries. Use the cursor\n\tto click on troops to move them to a point in the map " \
			  "Use the arrow keys, enter key, and E key to navigate the screen." )
			  
#define THANK_YOU	( "Thanks for playing, I need to stop doing projects like these and start doing like ones that I can actually get something in return.\n\n * Visit my Roblox, "\
			  "\"mrgameybean17\"\n\n\nAlso I'm just realizing I forgot to credit the art in here, but eh it doesn't matter, I think...\n" )

#define SAVE_DIR	( "/home/%s/.conquest" )

#define SAVE_EXT	( ".scon" )
#define EXIT_MENU	( "EXIT" )

/**********************************************************************/

/* Other */
#define EXIT_RET	( 2 )

/* Some characters */
#define ESC		( 27 )
#define ENTER	( 13 )
#endif /* End file */
