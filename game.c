/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : Keaton Okkonen
* Student Number   : s3432651
* Course Code      : COSC1076
* Program Code     : BP094
* Start up code provided by Paul Miller
***********************************************************************/
#include "game.h"

struct player * play_game(struct player * human ,
        struct player* computer)
{
    /* declaration that allocates the board for the game */
    enum cell_contents board[BOARDHEIGHT][BOARDWIDTH];
    /* If turn is set to 0 white's turn, else 1 for red. */
    int turn = 0;
    enum game_state game = G_NO_WINNER;
	/* calls human player creation */
    get_human_player(human);
	get_computer_player(computer);

    /*set computer color based on random human color */
    if (human->thiscolor == C_RED){
		computer->thiscolor = C_WHITE;
	} else if (human->thiscolor == C_WHITE) {
		computer->thiscolor = C_RED;
	}

    /*tells the user what color they are*/
    if (human->thiscolor == C_RED) {
        printf("%s\n", "You the WHITE player");
    } else {
        printf("%s\n", "You are the RED player");
    }

	/* initialise board and display board  -- see board.c for method */
	printf("%s\n", "Let's play some connect 4");

	initialise_board(board);
	display_board(board);

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

    switch(game){
		/* play a game option */
		case G_RED :
            printf("---------------------------------------");
            display_board(board);
            printf("\e[1;1H\e[2J%s\n%s\n%s\n",
                "---------------------------------------",
                "EVENT LOG:",
                "Red wins! Game over."
            );
            /* Print board and gamestate to user, return victor details */
            if (human->thiscolor == C_RED){
                return human;
            } else {
                return computer;
            }

            break;

		case G_WHITE :
            printf("---------------------------------------");
            display_board(board);
            printf("\e[1;1H\e[2J%s\n%s\n%s\n",
                "---------------------------------------",
                "EVENT LOG:",
                "White wins! Game over."
            );
            /* Print board and gamestate to user, return victor details */
            if (human->thiscolor == C_WHITE){
                return human;
            } else {
                return computer;
            }
            break;

		case G_DRAW :
            printf("---------------------------------------");
            display_board(board);
            printf("\e[1;1H\e[2J%s\n%s\n%s\n",
                "---------------------------------------",
                "EVENT LOG:",
                "It was a draw! Game over."
            );
            return NULL;
            break;

        default :
            printf("Oops, we had a bit of an issue with that. Returning home.");
            return NULL;
            break;
    }

    return NULL;
}

enum game_state test_for_winner(
        enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
    int emptycount = 0;

    int row;
    int col;

    enum cell_contents colhistory;
    int colcount;

    enum cell_contents rowhistory;
    int rowcount;

    /* Iterate through horizontal ROW cell values, recording the counters */
    for (row = 0; row < BOARDHEIGHT; row++) {
        /* New row, reset counters */
        rowcount = 0;
        rowhistory = 0;
        for (col = 0; ((col < BOARDWIDTH)); col++) {
            if (board[row][col] == C_RED) {
                /*current cell is red */
                /* reset white counter */
                if (rowhistory == C_WHITE){
                    rowcount = 0;
                } else if (rowhistory == C_RED){
                    rowcount += 1;
                    if (rowcount == 3) {
                        /* 4 red found in a row */
                        return G_RED;
                    }
                }
            } else if (board[row][col] == C_WHITE) {
                /* current cell is white */
                /* reset red counter */
                if (rowhistory == C_RED){
                    rowcount = 0;
                } else if (rowhistory == C_WHITE){
                    rowcount += 1;
                    if (rowcount == 3) {
                        /* 4 white found in a row */
                        return G_WHITE;
                    }
                }
            } else if (board[row][col] == C_EMPTY){
                rowcount = 0;
                emptycount += 1;
            }
            rowhistory = board[row][col];
        }

    }

    /* Iterate through vertical COLUMN cell values, recording the counters */

    for (col = 0; col < BOARDWIDTH; col++) {
        /* New row, reset counters */
        colcount = 0;
        colhistory = 0;

        for (row = 0; row < BOARDHEIGHT; row++) {

            if (board[row][col] == C_RED) {
                /*current cell is red */
                /* reset white counter */
                if (colhistory == C_WHITE){
                    colcount = 0;
                } else if (colhistory == C_RED){
                    colcount += 1;
                    if (colcount == 3) {
                        /* 4 red found in a row */
                        return G_RED;
                    }
                }
            } else if (board[row][col] == C_WHITE) {
                /* current cell is white */
                /* reset red counter */
                if (colhistory == C_RED){
                    colcount = 0;
                } else if (colhistory == C_WHITE){
                    colcount += 1;
                    if (colcount == 3) {
                        /* 4 white found in a row */
                        return G_WHITE;
                    }
                }
            } else if (board[row][col] == C_EMPTY) {
                colcount = 0;
                emptycount += 1;
            }
            colhistory = board[row][col];
        }
    }

    if (emptycount == 0) {
        return G_DRAW;
    } else {
        return G_NO_WINNER;
    }

}


static void swap_players(struct player ** current, struct player ** other)
{
    /* implement a classic swap using a temporary pointer */
}
