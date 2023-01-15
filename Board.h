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

Token* FindToken(Board* B, Slot* S);

/*
 * Printing function for a Board 
 *  args : (B:Board*)
 *  result :
 *      for an initialized board ->
 *     a    b    c    d    e    f    g    h
 *   -----------------------------------------
 *   | wR | wK | wB | wQ | WK | wB | wK | wR | 1
 *   -----------------------------------------
 *   | wP | wP | wP | wP | wP | wP | wP | wP | 2
 *   -----------------------------------------
 *   |    |    |    |    |    |    |    |    | 3
 *   -----------------------------------------
 *   |    |    |    |    |    |    |    |    | 4
 *   -----------------------------------------
 *   |    |    |    |    |    |    |    |    | 5
 *   -----------------------------------------
 *   |    |    |    |    |    |    |    |    | 6
 *   -----------------------------------------
 *   | bP | bP | bP | bP | bP | bP | bP | bP | 7
 *   -----------------------------------------
 *   | bR | bK | bB | bQ | BK | bB | bK | bR | 8
 *   -----------------------------------------
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