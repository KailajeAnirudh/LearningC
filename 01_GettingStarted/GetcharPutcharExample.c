#include<stdio.h>
int main() {
    int c = 'a';
    // printf(char(*EOF));
    while ((c = getchar() )!= EOF)
       putchar(c);
    return 0;
}
