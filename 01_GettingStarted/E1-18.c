#include<stdio.h>
#define MAXLINE 50

int getline1(char s[], int lim);
int main() {
    int c, j, len;
    char line[MAXLINE];
    while((len = getline1(line, MAXLINE)) > 0) {
        for (j=len-2; line[j] == ' ' || line[j] == '\t'; j--);
        j++;
        for (int i=0; i<j; i++) putchar(line[i]);
        putchar('\n');
    }
    
    return 0;
}

int getline1(char s[], int lim) {
    int c, i;

    for (i = 0; i< lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}