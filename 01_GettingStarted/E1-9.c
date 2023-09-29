#include<stdio.h>

int main() {
    int c, oldchar;
    c = getchar();
    putchar(c);
    oldchar = c;
    while((c = getchar()) != EOF) {
        if (c == '\t') c = ' ';
        if ((c == ' ') && (oldchar == c));
        else {
            putchar(c);
        }
        oldchar = c;
    }
    return 0;
}