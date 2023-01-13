#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Board.h"

Board* new_Board(){
    Board* B;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            Slot* S_ = new_Slot(new_Coord(i,j));
            B->grid[i][j] = S_;
            //assert( EqSlotP(B->S[i][j],S_) );
        }
    }
    return B;
}

Slot* GetSlot(Board* B, Coord* C){
    return B->grid[C->x][C->y];
}

void TestBoard(){
    printf("#- BOARD TEST START\n");
    printf("Testing Board Constructor -> ");
    Board* B = new_Board();
    Slot* S00 = new_Slot(new_Coord(0,0));
    Slot* S57 = new_Slot(new_Coord(5,7));
    assert( EqSlot(B->grid[0][0], S00)==1 );
    assert( EqSlot(B->grid[5][7], S57)==1 );
    printf(" check\n");

    printf("Testing Slot Getter -> ");
    Slot* S35 = GetSlot(B,new_Coord(3,5));
    assert( EqSlot(B->grid[3][5], S35) );
    assert( EqSlotP(B->grid[3][5], S35) );
    printf(" check\n");
    
    printf(" -> BOARD TEST END -# \n\n");
}