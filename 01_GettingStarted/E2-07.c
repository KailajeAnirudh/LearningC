/*Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

unsigned invert(int x, int p, int n)
{
    assert(p+1-n>=0);
    assert(p>=0 || n>= 0);
    assert(p<=sizeof(x)*8 || n<=sizeof(x)*8);
    unsigned bitinvert_mask = ((1<<n)-1)<<(p+1-n);
    printf("\n___________________\nx:%32b\np:%32d\nn:%32d\nm:%32b\nr:%32b\n___________________\n", x, p, n, bitinvert_mask, x^bitinvert_mask);    
    return (x^bitinvert_mask);
}

int main(int argc, char **argv)
{
    int i; int x, p, n;
    x = atoi(argv[1]);
    p = atoi(argv[2]);
    n = atoi(argv[3]);
    // printf("x:%32b\np:%d\nn:%d\n", x, p, n);
    x = invert(x, p, n);
}