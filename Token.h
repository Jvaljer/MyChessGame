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
 * Id (Simple acces to Role & Color) is defined by
 * the color as first min letter, and role as second 
 * maj letter.
 */
typedef enum { bP, bR, bK, bB, bQ, BK,
               wP, wR, wK, wB, wQ, WK,
               ER }Id;

/*
 * Token is defined by a role, a color, a Slot, and an Id  
 * (plus a statement which tells if it's on Board or not ?)
 */
typedef struct Token{
    Role role;
    Color color;
    Slot* slot;
    Id id;
    //int onBoard;
}Token;

/*
 * Id maker 
 * args : (R:Role) (C:Color)
 * result : Id corresponding to R & C 
 */
Id make_Id(Role R, Color C);

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