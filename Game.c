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
    printf("PawnMove -> ");
    if(G->turn == BLACK){
        printf("shall be black's turn\n");
    } else if(G->turn == WHITE){
        printf("shall be white's turn\n");
    }

    if(T->color == BLACK){
        printf("token is black\n");
    } else if(T->color == WHITE){
        printf("token is white\n");
    }
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        printf("1st case -> 0\n");
        return 0;
    } else {
        switch (T->color){
            case WHITE :
                printf("WHITE -> ");
                if(T->slot->coord->y != S->coord->y){
                    printf("y are : %d | %d \n",T->slot->coord->y, S->coord->y);
                    printf("x are : %d | %d \n", T->slot->coord->x, S->coord->x);
                    if(T->slot->coord->x != S->coord->x + 1){
                        if(IsDirectDiagSlot(T->slot,S) && S->occupied==1){
                            printf("1st case -> 1\n");
                            return 1;
                        }
                    } else {
                        printf("2nd case -> 0\n");
                        return 0;
                    }
                } else {
                    int i = T->slot->coord->y;
                    if(T->slot->coord->x < S->coord->x){
                        for(int j=T->slot->coord->x+1; j<=S->coord->x; j++){
                            if(G->board->grid[j][i]->occupied==1){
                                printf("3rd case -> 0\n");
                                return 0;
                            }
                        }
                        printf("2nd case -> 1\n");
                        return 1;
                    } else {
                        printf("4th case -> 0\n");
                        return 0;
                    }
                }
            case BLACK :
                printf("BLACK -> ");
                if(T->slot->coord->y != S->coord->y){
                    printf("y are : %d | %d \n",T->slot->coord->y, S->coord->y);
                    printf("x are : %d | %d \n", T->slot->coord->x, S->coord->x);
                    if(T->slot->coord->x == S->coord->x + 1){
                        printf("checking diag\n");
                        if(IsDirectDiagSlot(T->slot,S) && S->occupied==1){
                            printf("1st case -> 1\n");
                            return 1;
                        }
                    } else {
                        printf("2nd case -> 0\n");
                        return 0;
                    }
                } else {
                    int i = T->slot->coord->y;
                    if(T->slot->coord->x > S->coord->x){
                        for(int j=S->coord->x; j<T->slot->coord->x; j++){
                            printf("checking slot [%d][%d]\n", i, j);
                            if(G->board->grid[j][i]->occupied==1){
                                printf("3rd case -> 0\n");
                                return 0;
                            }
                        }
                        printf("2nd case -> 1\n");
                        return 1;
                    } else {
                        printf("4th case -> 0\n");
                        return 0;
                    }
                }
            default:
                printf("null\n");
                return 0;
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
                        Token* T_ = FindToken(G->board,G->board->grid[i][j]);
                        if(EqSlotP(G->board->grid[i][j],S) && T_->color!=G->turn){
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
                return 1;
            }
        } else if(T->slot->coord->y==S->coord->y){
            int j = T->slot->coord->y;
            if(S->coord->x > T->slot->coord->x){
                for(int i=T->slot->coord->x+1; i<=S->coord->x; i++){
                    if(G->board->grid[i][j]->occupied==1){
                        Token* T_ = FindToken(G->board,G->board->grid[i][j]);
                        if(EqSlotP(G->board->grid[i][j],S) && T_->color!=G->turn){
                            return 1;
                        } else {
                            return 0;
                        }
                    }
                }
            } else {
                for(int i=S->coord->x; i<T->slot->coord->x; i++){
                    if(G->board->grid[i][j]->occupied==1){
                        Token* T_ = FindToken(G->board,G->board->grid[i][j]);
                        if(EqSlotP(G->board->grid[i][j],S) && T_->color!=G->turn){
                            return 1;
                    } else {
                            return 0;
                        }
                    }
                }
            }
        } else {
            return 0;
        }
    }
}

int KnightMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        return 0;
    } else {
        int X = T->slot->coord->x;
        int Y = T->slot->coord->y;
        //if knight is on (0,0) he can move on 
            // (1,2) (2,1) -down right corner-
            // (-1,2) (-2,1) -down left corner'
            // (1,-2) (2,-1) -up right corner-
            // (-1,-2) (-2,-1) -up left corner-
        //gonna test each corner at time 
        if( (S->coord->x+1==X && S->coord->y+2==Y) || (S->coord->x+2==X && S->coord->y+1==Y) ){
            //we are in the down right corner 
            return 1;
        } else if( (S->coord->x-1==X && S->coord->y+2==Y) || (S->coord->x-2==X && S->coord->y+1==Y) ){
            //we are in the down left corner
            return 1;
        } else if( (S->coord->x+1==X && S->coord->y-2==Y) || (S->coord->x+2==X && S->coord->y-1==Y) ){
            //we are in the up right corner
            return 1;
        } else if( (S->coord->x-1==X && S->coord->y-2==Y) || (S->coord->x-2==X && S->coord->y-1==Y) ){
            //we are in the up left corner
            return 1;
        } else {
            return 0;
        }
    }
}

int BishopMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        return 0;
    } else {
        int X = T->slot->coord->x;
        int Y = T->slot->coord->y;
        //we wanna go in one of the fourth diagonal
            //up right -> x+ & y-
            //up left -> x- & y-
            //down right -> x+ & y+
            //down left -> x- & y+
        if(S->coord->x > X && S->coord->y < Y){
            //up right direction
            int dist = Y - S->coord->y;
            for(int n=1; n<=dist; n++){
                if(G->board->grid[X+n][Y-n]->occupied){
                    return EqSlotP(G->board->grid[X+n][Y-n],S);
                }
            }
            return 1;
        } else if(S->coord->x < X && S->coord->y < Y){
            //up left direction
            int dist = Y - S->coord->y;
            for(int n=1; n<=dist; n++){
                if(G->board->grid[X-n][Y-n]->occupied){
                    return EqSlotP(G->board->grid[X-n][Y-n],S);
                }
            }
            return 1;
        } else if(S->coord->x > X && S->coord->y > Y){
            //down right direction
            int dist = S->coord->y - Y;
            for(int n=1; n<=dist; n++){
                if(G->board->grid[X+n][Y+n]->occupied){
                    return EqSlotP(G->board->grid[X+n][Y+n],S);
                }
            }
            return 1;
        } else if(S->coord->x < X && S->coord->y > Y){
            //down left direction
            int dist = S->coord->y - Y;
            for(int n=1; n<=dist; n++){
                if(G->board->grid[X-n][Y+n]->occupied){
                    return EqSlotP(G->board->grid[X-n][Y+n],S);
                }
            }
            return 1;
        } else {
            //nothing valid...
            return 0;
        }
    }
}

int QueenMove(Game* G, Token* T, Slot* S){
    if(RookMove(G, T, S)){
        return 1;
    } else if(BishopMove(G, T, S)) {
        return 1;
    }else {
        return 0;
    }
}

int KingMove(Game* G, Token* T, Slot* S){
    if(G->turn != T->color || EqSlotP(T->slot,S) ){
        return 0;
    }
    int X = T->slot->coord->x;
    int Y = T->slot->coord->y;
    //8 possible moves for (0,0)
        //(0,1) (1,0) (0,-1) (-1,0)
        //(1,-1) (-1,1) (1,1) (-1,-1)
    if(S->coord->x==X+1 && S->coord->y==Y){
        return 1;
    } else if(S->coord->x==X-1 && S->coord->y==Y){
        return 1;
    } else if(S->coord->x==X && S->coord->y==Y+1){
    return 1;
    } else if(S->coord->x==X && S->coord->y==Y-1){
        return 1;
    } else if(S->coord->x==X+1 && S->coord->y==Y+1){
        return 1;
    } else if(S->coord->x==X-1 && S->coord->y==Y-1){
        return 1;
    } else if(S->coord->x==X+1 && S->coord->y==Y-1){
        return 1;
    } else if(S->coord->x==X-1 && S->coord->y==Y+1){
        return 1;
    } else {
        //nothing valid
        return 0;
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

int PinCheck(Game* G, Slot* S1, Slot* S2){
    //here we can just test if when the piece moves, the king is checked...
    return 0;
}

int Unchecked(Game* G, Slot* S1, Slot* S2){
    return 0;
}

int IsChecked(Game* G){
    printf("entering IsChecked\n");
    return 0;
}

void ChangeTurn(Game* G){
    switch (G->turn){
        case BLACK :
            G->turn = WHITE;
            return;
        case WHITE :
            G->turn = BLACK;
            return;
    }
}