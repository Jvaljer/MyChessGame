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

void TestSlot(){
    printf("#- SLOT TEST START\n");
    printf("Testing Constructor :");
    Coord* C0 = new_Coord(2,1);
    Slot* S0 = new_Slot(C0);
    Slot* S1 = new_Slot(new_Coord(1,2));
    assert(EqCoord(S0->coord,C0)==1);
    assert(EqCoord(S0->coord,new_Coord(2,1))==1);
    assert(EqCoord(S1->coord,new_Coord(1,2))==1);
    assert((S1->occupied)==0);
    assert((S0->occupied)==0);
    printf(" check\n");

    printf("Testing Equality :");
    Slot* S0_bis = new_Slot(new_Coord(2,1));  
    assert( EqSlot(S0,S1)==0 );
    assert( EqSlot(S0,S0_bis)==1 );
    Coord* Cp = new_Coord(5,5);
    Slot* Sp = new_Slot(Cp);
    Slot* Spp = new_Slot(Cp);
    assert(EqSlotP(Sp,Spp));
    printf(" check\n");

    printf("Testing Slot Neighbouring :");
    assert(IsNeighbourSlot(S0,S1)==0);
    Slot* S2 = new_Slot(new_Coord(0,0));
    Slot* S3 = new_Slot(new_Coord(0,1));
    assert( IsNeighbourSlot(S0,S2)==0 );
    assert( IsNeighbourSlot(S2,S0)==IsNeighbourSlot(S0,S2) );
    assert( IsNeighbourSlot(S0,S3)==IsNeighbourSlot(S3,S0) );
    printf(" check\n");

    printf("Testing Slot Adjacent Diagonal :");
    Slot* S4 = new_Slot(new_Coord(1,1));
    Slot* S5 =  new_Slot(new_Coord(0,0));
    assert( IsDirectDiagSlot(S2,S4)==1 );
    assert( IsDirectDiagSlot(S1,S5)== 0);
    assert( IsDirectDiagSlot(S4,S5)==1 );
    assert( IsDirectDiagSlot(S0,S3)==IsDirectDiagSlot(S3,S0) );
    printf(" check\n");

    printf("Testing char* conversion : ");
    Slot* S6 = new_Slot(new_Coord(3,7));
    printf(" excpeting [3][7] -> ");
    PrintSlot(S6);
    printf("\n");
    printf(" -> SLOT TEST END -# \n\n");
}