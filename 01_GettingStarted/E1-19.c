#include<stdio.h>
#define MAXLINE 50

int getline(char s[], int lim);
void reverseline(char s[], char rs[], int lim);
int main() {
    int c, j, len;
    char line[MAXLINE], reversedline[MAXLINE];
    while((len = getline(line, MAXLINE)) > 0) {
        reverseline(line, reversedline, len);
        printf("%s", reversedline);
    }
    
    return 0;
}

int getline(char s[], int lim) {
    int c, i;

    for (i = 0; i< lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void reverseline(char s[], char rs[], int lim) {
    int j = lim-1;
    for (j = lim-1; j>= 0; --j) {
        rs[(lim-1)-j] = s[j];
    }
    rs[lim] = '\0';
}