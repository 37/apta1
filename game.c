/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"

/**
 * @file game.c contains the functions that relate to the management of
 * the game.
 **/

/**
 * This requirement requires you to understand a little more about pointers.
 * We want you to understand that all pointers just point to another memory
 * address whether they are a single pointer, a pointer to a pointer, etc.
 *
 * In this example, we want you to swap the pointers for two players.
 * This will be called from \ref play_game with a call such as
 * swap(&current, &other) and at the end of this function, current and
 * other's pointers will be swapped.
 * For example, if current points to the human player and other points to
 * the computer player, at the end of this function, the player they point
 * to will have been swapped.
 *
 * @param current the current player who has just completed their turn
 * @param other the next player whose turn it will be
 **/
static void swap_players(struct player ** current, struct player ** other)
{
    /* implement a classic swap using a temporary pointer */
}

/**
 * This is the heart of the game.
 *
 * Firstly, you need to initialise the game by calling functions written
 * for requirement 3. The rest of this function is then managing the game
 * loop.
 *
 * Each player takes a turn to drop a token into a column on the game
 * board. The task that needs to be performed will be different depending
 * on whether this is a human or a computer player.
 *
 * Regardless of the player type, you will need to display the board as it
 * was before the player makes their move. If the current player is a
 * computer player, we just need to select a column at random and drop a
 * token into that column. If there is no room, try another column.
 *
 * If the current player is a human player, your program will need to ask
 * the user what column they wish to drop a token in. This input should be
 * validated to check that it is numeric and within the range of allowed
 * columns.
 *
 * Once a valid move has been entered, your program should update the
 * gameboard. It should then check if the game has been won lost or drawn
 * by calling and the change the current player.
 *
 * This function also checks if the game has been won, lost or drawn by
 * calling \ref test_for_winner(), and if the game is over, returns the
 * winner to main or NULL if the game was a draw.

 * @param human a pointer to details about the human player
 * @param computer a pointer to details about the computer player
 **/
struct player * play_game(struct player * human ,
        struct player* computer)
{
    /* declaration that allocates the board for the game */
    enum cell_contents board[BOARDHEIGHT][BOARDWIDTH];
    /* If turn is set to 0 white's turn, else 1 for red. */
    int turn = 0;
    int game;
	/* calls human player creation */
    get_human_player(human);
	get_computer_player(computer);

	/* initialise board and display board  -- see board.c for method */
	printf("%s\n", "Let's play some connect 4");

	initialise_board(board);
	display_board(board);
    printf("color white is: \x1b[1;37mO\x1b[1;0m");

    /* turn loop */
    do {
        if (turn == 0){ /* White turn */
            if (human->thiscolor == C_WHITE){
        		take_turn(human, board);
        	} else {
        		take_turn(computer, board);
        	}
            /* stap turns */
            turn = 1;
        } else if (turn == 1) { /* red turn */
            if (human->thiscolor == C_RED){
        		take_turn(human, board);
        	} else {
        		take_turn(computer, board);
        	}
            /* stap turns */
            turn = 0;
        }
        display_board(board);
        game = test_for_winner(board);

    } while (game == G_NO_WINNER);
    /* Result achieved, victory or draw */
    printf("%s\n", "Game over.");
    return NULL;
}

enum game_state test_for_winner(
        enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
    int emptycount = 0;
    int row;
    int col;

    int colhistory;
    int colcount;

    char rowhistory;
    int rowcount;

    /* Iterate through horizontal ROW cell values, recording the counters */
    for (row = 0; ((row < BOARDHEIGHT) && (rowcount < 4)); row++) {
        /* New row, reset counters */
        rowcount = 0;
        rowhistory = 0;
        for (col = 0; ((col < BOARDWIDTH) && (rowcount < 4)); col++) {

            if (board[row][col] == C_RED) {
                /*current cell is red */
                /* reset white counter */
                if (rowhistory == C_WHITE){
                    rowcount = 0;
                } else {
                    rowcount += 1;
                }
            } else if (board[row][col] == C_WHITE) {
                /* current cell is white */
                /* reset red counter */
                if (rowhistory == C_RED){
                    rowcount = 0;
                } else {
                    rowcount += 1;
                }
            } else if (board[row][col] == C_EMPTY){
                rowcount = 0;
                emptycount += 1;
            }
            rowhistory = board[row][col];
        }

        /* if horizontal victory */
        if (rowcount > 3) {
            if (rowhistory == C_RED) {
                return G_RED;
            } else if (rowhistory == C_WHITE) {
                return G_WHITE;
            }
        }
    }

    /* Iterate through vertical COLUMN cell values, recording the counters */

    for (col = 0; ((col < BOARDWIDTH) && (colcount < 4)); col++) {
        /* New row, reset counters */
        colcount = 0;
        colhistory = 0;

        for (row = 0; ((row < BOARDHEIGHT) && (colcount < 4)); row++) {

            if (board[row][col] == C_RED) {
                /*current cell is red */
                /* reset white counter */
                if (colhistory == C_WHITE){
                    colcount = 0;
                } else {
                    colcount += 1;
                }
            } else if (board[row][col] == C_WHITE) {
                /* current cell is white */
                /* reset red counter */
                if (colhistory == C_RED){
                    colcount = 0;
                } else {
                    colcount += 1;
                }
            } else if (board[row][col] == C_EMPTY) {
                colcount = 0;
                emptycount += 1;
            }
            colhistory = board[row][col];
        }

        /* if horizontal victory */
        if (colcount > 3) {
            if (colhistory == C_RED) {
                return G_RED;
            } else if (colhistory == C_WHITE) {
                return G_WHITE;
            }
        }
    }

    if (emptycount == 0) {
        return G_DRAW;
    } else {
        return G_NO_WINNER;
    }

}
