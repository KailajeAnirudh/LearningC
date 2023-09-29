#include<stdio.h>
/*
This program prints out a histogram of the word lengths, given a input string.
*/
int main() {
    int c, current_wordlen;
    current_wordlen = 0;
    int wordlenghts[20];
    for (int i = 0; i<20; ++i) wordlenghts[i] = 0;
    while ((c = getchar()) != '\n') {
        if ((c == ' ') || (c == '\t') || (c == '\n')) {
            if (current_wordlen >= 20) current_wordlen = 0;
            else {
                wordlenghts[current_wordlen] += 1;
                current_wordlen = 0;
            }
        } 
        else current_wordlen++;
    }

    for (int i = 19; i>= 0; i--) {
        if (wordlenghts[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j<= wordlenghts[i]; j++) printf("-");
            printf("\n");
        }
    }
return 0;
}