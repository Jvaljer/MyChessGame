#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

Game* new_Game(){
    Game* G_ = malloc(sizeof(Game));
    G_->board = new_Board();
    G_->turn = WHITE;
    return G_;
}

int PawnMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :
                if(T->slot->coord->x==S->coord-1 || T->slot->coord->y==S->coord-2){
                    return 1;
                } else {
                    return 0;
                }
            case BLACK : 
                if(T->slot->coord->x==S->coord+1 || T->slot->coord->y==S->coord+2){
                    return 1;
                } else {
                    return 0;
                }
        }
    }
}

int RookMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :
                
            case BLACK :

        }
    }
}

int KnightMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :

            case BLACK :
            
        }
    }
}

int BishopMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :

            case BLACK :
            
        }
    }
}

int QueenMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :

            case BLACK :
            
        }
    }
}

int KingMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || S->occupied==1){
        return 0;
    } else {
        switch (T->color){
            case WHITE :

            case BLACK :
            
        }
    }
}

int CanMove(Game* G, Slot* S1, Slot* S2){
    Token* T_ = FindToken(G->board, S1);
    switch (T_->id){
        case ER : 
            return 0;
        case wP :
            return PawnMove(G,T_,S2);
        case wR :
            return RookMove(G,T_,S2);
        case wK :
            return KnightMove(G,T_,S2);
        case wB :
            return BishopMove(G,T_,S2);
        case wQ :
            return QueenMove(G,T_,S2);
        case WK :
            return KingMove(G,T_,S2);
        case bP :
            return PawnMove(G,T_,S2);
        case bR :
            return RookMove(G,T_,S2);
        case bK :
            return KnightMove(G,T_,S2);
        case bB :
            return BishopMove(G,T_,S2);
        case bQ :
            return QueenMove(G,T_,S2);
        case BK :
            return KingMove(G,T_,S2);
    }
}

void TestGame(){
    printf("#- GAME TEST START\n");
    printf("Testing Cosntructor : ");
    Game* G0 = new_Game();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            assert( EqCoord(G0->board->grid[i][j]->coord,new_Coord(i,j)) );
            if(i<2)
                assert( G0->board->hands[i][j] != NULL );
        }
    }
    PrintBoard(G0->board);
    printf(" check\n");
    printf(" -> GAME TEST END -# \n\n");
}