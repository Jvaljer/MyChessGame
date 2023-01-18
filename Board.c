#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Board.h"

Board* new_Board(){
    Board* B = malloc(sizeof(Board));
    Role line[8] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            Coord* C_ = new_Coord(i,j);
            Slot* S_ = new_Slot(C_);
            B->grid[i][j] = S_ ;
            //assert( EqSlotP( B->grid[i][j], S_ ));
            if(i==0){
                Token* T_ = new_Token(B->grid[i][j],line[j],WHITE);
                B->hands[0][8+j] = T_ ;
                S_->occupied = 1;
                T_->onBoard = 1;
                //assert( EqTokenP(T_,B->hands[0][8+j]) );
            } else if(i==1){
                Token* T_ = new_Token(B->grid[i][j],PAWN,WHITE);
                B->hands[0][j] = T_ ;
                S_->occupied = 1;
                T_->onBoard = 1;
                //assert( EqTokenP(T_,B->hands[0][j]) );
            } else if(i==6){
                Token* T_ = new_Token(B->grid[i][j],PAWN,BLACK);
                B->hands[1][j] = T_ ;
                S_->occupied = 1;
                T_->onBoard = 1;
                //assert( EqTokenP(T_,B->hands[1][j]) );
            } else if(i==7){
                Token* T_ = new_Token(B->grid[i][j],line[j],BLACK);
                B->hands[1][8+j] = T_ ;
                S_->occupied = 1;
                T_->onBoard = 1;
                //assert( EqTokenP(T_,B->hands[1][8+j]) );
            }
        }
    }
    return B;
}

Token* FindToken(Board* B, Slot* S){
    for(int i=0; i<2; i++){
        for(int j=0; j<16; j++){
            if( EqSlotP(B->hands[i][j]->slot, S) && B->hands[i][j]->onBoard){
                return B->hands[i][j];
            }
        }
    }
    //return new_Token(new_Slot(new_Coord(-1,-1)),KING,NONE);
    printf("token wasn't found...\n");
    return NULL;
}

void PrintBoard(Board* B){
    printf("\n  a    b    c    d    e    f    g    h\n");
    printf("-----------------------------------------\n");
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("| ");
            if(B->grid[i][j]->occupied){
                Token* T_ = FindToken(B,B->grid[i][j]);
                printf("%s ", Id_to_str(T_->id));
            } else {
                printf("   ");
            }
        }
        printf("| %d\n", i+1);
        printf("-----------------------------------------\n");
    }
}

void MoveToken(Board* B, Slot* S1, Slot* S2){
    Token* T_ = FindToken(B,S1);
    S1->occupied = 0;
    T_->slot = S2;
    S2->occupied = 1;
}


void TakeToken(Board* B, Slot* S){
    Token* T_ = FindToken(B,S);
    S->occupied = 0;
    T_->slot = new_Slot(new_Coord(-1,-1));
    T_->onBoard = 0;
}

void TestBoard(){
    printf("#- BOARD TEST START\n");
    printf("Testing Constructor : ");
    Board* B = new_Board();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            assert( B->grid[i][j]->coord->x==i && B->grid[i][j]->coord->y==j);
        }
    }
    printf(" check\n");

    printf("Testing Printing #1 : ");
    PrintBoard(B);
    printf(" check\n");

    printf("Testing Token moving/Removing : ");
    MoveToken(B,B->grid[1][4],B->grid[3][4]);
    TakeToken(B,B->grid[1][0]);
    assert(B->grid[1][0]->occupied==0);
    assert( FindToken(B,B->grid[1][0])==NULL );
    assert( FindToken(B,B->grid[1][4])==NULL);
    assert( FindToken(B,B->grid[3][4])!=NULL);
    Token* T_ = FindToken(B,B->grid[3][4]);
    assert( EqSlotP(B->grid[3][4],T_->slot)==1 );
    printf(" check\n");

    printf("Testing Printing #2 : ");
    PrintBoard(B);
    printf(" check\n");

    printf(" -> BOARD TEST END -# \n\n");
}