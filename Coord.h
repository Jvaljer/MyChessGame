#ifndef COORD_H
#define COORD_H

/*
 * A Coord is defined by a couple (x,y)
 *  with (x:int) and (y:int)
 */
typedef struct Coord{
    int x;
    int y;
} Coord;

/*
 * Direction are all the possible (x,y) couples that can increment an actual coord
 */
typedef struct Direction{
    Coord* up;
    Coord* down;
    Coord* right;
    Coord* left;
    Coord* up_right;
    Coord* up_left;
    Coord* down_right;
    Coord* down_left;
}Direction;

/*
 * Direction Constructor
 * args : None
 * result : gives each direction its values
 */
Direction* new_Direction();

/*
 * Coord Constructor
 * args : (i:int) (j:int)
 * result : a new Coord with (x=i,y=j) as values
 */
Coord* new_Coord(int i, int j);

/*
 * Equality for type Coord
 * args : (C1:Coord*) (C2:Coord*)
 * result : 1 if C1=C2, else 0
 */
int EqCoord(Coord* C1, Coord* C2);

/*
 * Neighbour testing
 * args : (C1:Coord*) (C2:Coord*)
 * result : 1 if C2 neighbour of C1, else 0
 */
int IsNeighbour(Coord* C1, Coord* C2);

/*
 * Adjacent Diagonal Testing
 * args : (C1:Coord*) (C2:Coord*)
 * result : 1 if C2 in adjacent Diag of C1, else 0
 */
int IsDirectDiag(Coord* C1, Coord* C2);

/*
 * Test Function for Coord stuff
 * args : None
 * result : nothing if all assertion true
 *          error if an assertion false
 */
void TestCoord();

#endif