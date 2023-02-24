#include <stdio.h>
#include <stdlib.h>

#include "Turn.h"

int main(int argc, char* argv){
    Game* game = new_Game();
    while(Finished(game)==0){
        PrintBoard(game->board);
        Turn(game);
    }
    return 0;
}