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
 * args: (G:Game*)
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

/*
 * Test method for the game's end
 * args: (G:Game*)
 * result:
 *      returns 1 if the game is finished, so if there's a check somewhere
 *      and none of the checked player's possible moves can uncheck his king.
 *      return 0 if a move can uncheck the king
 */
int Finished(Game* G);

#endif