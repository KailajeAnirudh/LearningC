/*Exercise 1−9. Write a program to copy its input to its output, replacing each string of one or more blanks by a
single blank.*/
#include<stdio.h>

int main() {
    int c, oldchar;
    // c = getchar();
    // putchar(c);
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