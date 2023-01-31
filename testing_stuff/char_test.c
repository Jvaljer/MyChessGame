#include <stdio.h>

int main(int argc, char* argv){
    char input[2];
    printf("enter your input :\n");
    scanf("%s", input);
    char fst = input[0];
    char snd = input[1];
    printf("your full input is : %s\n", input);
    printf("fst -> %c\n", fst);
    printf("snd -> %c\n", snd);

    if(fst=='e'){
        printf("fst is 'e' :)\n");
    } else {
        printf("fst is not 'e'...\n");
    }
    if(snd=='3'){
        printf("snd is '3' :)\n");
    } else {
        printf("snd is not '3'...\n");
    }
}