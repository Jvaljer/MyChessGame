#ifndef BOARD_H
#define BOARD_H

#include "Token.h"

/*
 * Board is defined by 2 lists of Slots & Tokens which 
 *  represents the physical board & all tokens placed on the board 
 */
typedef struct Board{
    Slot *grid[8][8];
    Token *hands[2][16];
}Board;

/*
 * Board Constructor
 *  Creatign the 2 lists 
 *      Slots has Coords of the same indexs
 */
Board* new_Board();

/*
 * Test Function for Board stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestBoard();

#endif