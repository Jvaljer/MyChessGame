#ifndef TURN_H
#define TURN_H

#include "Game.h"

/*
 * input checking method
 * args: (input:char)
 * result: 
 *      1 if the input is well as 'letter + digit' 
 *      0 if not.
 */
int ValidInput(char input[2]);

/*
 * getter for coordinates from a certain input
 * args: (input: char[2])
 * result: 
 *      returns the corresponding coordinates associated to the given input 
 *      (letter-digit) -> (column-line) -> allows to access the corresponding slot
   (letter-digit) -> (column-line) -> allows to access the corresponding slot
 */
Coord* GetCoordFromInput(char input[2]);

/*
 * Turn behaviour method
 * args: (g:Game*)
 * result: 
 *      dictates how a turn must be, so calls for the wanted methods
 *      at the right time, in the good order :
 *         first the player must enter his inputs
 *         then we wanna analyze them and get the coords 
 *           he was meaning to play with
 *         after that we make the wanted moves if possible,
 *         and finally 
 */
void Turn(Game* G);

int Finished(Game* G);

/*
 * Test function for the Playing stuff (part of game)
 * args: None
 * result: nothing if all assertion true
 *         error if one or more assertion false
 */
void TestTurn();

#endif