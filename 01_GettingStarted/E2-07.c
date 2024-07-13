/*Write a function invert(x,p,n) that returns x with the n bits that begin at position p
inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

unsigned invert(int x, int p, int n)
{
    printf("x:%32b\n", x);
    printf("  %32b\n", (x>>(p-n+1) & ((1<<n) -1)));
    printf("m:%32b\n", ((1U<<n)-1)<<(p+1-n));
    printf("r:%32b", x^(((1U<<n)-1)<<(p+1-n)));
    return x;
}

int main(int argc, char **argv)
{
    int i; 
    int x, p, n;
    int args[argc];

    x = atoi(argv[1]);
    p = atoi(argv[2]);
    n = atoi(argv[3]);
    printf("x:%32b\np:%d\nn:%d\n", x, p, n);
    x = invert(x, p, n);
}