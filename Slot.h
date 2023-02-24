#ifndef SLOT_H
#define SLOT_H

#include "Coord.h"

/*
 * A Slot is defined by a Coord & an 'occupied' statement
 *  with (coord:Coord*) and (occupied:int)
 *  occupied is 1 when there's something on the Slot (might be useful)
 */
typedef struct Slot{
    Coord* coord;
    int occupied; 
} Slot;

/*
 * Equality for type Slot
 * args : (S1:Slot*) (S2:Slot*)
 * result : 1 if S1.coord & S2.coord has the same values
 */
int EqSlot(Slot* S1, Slot* S2);

/*
 * Equality for type Slot
 * args : (S1:Slot*) (S2:Slot*)
 * result : 1 if S1 & S2 are pointing at the same coord
 */
int EqSlotP(Slot* S1, Slot* S2);

/*
 * Neighbour testing for Slots
 * args : (S1:Slot*) (S2:Slot*)
 * result : 1 if S2 neighbour of S1, else 0
 */
int IsNeighbourSlot(Slot* S1, Slot* S2);

/*
 * Adjacent Diagonal Testing for Slots
 * args : (S1:Slot*) (S2:Slot*)
 * result : 1 if S2 in adjacent Diag of S1, else 0
 */
int IsDirectDiagSlot(Slot* S1, Slot* S2);

/*
 * Slot Constructor
 * args : (C:Coord*)
 * result : returns a new Slot with C as coord and 0 as occupied
 */
Slot* new_Slot(Coord* C);

/*
 * Printing function for slots
 * args : (S:Slot*)
 * result :
 *  "[x][y]\n" with x = S->coord->x & y = S->coord->y 
 */
void PrintSlot(Slot* S);

#endif