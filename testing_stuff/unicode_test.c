#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

void uni_test(int n);

int main() {
    setlocale(LC_CTYPE, "");
/*
    wchar_t wP = 0x265F;
    wprintf(L"%lc\n", wP);

    wchar_t WK = 0x265A;
    wprintf(L"%lc\n", WK);

    wchar_t bK = 0x2658;
    wprintf(L"%lc \n", bK);
 */
    wchar_t _1 = 0x265A;
    wchar_t _2 = 0x265B;
    wchar_t _3 = 0x265C;
    wchar_t _4 = 0x265D;
    wchar_t _5 = 0x265E;
    wchar_t _6 = 0x265F;

    char* uni_1 = (char*) _1;

    printf("%s \n", uni_1);
}