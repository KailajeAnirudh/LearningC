/*Write a function setbits(x,p,n,y) that returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving the other bits unchanged*/
#include <stdio.h>
#define SZ 32
char buff[SZ+1];


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

int main()
{
    int x = 123, y = 5, p = 5, n = 4; 
    printf("%d is %32b\n", x, x);
    printf("%d is %32b\n", y, y);
    printf("getbit(%d, %d, %d) = %b\n", x, p, n, getbits(x, p, n));
    int final_or_with_maskedx = (y&~(~0<<(n)))<<(p-n+1);
    printf("Eventually | with processed x,\n       %32b\n", final_or_with_maskedx);
    int x_lhs_mask = ~0<<(p+1);
    printf("Creating a mask for x,\n       %32b\n", x_lhs_mask);
    int x_rhs_mask = ~(~0<<(p-n+1));
    printf("Create rhs of mask\n");
    printf("rhs mask, %s\n", binrep(x_rhs_mask, buff, SZ));
    int x_full_mask = x_lhs_mask | x_rhs_mask;
    printf("Full mask, %s\n", binrep(x_full_mask, buff, SZ));
    int masked_x = x&x_full_mask;
    printf("Masked x %s\n", binrep(masked_x, buff, SZ));
    printf("Final result: %s\n", binrep(masked_x|final_or_with_maskedx, buff, SZ));
    printf("%b\n", masked_x|final_or_with_maskedx);
    printf("%32b\n", ~(((1<<n)-1)<<(p-n+1)));
    printf("%32b\n", y&((1<<n)-1)<<(p-n+1));
}
