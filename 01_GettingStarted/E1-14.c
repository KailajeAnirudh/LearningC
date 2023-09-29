#include<stdio.h>
/*
This program takes in a sentence, and print outs a histogram of the characters.
*/
int main() {
    int c, offset = 0;
    int alphafrequencies[26];
    for (int i = 0; i<26; i++) alphafrequencies[i] = 0;
    while((c = getchar()) != '\n') {
        if((c >= 'A') && (c <= 'Z')) alphafrequencies[c-65] += 1;
        if((c >= 'a') && (c <= 'z')) alphafrequencies[c-97] += 1;
    }
    for (int i = 0; i< 26; i++) {
        if (alphafrequencies[i] > 0) {
            printf("%c: ", (i+97));
            for(int j = 0; j<=alphafrequencies[i]; j++) {
                printf("-");
            }
            printf("\n");
        }
    }
    return 0;
}