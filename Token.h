#ifndef TOKEN_H
#define TOKEN_H

#include "Slot.h"

/*
 * Role & Color type definition
 * Role defines the nature of the pawn (which will give use its abilities)
 * Color defines the player who owns the token
 */
typedef enum { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING }Role;
typedef enum { WHITE, BLACK, NONE }Color;

/*
 * Token is defined by a role, a color, and a Slot, 
 * (plus a statement which tells if it's on Board or not ?)
 */
typedef struct Token{
    Role role;
    Color color;
    Slot* slot;
    //int onBoard;
}Token;

/*
 * Token Constructor
 * args : (S:Slot*) (R:Role) (C:Color)
 * result : returns a brand new token with the assigned Slot*
 *    Role & Color values.
 */
Token* new_Token(Slot* S, Role R, Color C);

/*
 * Test Function for Token stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestToken();

#endif