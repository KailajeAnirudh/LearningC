/*Exercise 1−8. Write a program to count blanks, tabs, and newlines.*/
#include<stdio.h>

int main() {
    int c, nl, nt, nb;
    nl = 0;
    nt = 0;
    nb = 0;
    while(((c = getchar()) != '\n')) {
        // printf("%s", c);
        // putchar(c);
        print("\n");
        if (c == '\n') ++nl;
        if (c == '\t') ++nt;
        if (c == ' ') ++nb;
    }
    printf("New Lines: %2d Blanks:\t%2d Tabs:\t%2d\n", nl, nb, nt);
    return 0;
}