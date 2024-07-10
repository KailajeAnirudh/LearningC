#include<stdio.h>
#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

unsigned getbits(unsigned x, int p, int n)
{
    // Ensure that p and n are within valid bounds
    if (p < 0 || n < 0 || p >= sizeof(x) * 8 || n > sizeof(x) * 8 || (p + 1 - n) < 0) {
        fprintf(stderr, "Invalid bit position or length\n");
        return 0;
    }
    // Shift right by (p+1-n) to move the desired bits to the rightmost position
    // then mask the result with (1 << n) - 1 to isolate the last n bits
    return (x >> (p+1-n)) & ((1 << n) - 1);
}

enum escapes {BELL= '\a', BACKSPACE = '\b', TAB='\t',
                NEWLINE = '\n', VTAB='\v', RETURN = '\r'};

const double e = 2.718281;
const char msg[] = "warning: ";

// int strlen(const char[]);

#include <stdio.h> /* only needed for the printf() in main(). */
#include <string.h>

/* Create a string of binary digits based on the input value.
   Input:
       val:  value to convert.
       buff: buffer to write to must be >= sz+1 chars.
       sz:   size of buffer.
   Returns address of string or NULL if not enough space provided.
*/
static char *binrep (unsigned int val, char *buff, int sz) {
    char *pbuff = buff;

    /* Must be able to store one character at least. */
    if (sz < 1) return NULL;

    /* Special case for zero to ensure some output. */
    if (val == 0) {
        *pbuff++ = '0';
        *pbuff = '\0';
        return buff;
    }

    /* Work from the end of the buffer back. */
    pbuff += sz;
    *pbuff-- = '\0';

    /* For each bit (going backwards) store character. */
    while (val != 0) {
        if (sz-- == 0) return NULL;
        *pbuff-- = ((val & 1) == 1) ? '1' : '0';

        /* Get next bit. */
        val >>= 1;
    }
    return pbuff+1;
}

void copy(void);

int main()
{
    int len;
    extern int max;
    extern char longest[];
    max = 0;
    const int SZ = 32;
    char buff[SZ+1];
    int x = 123, p = 3, n = 5;
    printf("%d is leap year\n", 1996);
    printf("%d\n",(1996>>1));
    printf("%s\n", binrep(7, buff, SZ));
    printf("%d is %s\n", x, binrep(x, buff, SZ));
    printf("~%d is %s\n", x, binrep(~x^x, buff, SZ));
    printf("Getbits %d bits of %d, from postion %d, is %s\n", n, x, p, binrep(getbits(x, n, p), buff, SZ));
    return 0;
}