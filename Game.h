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
 * valid move testing method  
 * args: (G:Game*) (S1:Slot*) (S2:Slot*)
 * result: 
 *      returns 1 if the given move from S1 to S2 is valid 
 *      durign the current G game (slot is occupied by ally 
 *      token, move respects described possible slots ...)
 */
int ValidMove(Game* G, Slot* S1, Slot* S2);

/*
 * Turn behaviour method
 * args: None
 * result: 
 *      dictates how a turn must be, so calls for the wanted methods
 *      at the right time, in the good order :
 *         first the player must enter his inputs
 *         then we wanna analyze them and get the coords 
 *           he was meaning to play with
 *         after that we make the wanted moves if possible,
 *         and finally 
 */
void Turn();

/*
 * changing player's turn 
 * args : (G:Game*)
 * result : switchs G->turn to WHITE if BLACK & to BLACK if WHITE
 */
void ChangeTurn(Game* G);

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
void TestPlaying();

#endif