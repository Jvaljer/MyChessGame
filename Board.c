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
                //assert( EqTokenP(T_,B->hands[0][8+j]) );
            } else if(i==1){
                Token* T_ = new_Token(B->grid[i][j],PAWN,WHITE);
                B->hands[0][j] = T_ ;
                //assert( EqTokenP(T_,B->hands[0][j]) );
            } else if(i==6){
                Token* T_ = new_Token(B->grid[i][j],PAWN,BLACK);
                B->hands[1][j] = T_ ;
                //assert( EqTokenP(T_,B->hands[1][j]) );
            } else if(i==7){
                Token* T_ = new_Token(B->grid[i][j],line[j],BLACK);
                B->hands[1][8+j] = T_ ;
                //assert( EqTokenP(T_,B->hands[1][8+j]) );
            }
        }
    }
    return B;
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
    printf(" -> BOARD TEST END -# \n\n");
}