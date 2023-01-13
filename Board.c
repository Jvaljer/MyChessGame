#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Board.h"

Board* new_Board(){
    int size = 8;
    Role line[8] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    
    Board* B;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            Slot* S_ = new_Slot(new_Coord(i,j));
            B->grid[i][j] = S_;
            if(i=0){
                Token* T_ = new_Token(S_,line[j],WHITE);
                B->hands[0][size+j] = T_;
               S_->occupied = 1;
               T_->onBoard = 1;
            } else if(i=1){
                Token* T_ = new_Token(S_,PAWN,WHITE);
                B->hands[0][j] = T_;
                S_->occupied = 1;
                T_->onBoard = 1;
            } else if(i=6){
                Token* T_ = new_Token(S_,PAWN,BLACK);
                B->hands[1][j] = T_;
                S_->occupied = 1;
                T_->onBoard = 1;
            } else if(i=7){
                Token* T_ = new_Token(S_,line[j],BLACK);
                B->hands[1][size+j] = T_;
                S_->occupied = 1;
                T_->onBoard = 1;
            }
            //assert( EqSlotP(B->S[i][j],S_) );
        }
    }
    return B;
}

Slot* GetSlot(Board* B, Coord* C){
    return B->grid[C->x][C->y];
}

Token* GetToken(Board* B, Slot* S){
    int size = 8;
    for(int i=0; i<2; i++){
        for(int j=0; j<size; j++){
            if(EqSlotP(B->hands[i][j]->slot,S) && S->occupied){
                return B->hands[i][j];
            }
        }
    }
}

void PrintBoard(Board* B){
    int size = 8;
    char* transition_line = "-----------------------------------------";
    printf("  a    b    c    d    e    f    g    h\n");
    printf("%s\n", transition_line);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(j==0){
                printf("|");
            }
            if( B->grid[i][j]->occupied==1){
                Token* T_ = GetToken(B,B->grid[i][j]);
                printf(" %s ",(char*)T_->id);
            } else {
                printf("    ");
            }
            printf("|");
        }
        printf(" %d\n", i);
        printf("%s\n",transition_line);
    }

}

void TestBoard(){
    printf("#- BOARD TEST START\n");
    printf("Testing Board Constructor -> ");
    Board* B = new_Board();
    Slot* S00 = new_Slot(new_Coord(0,0));
    Slot* S57 = new_Slot(new_Coord(5,7));
    assert( EqSlot(B->grid[0][0], S00)==1 );
    assert( EqSlot(B->grid[5][7], S57)==1 );
    assert( EqSlotP(B->grid[5][7], S57)==0 );
    printf(" check\n");

    printf("Testing Slot Getter -> ");
    Slot* S35 = GetSlot(B,new_Coord(3,5));
    assert( EqSlot(B->grid[3][5], S35) );
    assert( EqSlotP(B->grid[3][5], S35) );
    printf(" check\n");
    
    printf(" -> BOARD TEST END -# \n\n");
}