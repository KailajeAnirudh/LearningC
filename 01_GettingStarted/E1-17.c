#include<stdio.h>
#define MAXLINE 80
int main() {
    int c, len = 0;
    while((c = getchar()) != '\n' && len<MAXLINE) {
        putchar(c); ++len;
    }
    return 0; 
}