#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned getbits(unsigned x, unsigned p, unsigned n){
    assert(p>n-1);
    unsigned mask = (((1<<n)-1)<<(p+1-n));
    // printf("\nx:%d, p:%d, n:%d\n",x,p,n);
    printf("x:%32b\nm:%32b\nr1:%31b\nr2:%31b\n\n", x, mask, x&mask, (x&mask)>>(p+1-n));
    return (x&mask)>>(p+1-n);
}


int main(int argc, char *argv[]) {
    // printf("%d\n\n", argc);
    assert(argc==4);
    unsigned res = getbits(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

    return 0;
}
