#include<stdio.h>

int main() {
    int c, nl, nt, nb;
    nl = 0;
    nt = 0;
    nb = 0;
    while(((c = getchar()) != EOF)) {
        printf("%d", c);
        // putchar(c);
        printf("\n");
        if (c == '\n') ++nl;
        if (c == '\t') ++nt;
        if (c == ' ') ++nb;
    }
    printf("New Lines: %2d Balnks:\t%2d Tabs:\t%2d\n", nl, nb, nt);
    return 0;
}