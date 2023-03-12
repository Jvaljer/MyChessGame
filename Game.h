#ifndef GAME_H
#define GAME_H

#include "Board.h"

/*
 * Game is simply defined by a Board on which we'll apply
 * many statements and modification controllled to make the 
 * Game's behaviour rightly.
 */
typedef struct Game{
    Board* board;
    Color turn;
    Direction* direction;
}Game;

/*
 * Game Constructor
 *  Creating a new Board only related to this new Game
 */
Game* new_Game();

/*
 * Test Moving for ALL Tokens 
 * args : (G:Game*) (T:Token*) (S:Slot*)
 * result : 
 *      0 if T can't move on S (not right turn or not 
 *      a valid move)
 */

/*  on .. if there's nothing on it
        on .T if there's a token on it
    ----------------
    |    | .. |    |
    -----------------
    | .T | .. | .T |
    -----------------
    |    | P_ |    |
    ----------------
    */
int PawnMove(Game* G, Token* T, Slot* S);

/*  in both x & y direction as far as 
        it can until there's a token on it
    ---------------------
    |    | .. |    |    |
    ---------------------
    |    | .. |    |    |
    ---------------------
    | .. | R_ | .. | .T |
    ---------------------
    */
int RookMove(Game* G, Token* T, Slot* S);

/*    on .. whatever there's on the board.
    --------------------------
    |    | .. |    | .. |    |
    --------------------------
    | .. |    |    |    | .. |
    --------------------------
    |    |    | K_ |    |    |
    --------------------------
    | .. |    |    |    | .. |
    --------------------------
    |    | .. |    | .. |    |
    --------------------------
    */
int KnightMove(Game* G, Token* T, Slot* S);

/*  in any diagonal until there's a token on the way
    --------------------------
    | .. |    |    |    |    |
    --------------------------
    |    | .. |    | .T |    |
    --------------------------
    |    |    | B_ |    |    |
    --------------------------
    |    | .. |    | .. |    |
    --------------------------
    | .. |    |    |    | .T |
    --------------------------
    */
int BishopMove(Game* G, Token* T, Slot* S);

/*    as a combination of a Rook & a Bishop
        on any line/column or diagonal until there's a 
        token on the slot.
    --------------------------
    | .. |    | .. |    |    |
    --------------------------
    |    | .. | .. | .T |    |
    --------------------------
    | .T | .. | Q_ | .. | .. |
    --------------------------
    |    | .. | .T | .. |    |
    --------------------------
    | .. |    | .. |    | .T |
    --------------------------
    */
int QueenMove(Game* G, Token* T, Slot* S);

/*    in any direction but only on a distance of 
        one slot
    --------------------------
    |    |    |    |    |    |
    --------------------------
    |    | .. | .. | .. |    |
    --------------------------
    |    | .. | K_ | .. |    |
    --------------------------
    |    | .. | .. | .. |    |
    --------------------------
    |    |    |    |    |    |
    --------------------------
    */
int KingMove(Game* G, Token* T, Slot* S);

/*
 * Movement Test for a specific Token
 * args : (G:Game*) (S1:Slot*) (S2:Slot*)
 * result : return 1 if the token on S1 can move on S2 
 *  using the actual G's board
 */
int CanMove(Game* G, Slot* S1, Slot* S2);

/*
 * Pin Checking method
 * args: (G:Game*) (S:Slot*) 
 * result: 
 *      1 if the S1's token isn't pinned on the G game
 *      0 if it is.
 */
int PinCheck(Game* G, Slot* S1, Slot* S2);

/*
 * UnCheck test method
 * args: (G:Game*) (S1:Slot*) (S2:Slot*)
 * result:
 *      returns 1 if the move S1->S2 is unchecking the player's king. 
 *      returns 0 if not.
 */
int Unchecked(Game* G, Slot* S1, Slot* S2);

/*
 * Check test method
 * args: (G:Game*)
 * result:
 *      returns 1 if the actual player's king is checked by anyway on 
 *      the board. And 0 if not.
 */
int IsChecked(Game* G);

/*
 * valid move testing method  
 * args: (G:Game*) (S1:Slot*) (S2:Slot*)
 * result: 
 *      returns 1 if the given move from S1 to S2 is valid 
 *      durign the current G game (slot is occupied by ally 
 *      token, move respects described possible slots ...)
 */
int ValidMove(Game* G, Slot* S1, Slot* S2);

/*
 * changing player's turn 
 * args : (G:Game*)
 * result : switchs G->turn to WHITE if BLACK & to BLACK if WHITE
 */
void ChangeTurn(Game* G);

/*
 * finished game function
 * args: (G:Game*)
 * result:
 *      1 if none of the current player's move can uncheck the king
 *      0 if not
 */
int Finished(Game* G);

#endif