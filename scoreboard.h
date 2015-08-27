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
#include "bool.h"
#include <string.h>
#include <stdio.h>


/**
 * @file scoreboard.h contains data definitions for the scoreboard
 **/
#ifndef SCOREBOARD_H
#define SCOREBOARD_H
/**
 * the number of entries on the scoreboard
 **/
#define SCOREBOARDSIZE 10
/**
 * redefine an array of player structs to be a scoreboard type. 
 **/
typedef struct player scoreboard[SCOREBOARDSIZE];
/**
 * alias the player struct to also be a score as that is what it is for the 
 * scoreboard
 **/
typedef struct player score;
/**
 * initialises the scoreboard to be all empty cells
 **/
void init_scoreboard(scoreboard board);

/**
 * add a winner to the scoreboard. The scores should be sorted by
 * number of counters sorted from lowest to highest.
 **/
BOOLEAN add_to_scoreboard(scoreboard, const score*);
/**
 * display the scores in the scoreboard
 **/
void display_scores(const scoreboard board);
#endif
