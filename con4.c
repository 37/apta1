/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "con4.h"

/**
 * @mainpage COSC1076 - Assignment 1 documentation.
 *
 * This is the main html documentation of assignment 1 for COSC1076 -
 * Advanced Programming Techniques for semester 2, 2015. You will find
 * here a description of the functions tha	 you need to implement for
 * your assignment.
 *
 * Please note that this should not be your first stop when starting
 * your assignment. Please read the assignment 1 specifications that
 * are available on blackboard before reading this documentation. The
 * purpose of this documentation is to clarify the actual individual
 * requirements.
 *
 * This site presents you with the documentation for each function
 * that you need to implement broken down by the file that they exist
 * in. Please go to the <b>Files</b> tab and click on the file you wish to
 * get more information about and then click on that file. An
 * explanation of each function implemented in that file will be
 * displayed.
 **/

/**
 * @file con4.c contains the main function which is the entry point into the
 * application and manages the main memory.
 **/

/**
 * the entry point into the game. You should display the main menu and
 * respond to user requests.
 *
 * The main menu should look like this:
 * Welcome to connect 4
 *  \n\--------------------
 * 1. Play Game
 * 2. Display High Scores
 * 3. Quit
 * Please enter your choice:
 *
 * This menu should also be redisplayed when the program returns from
 * running an option.
 **/
int main(void)
{
    /* the scoreboard for keeping track of winners */
    scoreboard scores;
    /* the two players and a pointer to who won the last game */
    struct player human_player, computer_player, *winner;
	char input[3];
	char *end;
	int iLength;
	int selection;
    /* with each of the comments below, insert the code that performs
     * this function
     */

    /* initialise the scoreboard */

	/*display menu and get menu choice until the user chooses to quit */


	printf("\n%s\n%s\n%s\n%s\n%s\n%s\n",
			"Welcome to Connect 4",
			"--------------------",
			"1. Play Game",
			"2. Display High Scores",
			"3. Quit",
			"Please enter your choice:");

	/* Get user selection & clear line*/
	fgets(input, 3 , stdin);

	/* Format and fix newline chars */
	iLength = strlen(input) - 1;
	if (input[iLength] == '\n'){
		input[iLength] = '\0';
	}

	/* Convert read input string to int */
	selection = (int) strtol(input, &end, 10);

	/* Log to console user selection */
	printf("You selected: %d\n", selection);

	/* Process selection and call appropriate methods */
	switch(selection){
		/* play a game option */
		case 1 :
			printf("\e[1;1H\e[2J");
			printf(" - %d | play game \n", selection);

			play_game(&human_player, &computer_player);

		    /* if there was not a draw, add player to the scoreboard in
		     * order by number of tokens in play
		     */

		    /* let the user know who won */

		    /* if there was a draw, alert the user to this fact */
			break;

		/* display the scoreboard option */
		case 2  :
		   /* code goes here */
		   break;

		/* quit the program option */
		case 3  :
		   /* code goes here */
		   break;

		default : /* Optional */
			/* default code here */
			printf("%s\n", "you a basic bitch");
			break;
	}

    return EXIT_SUCCESS;
}
