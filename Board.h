#ifndef BOARD_H
#define BOARD_H

#include "Token.h"

/*
 * Board is simply defined by a grid of Slots (pointer on Slots)
 */
typedef struct Board{
    Slot* grid [8][8]; 
}Board;

/*
 * Board Constructor 
 * args : None 
 * result : a 8x8 board with grid full of Slots 
 *      which has the same coords as there position
 */
Board* new_Board();

/*
 * Getter for a precise slot 
 * args : (B:Board*) (C:Coord*)
 * result : the grid's slot which coordinates are C
 */
Slot* GetSlot(Board* B, Coord* C);

/*
 * Test Function for Board stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestBoard();
#endif