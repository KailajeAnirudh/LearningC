/*Counts the number of 1-bits in an integer*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

unsigned bitcount(unsigned x)
{
    int r = 0;
    printf("\n___________________________________\n \
    \nx :%32b\n");

    while (x != 0){
        x &= (x-1);
        ++r;
        printf("%d :%32b\n", r, x);
    }
    printf("r :%32d\n___________________________________\n", r);
    
    return r;
}

int main(int argc, char **argv)
{
    unsigned x;
    assert(argc == 2);
    x = atoi(argv[1]);
    int r = bitcount(x);
}