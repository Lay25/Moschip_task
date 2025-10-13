#include <stdio.h>


unsigned setbits(unsigned x, int p, int n, unsigned y) 
{
    unsigned mask;

    
    mask = ((1U << n) - 1);   
    mask <<= (p + 1 - n);
    x &= ~mask;
    x |= ((y & ((1U << n) - 1)) << (p + 1 - n));

    return x;
}


int main() {
    unsigned x = 0b10101010;
    unsigned y = 0b1111;
    int n = 3;          
    int p = 5;

    unsigned result = setbits(x, p, n, y);

    printf("x     = 0b");
    for (int i = 7; i >= 0; i--) printf("%d", (x >> i) & 1);
    printf("\ny     = 0b");
    for (int i = 7; i >= 0; i--) printf("%d", (y >> i) & 1);
    printf("\nresult= 0b");
    for (int i = 7; i >= 0; i--) printf("%d", (result >> i) & 1);
    printf("\nDecimal result: %u\n", result);

    return 0;
}

