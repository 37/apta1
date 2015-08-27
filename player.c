/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "player.h"

/**
 * @param human the human player to initialise
 **/
enum input_result get_human_player(struct player* human)
{

	char userName[(NAMELEN + 2)];
	int uLength;


	printf("%s\n", "What's yo name dawg?");

	fgets(userName, (NAMELEN + 2) , stdin);

	uLength = strlen(userName) - 1;
	if (userName[uLength] == '\n'){
		userName[uLength] = '\0';
	}
	printf("\e[1;1H\e[2J");
	printf("Thanks, %s.\n", userName);

	/* construct player */
	strcpy(human->name, userName);
	human->thiscolor = C_WHITE;
	human->counters = 0;
	human->type = HUMAN;



    return SUCCESS;
}

/**
 * @param computer the computer player to initialise
 **/
enum input_result get_computer_player(struct player * computer)
{
	char compName[NAMELEN] = "computer\o";
    /* initialise all variables that are part of the struct to sensible
     * values */
	computer->thiscolor = C_RED;
	strcpy(computer->name, compName);
	computer->counters = 0;
	computer->type = COMPUTER;

    return FAILURE;
}

/**
 * In this requirement, you need to handle the taking of a turn - either
 * of a human or a computer player.
 *
 * For the human player, you will need to allow the user to enter the
 * column they wish to place a token in. You will need to validate what
 * the user enters, then place a token correctly in that column so that
 * it occupies the cell closest to the bottom of the board array for that
 * column.
 *
 * For the computer player, you will need to randomly generate a column
 * number to place a token in and if that column is full, generate a
 * different column number until a column number with some free space has
 * been found.
 *
 * @param current the current player
 * @param board the game board that we will attempt to insert a token into
 * @return enum @ref input_result indicating the state of user input (in
 * case this run involved user input
 **/
enum input_result take_turn(struct player * current,
        enum cell_contents board[BOARDHEIGHT][BOARDWIDTH])
{
	if (current->type == HUMAN){
		char input[3];
		char *end;
		int selection;
		int iLength;
		int count = 0;
		int col;

		printf("%s\n", "It's your turn! \nPick a column from 1 to 7:");

		/* Get user selection & clear line*/
		fgets(input, 3 , stdin);

		/* Format and fix newline chars */
		iLength = strlen(input) - 1;
		if (input[iLength] == '\n'){
			input[iLength] = '\0';
		}

		/* Convert read input string to int */
		selection = (int) strtol(input, &end, 10);

		/* Log to console user selection and change board */

		printf("You selected: %d\n", selection);

		for (col = 0; col < 6; col++){
			if (board[col][selection] = C_EMPTY) {
				count += 1;
			}
		}

		if (count) {
			printf("%s\n", "This is a valid move");
			printf("Column %d\n", selection);
			printf("Row %d\n", count);
			printf("this color:  %d\n", current->thiscolor);

			board[count][selection] = current->thiscolor;
		} else {
			printf("%s\n", "This isnt a valid move! Try again m8..");
			/* use this entire thing in do while. */
		}


	} else if (current->type == COMPUTER){
		/* generate random number.*/
		printf("%s\n", "It's the computers turn.");
	}

	/*  call gamestate. */

	/*
     * Default return value - delete this comment and the return
     * value and replace it with appropriate logic to handle either
     * a human or computer turn including handling any input errors.
     */
    return FAILURE;
}
