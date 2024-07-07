#include<stdio.h>

int main(){
    float fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;
    cels = lower;
    printf("%6s\t%6s\n", "cels", "fahr");
    while(cels <= upper){
        fahr = (9.0/5.0)*cels + 32.0;
        printf("%5.1f\t%5.1f\n", cels, fahr);
        cels += step;
    }
}