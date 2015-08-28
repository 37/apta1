/***********************************************************************
* COSC1076 - Advanced Programming Techniques
* Semester 2 2015 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Course Code      : EDIT HERE
* Program Code     : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/
#include "scoreboard.h"

void init_scoreboard(scoreboard board) {
    int index;

    /* these values are set to a default state, as type and color aren't important in the initial state
    * they are set as such below.. */
    for (index = 0; index < SCOREBOARDSIZE; index++) {
        strcpy(board[i].name, "");
        board[i].type = HUMAN;
        board[i].counters = 0;
        board[i].thiscolor = C_EMPTY;
    }

}

/** For this requirement, you will need to display the scores in the
 * order they are scored in the scoreboard array.
 *
 * The display should look as follows:
 * Player               |Score
 * ---------------------------------------------
 * Barney               |17
 * Magi                 |15
 * Red                  |10
 * Computer             |8
 * Computer             |7
 * Computer             |6
 * Paul                 |4
 * Fred                 |4
 * Muaddib              |4
 * Zafiqa               |4
 *
 * @param board the scoreboard to display
 **/
void display_scores(const scoreboard board) {
    /* display score code goes here */
    int count;
    printf("%s\n%s\n%s\n",
        "---------------------------------------------",
        "Player               |Score                  ",
        "---------------------------------------------"
    );

    for (count = 0; count < SCOREBOARDSIZE; count++) {
        /* prints the name and counters of the current element of the array*/
        printf("%-21s|%d\n",
            board[count].name,
            board[count].counters
        );
    }
    printf("%s\n", "---------------------------------------------");
}

 BOOLEAN add_to_scoreboard(scoreboard board, const score * sc) {
    /* placeholder return value - delete this and insert logic for
     * inserting in sorted order by number of counters in play at the
     * time the player won.  Remember that empty slots in the
     * scoreboard are signified by names which are equivalent to the
     * empty string.
     */

    int bottom;
    int top;

    score primary, secondary;
    /* loops through the board and compares the new score to the old scores,
     * starting from the bottom and iteratively moving scores up / down to adjust.
     */

    for (bottom = 0; bottom < SCOREBOARDSIZE; bottom++) {

         if (board[bottom].counters < sc->counters) {
            primary = board[bottom];
            board[bottom] = *sc;

            for (top = bottom + 1; top < SCOREBOARDSIZE; top++) {
                secondary = board[top];
                primary = secondary;
            }
            /* This score IS WORTHY of the board. */
        	return TRUE;
        }
    }

    /* Having checked if the new score is scoreboard worthy, this peasant score is disregarded.*/

    return FALSE;
}
