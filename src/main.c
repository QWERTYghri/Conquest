/*
 * main.c
 *
 * The main file for the game.
 *
 * @QWERTYghri
 */

/* libc */
#include <locale.h>


/* posix */
#define _POSIX_C_SOURCE 200809L

/* lib includes */
#include <ncurses.h>
#include <panel.h>


int main ( void )
{
	// placeholder for now
	initscr ();
	cbreak ();

	box ( stdscr, 0, 0 );
	refresh ();

	getch ();
	endwin ();

	return 0;
}

