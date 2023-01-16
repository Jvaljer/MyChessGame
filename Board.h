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
 * Finding a Token on Board 
 * args : (B:Board*) (S:Slot*)
 * result : returns the Token that's on B located on S
 */
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
 * Moving Token Function
 * args : (B:Board*) (S1:Slot*) (S2:Slot*)
 * result : changes Token on S1 to now positionned as on S2, 
 * (don't care if possible or not, will be tested 
 *  later on in 'Game')
 */
void MoveToken(Board* B, Slot* S1, Slot* S2);

/*
 * Taking Token Function
 * args : (B:Board*) (S:Slot*)
 * result : removes the Token on S from the board (giving him
 *  a [-1][-1] slot as position)
 */
void TakeToken(Board* B, Slot* S);

/*
 * Test Function for Board stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestBoard();

#endif