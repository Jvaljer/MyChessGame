#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Token.h"

Id make_Id(Role R, Color C){
    switch (C){
        case NONE :
            return ER;
        case BLACK :
            switch (R){
                case PAWN :
                    return bP;
                case ROOK :
                    return bR;
                case KNIGHT :
                    return bK;
                case BISHOP :
                    return bB;
                case QUEEN :
                    return bQ;
                case KING :
                    return BK;
            }
        case WHITE :
            switch (R){
                case PAWN :
                    return wP;
                case ROOK :
                    return wR;
                case KNIGHT :
                    return wK;
                case BISHOP :
                    return wB;
                case QUEEN :
                    return wQ;
                case KING :
                    return WK;
            }
    }
}

Token* new_Token(Slot* S, Role R, Color C){
    Token* T = malloc(sizeof(Token));
    T->role = R;
    T->color = C;
    T->slot = S;
    T->id = make_Id(T->role, T->color);
    T->onBoard = 0;
    return T;
}

int EqToken(Token* T1, Token* T2){
    return ( (EqSlot(T1->slot,T2->slot)) && (T1->role==T2->role) && (T1->color==T2->color) );
}

int EqTokenP(Token* T1, Token* T2){
    return (T1==T2);
}

void TestToken(){
    printf("#- TOKEN TEST START\n");
    printf("Testing Constructor :");
    Coord* C0 = new_Coord(1,1);
    Slot* S0 = new_Slot(C0);
    Token* T0 = new_Token(S0,KING,WHITE);
    assert( EqSlot(T0->slot,S0) );
    assert( EqSlotP(T0->slot,S0) );
    assert( T0->role == KING );
    assert( T0->color == WHITE);
    assert( T0->id == WK );
    printf(" check\n");

    printf(" -> TOKEN TEST END -# \n\n");
}