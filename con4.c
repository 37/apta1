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
