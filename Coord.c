#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Coord.h"

Coord* new_Coord(int i, int j){
    Coord* C = malloc(sizeof(Coord));
    C->x = i;
    C->y = j;
    return C;
}

Direction* new_Direction(){
    Direction* D_ = malloc(sizeof(Direction));
    D_->up = new_Coord(0,1);
    D_->down = new_Coord(0,-1);
    D_->right = new_Coord(1,0);
    D_->left = new_Coord(-1,0);
    D_->up_right = new_Coord(1,1);
    D_->up_left = new_Coord(-1,1);
    D_->down_right = new_Coord(1,-1);
    D_->down_left = new_Coord(-1,-1);
    return D_;
}

int EqCoord(Coord* C1, Coord* C2){
    return ( (C1->x)==(C2->x) && (C1->y)==(C2->y) );
}

int IsNeighbour(Coord* C1, Coord* C2){
    // for (0,0) all possible neighbours are : 
        // (0,1) (1,0) (0,-1) (-1,0)
    return ( 
        ( ((C1->x)==(C2->x)) && ((C2->y)==(C1->y+1)) ) ||
        ( ((C2->x)==(C1->x+1)) && ((C1->y)==(C2->y)) ) ||
        ( ((C1->x)==(C2->x)) && ((C2->x)==(C1->x-1)) ) ||
        ( ((C2->x)==(C1->x-1)) && ((C1->y)==(C2->y)) )
    );
}

int IsDirectDiag(Coord* C1, Coord* C2){
    // for (0,0) all possible adjacent diag are :
        // (1,1) (-1,-1) (-1,1) (1,-1)
    return (
        ( ((C2->x)==(C1->x+1)) && ((C2->y)==(C1->y+1)) ) ||
        ( ((C2->x)==(C1->x-1)) && ((C2->y)==(C1->y-1)) ) ||
        ( ((C2->x)==(C1->x+1)) && ((C2->y)==(C1->y-1)) ) ||
        ( ((C2->x)==(C1->x-1)) && ((C2->y)==(C1->y+1)) )
    );
}

void TestCoord(){
    printf("#- COORD TESTS START\n");
    printf("Testing Constructor :");
    Coord* C0 = new_Coord(1,0);
    Coord* C1 = new_Coord(0,-1);
    assert(C0->x==1 && C0->y==0);
    assert(C1->x==0 && C1->y==(-1));
    printf(" check\n");

    printf("Testing Equality :");
    assert( EqCoord(C0,C1)==0 );
    Coord* C0_bis = new_Coord(1,0);
    Coord* C1_false = new_Coord(-1,0);
    assert( EqCoord(C0,C0_bis)==1 );
    assert( EqCoord(C1, C1_false)==0 );
    printf(" check\n");

    printf("Testing Neighbouring :");
    assert(IsNeighbour(C0,C1)==0);
    Coord* C2 = new_Coord(0,0);
    Coord* C3 = new_Coord(0,1);
    assert( IsNeighbour(C0,C2)==1 );
    assert( IsNeighbour(C2,C0)==IsNeighbour(C0,C2) );
    assert( IsNeighbour(C0,C1)==0 );
    assert( IsNeighbour(C0,C3)==IsNeighbour(C3,C0) );
    printf(" check\n");

    printf("Testing Adjacent Diagonal :");
    Coord* C4 = new_Coord(1,1);
    Coord* C5 = new_Coord(-1,0);
    assert( IsDirectDiag(C2,C4)==1 );
    assert( IsDirectDiag(C1,C5)== 1);
    assert( IsDirectDiag(C4,C5)==0 );
    assert( IsDirectDiag(C0,C3)==IsDirectDiag(C3,C0) );
    printf(" check\n");
    
    printf(" -> COORD TEST END -#\n\n");
}