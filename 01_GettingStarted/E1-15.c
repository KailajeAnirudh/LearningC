#include<stdio.h>

float F2C(int fahr) {return ((5.0/9.0)*(fahr-32));}

int main() {
    for (int i = 0; i<=300; i+=20){
        printf("%5d\t%5.2f\n", i, F2C(i));
    }
    return 0;
}