#include <stdio.h>
#include <wchar.h>
#include <locale.h>

wchar_t uni_test(int n);

int main() {
    setlocale(LC_CTYPE, "");
    /*
    wchar_t star = 0x2605;
    wprintf(L"%lc\n", star);
    */

    wchar_t wP = 0x265F;
    wprintf(L"%lc\n", wP);

    wchar_t WK = 0x265A;
    wprintf(L"%lc\n", WK);

    wchar_t bK = 0x2658;
    wprintf(L"%lc \n", bK);

    wchar_t test = uni_test(1);
    wprintf(L"%lc", test);
}

wchar_t uni_test(int n){
    wchar_t uni;
    switch (n){
        case 0 :
            uni = 0x265F;
            return uni;
        case 1 : 
            uni = 0x265A;
            return uni;
        default:
            uni = 0x2658;
            return uni;
    }
}