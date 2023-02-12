#include <stdio.h>
#include <stdlib.h>

#include "Turn.h"

int main(int argc, char* argv){
    /*
     * Test Section
     */
    //TestCoord();  
    //TestSlot(); 
    //TestToken(); 
    //TestBoard(); 
    
    //TestGame();
    //TestTurn();

    /*
     * Main Section
     */
    Game* game = new_Game();
    while(Finished(game)==0){
        PrintBoard(game->board);
        Turn(game);
        system("clear");
    }
    return 0;
}