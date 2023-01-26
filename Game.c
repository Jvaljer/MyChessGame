#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

Game* new_Game(){
    Game* G_ = malloc(sizeof(Game));
    G_->board = new_Board();
    G_->turn = WHITE;
    G_->direction = new_Direction();
    return G_;
}

int PawnMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        return 0;
    } else {
        switch (T->color){
            case WHITE :
                if(T->slot->coord->y != S->coord->y){
                    if(T->slot->coord->x != S->coord->x + 1){
                        if(IsDirectDiagSlot(T->slot,S) && S->occupied==1){
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    int i = T->slot->coord->y;
                    if(T->slot->coord->x < S->coord->x){
                        for(int j=T->slot->coord->x+1; j<=S->coord->x; j++){
                            if(G->board->grid[i][j]->occupied==1){
                                return 0;
                            }
                        }
                        return 1;
                    } else {
                        return 0;
                    }
                }
            case BLACK :
                if(T->slot->coord->y != S->coord->y){
                    if(T->slot->coord->x != S->coord->x + 1){
                        if(IsDirectDiagSlot(T->slot,S) && S->occupied==1){
                            return 1;
                        }
                    } else {
                        return 0;
                    }
                } else {
                    int i = T->slot->coord->y;
                    if(T->slot->coord->x > S->coord->x){
                        for(int j=S->coord->x; j<T->slot->coord->x; j++){
                            if(G->board->grid[i][j]->occupied==1){
                                return 0;
                            }
                        }
                        return 1;
                    } else {
                        return 0;
                    }
                }
        }
    }
}

int RookMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        return 0;
    } else {
        if(T->slot->coord->x==S->coord->x){
            int i = T->slot->coord->x;
            if(S->coord->y > T->slot->coord->y){
                for(int j=T->slot->coord->y+1; j<=S->coord->y; j++){
                    if(G->board->grid[i][j]->occupied==1){
                        return 0;
                    }
                }
                return 1;
            } else {
                for(int j=S->coord->y; j<T->slot->coord->y; j++){
                    if(G->board->grid[i][j]->occupied==1){
                        return 0;
                    }
                }
                return 1;
            }
        } else if(T->slot->coord->y==S->coord->y){
            int j = T->slot->coord->y;
            if(S->coord->x > T->slot->coord->x){
                for(int i=T->slot->coord->x+1; i<=S->coord->x; i++){
                    if(G->board->grid[i][j]->occupied==1){
                        return 0;
                    }
                }
                return 1;
            } else {
                for(int i=S->coord->x; i<T->slot->coord->x; i++){
                    if(G->board->grid[i][j]->occupied==1){
                        return 0;
                    }
                }
                return 1;
            }
        } else {
            return 0;
        }
    }
}

int KnightMove(Game* G, Token* T, Slot* S){
    return 0;
}

int BishopMove(Game* G, Token* T, Slot* S){
    return 0;
}

int QueenMove(Game* G, Token* T, Slot* S){
    return 0;
}

int KingMove(Game* G, Token* T, Slot* S){
    return 0;
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

void PlayTurn(Game* G, char* inputA, char* inputB){
    return;
}

void ChangeTurn(Game* G){
    switch (G->turn){
        case BLACK :
            printf("Actually black's turn\n");
            G->turn = WHITE;
        case WHITE :
            printf("Actually white's turn\n");
            G->turn = BLACK;
    }
}

void TestGame(){
    printf("#- GAME TEST START\n");
    printf("Testing Cosntructor : \n");
    Game* G0 = new_Game();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            assert( EqCoord(G0->board->grid[i][j]->coord,new_Coord(i,j)) );
            if(i<2)
                assert( G0->board->hands[i][j] != NULL );
        }
    }
    PrintBoard(G0->board);
    printf("    check\n");

    printf("Testing Pawn Moves : \n");
    assert( PawnMove(G0,FindToken(G0->board,G0->board->grid[1][3]), G0->board->grid[3][3])==1 );    
    assert( PawnMove(G0,FindToken(G0->board,G0->board->grid[6][6]), G0->board->grid[1][5])==0 );
    MoveToken( G0->board,  FindToken(G0->board,G0->board->grid[6][2])->slot, G0->board->grid[2][4] );
    assert( PawnMove(G0, FindToken(G0->board, G0->board->grid[1][3]), G0->board->grid[2][4])==1 );
    printf("    check\n");

    ChangeTurn(G0);
    assert(G0->turn == BLACK);

    printf("Testing Rook Moves : \n");
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[6][7])->slot, G0->board->grid[5][0] );
    assert( RookMove(G0, FindToken(G0->board, G0->board->grid[7][7]), G0->board->grid[3][7])==1 );
    assert( RookMove(G0, FindToken(G0->board, G0->board->grid[0][7]), G0->board->grid[4][7])==0 );
    PrintBoard(G0->board);
    printf("    check\n");

    printf("Testing Knight Moves : \n");
    printf(" not implemented yet\n ");

    printf("Testing Bishop Moves : \n");
    printf(" not implemented yet\n ");

    printf("Testing Queen Moves : \n");
    printf(" not implemented yet\n ");

    printf("Testing King Moves : \n");
    printf(" not implemented yet\n ");

    printf(" -> GAME TEST END -# \n\n");
}