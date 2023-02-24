#include <stdio.h>
#include <stdlib.h>

#include "Test.h"

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

void TestToken(){
    printf("#- TOKEN TEST START\n");
    printf("Testing Constructor :");
    Coord* C0 = new_Coord(1,1);
    Slot* S0 = new_Slot(C0);
    Token* T0 = new_Token(S0,KING,WHITE);
    assert( EqSlot(T0->slot,S0) );
    assert( EqSlotP(T0->slot,S0) );
    assert( T0->role == KING );
    assert( T0->color == WHITE);
    assert( T0->id == WK );
    printf(" check\n");

    printf(" -> TOKEN TEST END -# \n\n");
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

    printf("Testing Printing #1 : ");
    PrintBoard(B);
    printf(" check\n");

    printf("Testing Token moving/Removing : ");
    MoveToken(B,B->grid[1][4],B->grid[3][4]);
    TakeToken(B,B->grid[1][0]);
    assert(B->grid[1][0]->occupied==0);
    assert( FindToken(B,B->grid[1][0])==NULL );
    assert( FindToken(B,B->grid[1][4])==NULL);
    assert( FindToken(B,B->grid[3][4])!=NULL);
    Token* T_ = FindToken(B,B->grid[3][4]);
    assert( EqSlotP(B->grid[3][4],T_->slot)==1 );
    printf(" check\n");

    printf("Testing Printing #2 : ");
    PrintBoard(B);
    printf(" check\n");

    printf(" -> BOARD TEST END -# \n\n");
}

void TestGame(){
    printf("#- GAME TEST START\n");
    printf("Testing Cosntructor : \n");
    Game* G0 = new_Game();
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            assert( EqCoord(G0->board->grid[i][j]->coord,new_Coord(i,j)) );
            if(i<2)
                assert( G0->board->hands[i][j] != NULL );
        }
    }
    PrintBoard(G0->board);
    printf("    check\n");

    printf("Testing Pawn Moves : \n");
    assert( PawnMove(G0,FindToken(G0->board,G0->board->grid[1][3]), G0->board->grid[3][3])==1 );    
    assert( PawnMove(G0,FindToken(G0->board,G0->board->grid[6][6]), G0->board->grid[1][5])==0 );
    MoveToken( G0->board,  FindToken(G0->board,G0->board->grid[6][2])->slot, G0->board->grid[2][4] );
    assert( PawnMove(G0, FindToken(G0->board, G0->board->grid[1][3]), G0->board->grid[2][4])==1 );
    printf("    check\n");

    ChangeTurn(G0);
    assert(G0->turn == BLACK);

    printf("Testing Rook Moves : \n");
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[6][7])->slot, G0->board->grid[5][0] );
    assert( RookMove(G0, FindToken(G0->board, G0->board->grid[7][7]), G0->board->grid[3][7])==1 );
    assert( RookMove(G0, FindToken(G0->board, G0->board->grid[0][7]), G0->board->grid[4][7])==0 );
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[7][7])->slot, G0->board->grid[3][7]);
    PrintBoard(G0->board);
    printf("    check\n");

    printf("Testing Knight Moves : \n");
    ChangeTurn(G0);
    assert(G0->turn == WHITE);

    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[0][1]), G0->board->grid[2][2])==1 );
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[0][1]), G0->board->grid[2][0])==1 );
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[0][1])->slot, G0->board->grid[2][2]);
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[2][2]), G0->board->grid[3][4])==1 );
    assert( KnightMove(G0, FindToken(G0->board, G0->board->grid[2][2]), G0->board->grid[3][0])==1 );
    printf("    check\n ");

    printf("Testing Bishop Moves : \n");
    assert( BishopMove(G0, FindToken(G0->board, G0->board->grid[0][5]), G0->board->grid[3][2])==0 );
    MoveToken( G0->board, FindToken(G0->board, G0->board->grid[1][6])->slot, G0->board->grid[2][6]);
    assert( BishopMove(G0, FindToken(G0->board, G0->board->grid[0][5]), G0->board->grid[2][7])==1 );
    printf("    check\n ");

    printf("Testing Queen Moves : \n");
    printf("    must test\n ");

    printf("Testing King Moves : \n");
    printf("    must test\n ");

    printf(" -> GAME TEST END -# \n\n");
}

void TestTurn(){
    Game* G = new_Game();
    PrintBoard(G->board);
    Turn(G);
    PrintBoard(G->board);
}