#ifndef TEST_H
#define TEST_H

#include "Turn.h"

/*
 * Test Function for Coord stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestCoord();

/*
 * Test Function for Slot stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestSlot();

/*
 * Test Function for Token stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestToken();

/*
 * Test Function for Board stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestBoard();

/*
 * Test Function for Game stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestGame();

/*
 * Test function for the Playing stuff (part of game)
 * args: None
 * result: nothing if all assertion true
 *         error if one or more assertion false
 */
void TestTurn();

#endif