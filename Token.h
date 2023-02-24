#ifndef TOKEN_H
#define TOKEN_H

#include <wchar.h>
#include <locale.h>

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
    int onBoard;
}Token;

/*
 * Id maker 
 * args : (R:Role) (C:Color)
 * result : Id corresponding to R & C 
 */
Id make_Id(Role R, Color C);

/*
 * Id to Str
 * args : (id:Id)
 * result : returns the char value of 'id'
 */
char* Id_to_str(Id id);

/*
 * Id to unicode visual (wchar_t)
 * args : (id:Id)
 * result : returns the unicode character corresponding to the 
 *          given Id.
 */
char* Id_to_visual(Id id);

/*
 * Token Constructor
 * args : (S:Slot*) (R:Role) (C:Color)
 * result : returns a brand new token with the assigned Slot*
 *    Role & Color values.
 */
Token* new_Token(Slot* S, Role R, Color C);

/*
 * Equality for type Token
 * args : (T1:Token*) (T2:Token*)
 * result : 1 if T1.slot.coord & T2.slot.coord has the same values
 *         and T1.role = T2.role and T1.color = T2.color
 */
int EqToken(Token* T1, Token* T2);

/*
 * Equality for type Slot
 * args : (T1:Token**) (T2:Token**)
 * result : 1 if T1 & T2 are pointing at the same object
 */
int EqTokenP(Token* T1, Token* T2);

#endif