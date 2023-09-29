#include<stdio.h>
int main() {
    int c = 'a';
    while ((c = getchar() )!= EOF)
       putchar(c);
    return 0;
}
