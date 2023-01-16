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
}Game;

/*
 * Game Constructor
 *  Creating a new Board only related to this new Game
 */
Game* new_Game();

/*
 * Test Moving for Tokens 
 * args : (G:Game*) (T:Token*) (S:Slot*)
 * result : 
 *      0 if T can't move on S (not right turn or not 
 *      a valid move)
 */
int PawnMove(Game* G, Token* T, Slot* S);
int RookMove(Game* G, Token* T, Slot* S);
int KnightMove(Game* G, Token* T, Slot* S);
int BishopMove(Game* G, Token* T, Slot* S);
int QueenMove(Game* G, Token* T, Slot* S);
int KingMove(Game* G, Token* T, Slot* S);

/*
 * Movement Test for a specific Token
 * args : (G:Game*) (S1:Slot*) (S2:Slot*)
 * result : return 1 if the token on S1 can move on S2 
 *  using the actual G's board
 */
int CanMove(Game* G, Slot* S1, Slot* S2);

/*
 * Test Function for Game stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestGame();

#endif