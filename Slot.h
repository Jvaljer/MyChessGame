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
 * Test Function for Slot stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestSlot();

#endif