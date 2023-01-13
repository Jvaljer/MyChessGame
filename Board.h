#ifndef BOARD_H
#define BOARD_H

#include "Token.h"
/*
 * Board is simply defined by a grid of Slots (pointer on Slots)
 *  and the Hands (pointer on Tokens)
 */
typedef struct Board{
    Slot* grid [8][8];
    Token* hands[2][16];
}Board;

/*
 * Board Constructor 
 * args : None 
 * result : a 8x8 board with 'grid' full of Slots 
 *      which has the same coords as there position
 *         + all pieces present in 'hands'
 */
Board* new_Board();

/*
 * Getter for a precise slot 
 * args : (B:Board*) (C:Coord*)
 * result : the grid's slot which coordinates are C
 */
Slot* GetSlot(Board* B, Coord* C);

/*
 * Getter for a precise token 
 * args : (B:Board*) (S:Slot*)
 * result : the hand's token which is on S
 */
Token* GetToken(Board* B, Slot* S);

/*
 * Board Printing 
 * args : (B:Board*)
 * result : brand new board -> 
 *        a    b    c    d    e    f    g    h
 *      -----------------------------------------
 *      | bR | bK | bB | bQ | BK | bB | bK | bR |  1
 *      -----------------------------------------  
 *      | bP | bP | bP | bP | bP | bP | bP | bP |  2
 *      ----------------------------------------- 
 *      |    |    |    |    |    |    |    |    |  3
 *      -----------------------------------------
 *      |    |    |    |    |    |    |    |    |  4
 *      -----------------------------------------  
 *      |    |    |    |    |    |    |    |    |  5
 *      -----------------------------------------
 *      |    |    |    |    |    |    |    |    |  6
 *      -----------------------------------------
 *      | wP | wP | wP | wP | wP | wP | wP | wP |  7
 *      -----------------------------------------
 *      | wR | wK | wB | wQ | WK | wB | wK | wR |  8
 *      -----------------------------------------
 * token's name & position are printed by recognizing where they are 
 *  not only print the previous grid...
 */
void PrintBoard(Board* B);

/*
 * Test Function for Board stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestBoard();
#endif