/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

unsigned getbits(unsigned x, int p, int n)
{
    // Ensure that p and n are within valid bounds
    if (p < 0 || n < 0 || p >= sizeof(x) * 8 || n > sizeof(x) * 8 || (p + 1 - n) < 0) {
        fprintf(stderr, "Invalid bit position or length\n");
        return 0;
    }
    // Shift right by (p+1-n) to move the desired bits to the rightmost position
    // then mask the result with (1 << n) - 1 to isolate the last n bits
    return (x >> (p+1-n)) & ((1 << n) - 1);
}

unsigned setbits(unsigned x, unsigned y, int p, int n){
    // if (p < 0 || n < 0 || p >= sizeof(x) * 8 || n > sizeof(x) * 8 || (p + 1 - n) < 0) {
    //     fprintf(stderr, "Invalid bit position or length\n");
    //     return 0;
    // }

    assert(p>=n-1);
    assert(p>=0);
    assert(n>=0);
    assert(p<=sizeof(x)*8);
    assert(n<=sizeof(x)*8);

    unsigned clear_mask = ~((1<<n)-1)<<(p+1-n) | ((1<<(p+1-n))-1);
    printf("\n\nm:%32b\n", clear_mask);
    unsigned set_mask = (((1<<n)-1)&y)<<(p+1-n);
    printf("m:%32b\n", set_mask);
    unsigned r = (x&clear_mask)|(set_mask);
    return r;
}

int main(int argc, char *argv[])
{
    assert(argc==5);
    unsigned x = atoi(argv[1]);
    unsigned y = atoi(argv[2]);
    int p = atoi(argv[3]), n = atoi(argv[4]);
    printf("x:%32b\ny:%32b\np:%32d\nn:%32d\nr:%32b\n\n", x, y, p, n, setbits(x,y,p,n));
}
