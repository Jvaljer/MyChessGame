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
                            if(G->board->grid[j][i]->occupied==1){
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
                    if(T->slot->coord->x == S->coord->x + 1){
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
                            if(G->board->grid[j][i]->occupied==1){
                                return 0;
                            }
                        }
                        return 1;
                    } else {
                        return 0;
                    }
                }
            default:
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
    return 1;
}

int IsChecked(Game* G){
    printf("entered IsChecked()...\n");
    //first we get the playing king 
    Color turn = G->turn;
    Token* King;
    if(turn==WHITE){
        King = G->board->hands[0][12];
    } else if(turn==BLACK){
        King = G->board->hands[1][12];
    } else {
        printf("turn problem...\n");
        return 0;
    }
    Slot* SK = King->slot;
    Coord* CK = SK->coord;
    int all_out = 0;
    int all_block = 0;
    //the King is check whenever he is in sight of an enemy piece 
    //3 possible ways :
        //from Diag -> Bishop || Queen || Pawn (only if direct diag)
    int diag_cpt = 1;

    int fst_out = 0;
    int snd_out = 0;
    int thrd_out = 0;
    int frth_out = 0;

    int fst_block = 0;
    int snd_block = 0;
    int thrd_block = 0;
    int frth_block = 0;

    int block_sum;
    int out_sum;

    Coord* CT1;
    Coord* CT2;
    Coord* CT3;
    Coord* CT4;

    
    printf("starting to check from diags\n");
    do {
        CT1 = new_Coord(CK->x+diag_cpt,CK->y+diag_cpt);
        CT2 = new_Coord(CK->x-diag_cpt,CK->y+diag_cpt);
        CT3 = new_Coord(CK->x+diag_cpt,CK->y-diag_cpt);
        CT4 = new_Coord(CK->x-diag_cpt,CK->y-diag_cpt);
        
        if(fst_out!=1 && fst_block!=1){
            if(IsInside(CT1)==1){
                Slot* ST1 = G->board->grid[CT1->x][CT1->y];
                if(ST1->occupied == 1){
                    Token* TT1 = FindToken(G->board,ST1);
                    Color col1 = TT1->color;
                    if(col1 != turn){
                        Role RT1 = TT1->role;
                        if(RT1==BISHOP || RT1==QUEEN){
                            return 1;
                        }
                        if(col1==BLACK && RT1==PAWN){
                            return 1;
                        }
                    } else {
                        fst_block = 1;
                    }
                }
            } else {
                fst_out = 1;
            }
        }

        if(snd_out!=1 && snd_block!=1){
            if(IsInside(CT2)==1){
                Slot* ST2 = G->board->grid[CT2->x][CT2->y];
                if(ST2->occupied == 1){
                    Token* TT2 = FindToken(G->board,ST2);
                    Color col2 = TT2->color;
                    if(col2 != turn){
                        Role RT2 = TT2->role;
                        if(RT2==BISHOP || RT2==QUEEN){
                            return 1;
                        }
                        if(col2==BLACK && RT2==PAWN){
                            return 1;
                        }
                    } else {
                        snd_block = 1;
                    }
                }
            } else {
                snd_out = 1;
            }
        }

        if(thrd_out!=1 && thrd_block!=1){
            if(IsInside(CT3)==1){
                Slot* ST3 = G->board->grid[CT3->x][CT3->y];
                if(ST3->occupied == 1){
                    Token* TT3 = FindToken(G->board,ST3);
                    Color col3 = TT3->color;
                    if(col3 != turn){
                        Role RT3 = TT3->role;
                        if(RT3==BISHOP || RT3==QUEEN){
                            return 1;
                        }
                        if(col3==WHITE && RT3==PAWN){
                            return 1;
                        }
                    } else {
                        thrd_block = 1;
                    }
                }
            } else {
                thrd_out = 1;
            }
        }

        if(frth_out!=1 && frth_block!=1){
            if(IsInside(CT4)==1){
                Slot* ST4 = G->board->grid[CT4->x][CT4->y];
                if(ST4->occupied == 1){
                    Token* TT4 = FindToken(G->board,ST4);
                    Color col4 = TT4->color;
                    if(col4 != turn){
                        Role RT4 = TT4->role;
                        if(RT4==BISHOP || RT4==QUEEN){
                            return 1;
                        }
                        if(col4==WHITE && RT4==PAWN){
                            return 1;
                        }
                    } else {
                        frth_block = 1;
                    }
                }
            } else {
                frth_out = 1;
            }
        }

        block_sum = fst_block + snd_block + thrd_block + frth_block;
        out_sum = fst_out + snd_out + thrd_out + frth_out;

        diag_cpt++;
    } while(block_sum + out_sum < 4);

    printf("all good for diags !!!\n");

        //from lines/columns -> Rook || Queen
        // (+1,0) (-1,0) (0,+1) (0,-1)
    int line_cpt = 1;

    fst_out = 0;
    snd_out = 0;
    thrd_out = 0;
    frth_out = 0;
    int stop = 0;

    /*
    printf("starting to check for linears\n");
    do {
        printf("entered do while loop for the %dth time\n",line_cpt);
        CT1 = new_Coord(CK->x+line_cpt,CK->y);
        CT2 = new_Coord(CK->x-line_cpt,CK->y);
        CT3 = new_Coord(CK->x,CK->y+line_cpt);
        CT4 = new_Coord(CK->x,CK->y-line_cpt);
    } while(stop==0);
    printf("all good for linears !!!\n"); */
        //from L -> Knights
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

int ValidMove(Game* G, Slot* S1, Slot* S2){
    //here we just wanna check if S2 isn't occupied by an ally token
    //later on we'll add the 'Pin' checker
    Token* T1 = FindToken(G->board,S1);
    printf("moving token is : %s\n", Id_to_visual(T1->id));
    Token* T2;

    printf("S2.occupied ? ->");
    if(S2->occupied){
        printf(" yes\n");
        T2 = FindToken(G->board,S2);
        printf("on slot's token : %s\n", Id_to_visual(T2->id));
        if(T1->color == T2->color){
            printf("Cannot do this move, slot occupied by one token of yours\n");
            return 0;
        }
    }
    printf(" no\n");

    printf("Token is pinned ? -> ");
    if(PinCheck(G,S1,S2)==1){
        printf("yes\n");
        printf("Cannot do this move, you're pinned\n");
        return 0;
    }
    printf("no\n");

    printf("King is checked ? -> ");
    if(IsChecked(G)){
        printf("yes\n");
        printf("You must protect your King !\n");
        return Unchecked(G,S1,S2);
    }
    printf("no\n");

    if(T1->color!=G->turn){
        printf("not your turn ! \n");
        return 0;
    }

    printf("checking on can move...\n");
    return CanMove(G,S1,S2);
}