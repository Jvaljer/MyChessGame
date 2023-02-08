#include <stdio.h>
#include <stdlib.h>
#include "Turn.h"

int ValidInput(char input[2]){
    char letters[8] = "abcdefgh";
    char digits[8] = "12345678";

    int cpt = 0;
    for(int i=0; i<8; i++){
        if(input[0]==letters[i]){
            cpt++;
        } 
        if(input[1]==digits[i]){
            cpt++;
        }
    }

    if(cpt==2){
        return 1;
    } else {
        return 0;
    }
}

Coord* GetCoordFromInput(char input[2]){
    char fst = input[0];
    char snd = input[1];

    int x;
    int y;
    
    if(fst=='a'){
        y = 0;
    } else if(fst=='b'){
        y = 1;
    } else if(fst=='c'){
        y = 2;
    } else if(fst=='d'){
        y = 3;
    } else if(fst=='e'){
        y = 4;
    } else if(fst=='f'){
        y = 5;
    } else if(fst=='g'){
        y = 6;
    } else if(fst=='h'){
        y = 7;
    } else {
        y = -1;
    }

    if(snd=='1'){
        x = 0;
    } else if(snd=='2'){
        x = 1;
    } else if(snd=='3'){
        x = 2;
    } else if(snd=='4'){
        x = 3;
    } else if(snd=='5'){
        x = 4;
    } else if(snd=='6'){
        x = 5;
    } else if(snd=='7'){
        x = 6;
    } else if(snd=='8'){
        x = 7;
    } else {
        x = -1;
    }
    Coord* coord = new_Coord(x,y);
    return coord;
}

void Turn(Game* G){
    if(G->turn==WHITE){
        printf("WHITE to move -\n");
    } else if(G->turn==BLACK){
        printf("BLACK to move -\n");
    } else {
        printf("there's an error...");
    }
    //a turn happens like this :
        //asking for the user for 2 inputs
        //  first_input -> starting slot
        //  second_input -> ending slot

        //then we wanna check if the move is valid or not
        //if so -> move the token
        //if not -> restart from 'asking ...' 
    char first_input[2];
    char second_input[2];

    do {
        printf("please enter your starting slot's name :\n");
        scanf("%s", first_input);
    } while(ValidInput(first_input)==0);
    
    do {
        printf("now please enter your ending slot's name :\n");
        scanf("%s", second_input);
    } while(ValidInput(second_input)==0);

    Coord* C1 = GetCoordFromInput(first_input);
    Coord* C2 = GetCoordFromInput(second_input);

    Slot* S1 = G->board->grid[C1->x][C1->y];
    Slot* S2 = G->board->grid[C2->x][C2->y];

    printf("the slot corresponding to first input is : [%d][%d]\n", S1->coord->x, S1->coord->y);
    printf("the slot corresponding to second input is : [%d][%d]\n", S2->coord->x, S2->coord->y);

    if(ValidMove(G,S1,S2)){
        MoveToken(G->board,S1,S2);
    } else {
        printf("this move is not valid, please enter another one\n");
        Turn(G);
    }
}

void TestTurn(){
    Game* G = new_Game();
    PrintBoard(G->board);
    Turn(G);
    PrintBoard(G->board);
}