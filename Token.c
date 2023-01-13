#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Token.h"

Token* new_Token(Slot* S, Role R, Color C){
    Token* T = malloc(sizeof(Token));
    T->role = R;
    T->color = C;
    T->slot = S;
    return T;
}

void TestToken(){
    printf("#- TOKEN TEST START\n");
    printf("Testing Constructor :");
    

    printf(" -> TOKEN TEST END -# \n\n");
}