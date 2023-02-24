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

int IsInside(Coord* C){
    if(C->x < 0 || C->x > 7 || C->y < 0 || C->y > 7){
        return 0;
    } else {
        return 1;
    }
}