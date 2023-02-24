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

int IsStillChecked(Game* G, Slot* S1, Slot* S2){
    return 0;
}

int IsChecked(Game* G){
    Board* B_ = G->board;
    Color col = G->turn;
    Token* K_;
    if(col==WHITE){
        K_ = B_->hands[0][4];
    } else if(col==BLACK){
        K_ = B_->hands[1][4];
    } else {
        return 0;
    }

    //here we wanna check if from any token there's a check in the current board state
      //and if there's one, we check if the direction is matching its movement 

    Slot* S_ = K_->slot;
    int x_pos = S_->coord->x;
    int y_pos = S_->coord->y;
    //first we check for check from ROOK or QUEEN
    for(int i= 0; i<8-x_pos; i++){
        Slot* _S = B_->grid[x_pos+i][y_pos];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if(T_->color != K_->color){
                if(T_->role==ROOK || T_->role==QUEEN){
                    return 1;
                }
            }
        }
    }

    for(int i= 0; i<=x_pos; i++){
        Slot* _S = B_->grid[x_pos-i][y_pos];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if(T_->color != K_->color){
                if(T_->role==ROOK || T_->role==QUEEN){
                    return 1;
                }
            }
        }
    }

    for(int j=0; j<8-y_pos; j++){
        Slot* _S = B_->grid[x_pos][y_pos+j];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if(T_->color != K_->color){
                if(T_->role==ROOK || T_->role==QUEEN){
                    return 1;
                }
            }
        }
    }

    for(int j=0; j<=y_pos; j++){
        Slot* _S = B_->grid[x_pos][y_pos-j];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if(T_->color != K_->color){
                if(T_->role==ROOK || T_->role==QUEEN){
                    return 1;
                }
            }
        }
    }

    //checking check from BISHOP & QUEEN
    // wanna check up-left (-1,-1)

    int cpt = 0;
    Slot* _S;
    do {
        cpt++;
        _S = B_->grid[x_pos-cpt][y_pos-cpt];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if((T_->role == BISHOP || T_->role==QUEEN) && T_->color != col){
                return 1;
            } else if(T_->color == col){
                break;
            }
        }
    } while(IsInside(new_Coord(x_pos-cpt,y_pos-cpt)));

    //wanna check up-right (1,-1)
    do {
        cpt++;
        _S = B_->grid[x_pos+cpt][y_pos-cpt];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if((T_->role == BISHOP || T_->role==QUEEN) && T_->color != col){
                return 1;
            } else if(T_->color == col){
                break;
            }
        }
    } while(IsInside(new_Coord(x_pos+cpt,y_pos-cpt)));

    //wanna check down-left (-1,1)
    do {
        cpt++;
        _S = B_->grid[x_pos-cpt][y_pos+cpt];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if((T_->role == BISHOP || T_->role==QUEEN) && T_->color != col){
                return 1;
            } else if(T_->color == col){
                break;
            }
        }
    } while(IsInside(new_Coord(x_pos-cpt,y_pos+cpt)));

    //wanna check down-right (1,1)
    do {
        cpt++;
        _S = B_->grid[x_pos+cpt][y_pos+cpt];
        if(_S->occupied){
            Token* T_ = FindToken(B_,_S);
            if((T_->role == BISHOP || T_->role==QUEEN) && T_->color != col){
                return 1;
            } else if(T_->color == col){
                break;
            }
        }
    } while(IsInside(new_Coord(x_pos+cpt,y_pos+cpt)));

    //checking checks from PAWNS
    if(K_->color == WHITE){
        //then we wanna check on both directions (-1,1) (1,1)
        Slot* S = B_->grid[x_pos - 1][y_pos + 1];
        if(S->occupied){
            Token* T = FindToken(B_,S);
            if(T->color!=col && T->role==PAWN){
                return 1;
            }
        }

        S = B_->grid[x_pos + 1][y_pos + 1];
        if(S->occupied){
            Token* T = FindToken(B_,S);
            if(T->color!=col && T->role==PAWN){
                return 1;
            }
        }
    } else if(K_->color == BLACK){
        //then we wanna check on both directions (-1,-1) (1,-1)
        Slot* S = B_->grid[x_pos - 1][y_pos - 1];
        if(S->occupied){
            Token* T = FindToken(B_,S);
            if(T->color!=col && T->role==PAWN){
                return 1;
            }
        }

        S = B_->grid[x_pos + 1][y_pos - 1];
        if(S->occupied){
            Token* T = FindToken(B_,S);
            if(T->color!=col && T->role==PAWN){
                return 1;
            }
        }
    }

    //checking checks from KNIGHTS
    return 0;
}

int ValidMove(Game* G, Slot* S1, Slot* S2){
    //here we just wanna check if S2 isn't occupied by an ally token
    //later on we'll add the 'Pin' checker
    Token* T1 = FindToken(G->board,S1);
    printf("moving token is : %s\n", Id_to_visual(T1->id));
    Token* T2;
    if(S2->occupied){
        T2 = FindToken(G->board,S2);
        printf("on slot's token : %s\n", Id_to_visual(T2->id));
        if(T1->color == T2->color){
            printf("Cannot do this move, slot occupied by one token of yours\n");
            return 0;
        }
    }

    if(PinCheck(G,S1,S2)==1){
        printf("Cannot do this move, you're pinned\n");
        return 0;
    }

    if(Unchecked(G,S1,S2)){
        printf("Cannot do this move, your king is checked\n");
        return 0;
    }
    if(T1->color!=G->turn){
        printf("not your turn ! \n");
        return 0;
    }

    printf("checking on can move...\n");
    return CanMove(G,S1,S2);
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
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[7][7])->slot, G0->board->grid[3][7]);
    PrintBoard(G0->board);
    printf("    check\n");

    printf("Testing Knight Moves : \n");
    ChangeTurn(G0);
    assert(G0->turn == WHITE);

    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[0][1]), G0->board->grid[2][2])==1 );
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[0][1]), G0->board->grid[2][0])==1 );
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[0][1])->slot, G0->board->grid[2][2]);
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[2][2]), G0->board->grid[3][4])==1 );
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[2][2]), G0->board->grid[3][0])==1 );
    printf("    check\n ");

    printf("Testing Bishop Moves : \n");
    assert( BishopMove(G0, FindToken(G0->board, G0->board->grid[0][5]), G0->board->grid[3][2])==0 );
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[1][6])->slot, G0->board->grid[2][6]);
    assert( BishopMove(G0, FindToken(G0->board, G0->board->grid[0][5]), G0->board->grid[2][7])==1 );
    printf("    check\n ");

    printf("Testing Queen Moves : \n");
    printf("    must test\n ");

    printf("Testing King Moves : \n");
    printf("    must test\n ");

    printf(" -> GAME TEST END -# \n\n");
}