#include<stdio.h>

int main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = -20;
    upper = 150;
    step = 20;
    celsius = lower;
    printf("%6s\t%6s\n", "cels", "fahr");
    while (celsius <= upper) {
        fahr =(9.0/5.0)*celsius + 32.0;
        printf("%6.1f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}