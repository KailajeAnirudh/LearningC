#include<stdio.h>

int main() {
    float fahr, celsius;
    printf("%6s\t%6s\n", "fahr", "cels");
    for (fahr = 300.0; fahr>= 0.0; fahr -= 20.0) {
        printf("%6.1f\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
    return 0;
}