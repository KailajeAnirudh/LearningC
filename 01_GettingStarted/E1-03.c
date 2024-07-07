#include<stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;
    printf("%6s\t%6s\n", "fahr", "cels");
    while(fahr <= upper) {
        celsius = (5.0/9.0)*(fahr-32);
        printf("%5.1f\t%6.1f\n", fahr, celsius);
        fahr  = fahr+step;
    }
    return 0;
}