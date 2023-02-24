#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "Slot.h"

Slot* new_Slot(Coord* C){
    Slot* S = malloc(sizeof(Slot));
    S->coord = C;
    S->occupied = 0;
    return S;
}

int EqSlot(Slot* S1, Slot* S2){
    //Testing the coord's VALUE
    return EqCoord(S1->coord,S2->coord);
}

int EqSlotP(Slot* S1, Slot* S2){
    //Testing the coord's ADRESS
    return (S1->coord == S2->coord);
}

int IsNeighbourSlot(Slot* S1, Slot* S2){
    return IsNeighbour(S1->coord,S2->coord);
}

int IsDirectDiagSlot(Slot* S1, Slot* S2){
    return IsDirectDiag(S1->coord,S2->coord);
}

void PrintSlot(Slot* S){
    printf("[%d][%d]", S->coord->x, S->coord->y);
}