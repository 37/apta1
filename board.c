/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "board.h"
#include "player.h"

/**
 * @file board.c contains implementations of functions related to the game
 * board.
 **/

/**
 * @param board the board to reset the contents of
 **/
void initialise_board(enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	/* initialise row & column counters */
	int row, col;

	/* Create initial board state */
	for (row = 0; row < BOARDHEIGHT; row++) {
		for (col = 0; col < BOARDWIDTH; col++){
			board[row][col] = C_EMPTY;
		}
	}

}

/**
 * In this requirement you are required to display the game board.
 * The game board should be displayed as shown on the first page of the
 * assignment specification.
 * @param board the board to display
 **/
void display_board(enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	/* initialise row & column counters */
	int row, col;

	/* print board headers */
	printf("%s\n\n%s\n%s\n",
		"This is the current state of the board:",
		" 1 | 2 | 3 | 4 | 5 | 6 | 7 |",
		"----------------------------"
	);

	/* print board cells */
	for (row = 0; row < BOARDHEIGHT; row++) {
		for (col = 0; col < MAXCOLUMN; col++){

			switch(board[row][col]) {
				/* determine index content for game board*/
				case C_EMPTY :
					printf("   |");
					break;

				case C_RED  :
				   printf(" %s |", RED_TOKEN);
				   break;

				case C_WHITE  :
				   printf(" %s |", WHITE_TOKEN);
				   break;
			}

			if (col == 6) {
				printf("\n");
			}

		}
		printf("----------------------------\n");
	}

	/* print board footer */

	printf("\n%s\n", "Please enter a column in which to drop a token:");

}
