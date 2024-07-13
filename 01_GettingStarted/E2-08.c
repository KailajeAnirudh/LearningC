/*Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

unsigned rightrot(unsigned x, unsigned n)
{
    assert(n>=0);
    assert(n<=sizeof(x)*8);
    unsigned rightshifted_x = x>>n;
    unsigned lostbits = (x&((1<<n)-1));
    unsigned leftshifted_lostbits = lostbits << \
                                (sizeof(x)*8 -n);
    printf("\n___________________________________\n \
    \nx :%32b\nn :%32d\ns :%32d\nss:%32b\nm1:%32b\
    \nm2:%32b\nm3:%32b\nr :%32b\
    \n___________________________________\n", \
    x, n, sizeof(x), x>>2, rightshifted_x, \
    lostbits, leftshifted_lostbits, rightshifted_x|leftshifted_lostbits);    
    return (rightshifted_x | leftshifted_lostbits);
}

int main(int argc, char **argv)
{
    int i; unsigned x, p, n;
    assert(argc == 3);
    x = atoi(argv[1]);
    n = atoi(argv[2]);
    // printf("x:%32b\np:%d\nn:%d\n", x, p, n);
    int r = rightrot(x, n);
}