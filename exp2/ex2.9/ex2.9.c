#include <stdio.h>

int bitcount(unsigned x)
{
    int count = 0;
    while (x != 0) {
        x &= (x - 1);  	
        count++;
    }
    return count;
}

int main()
{
    unsigned x = 0b10110101;
    printf("Number of 1 bits in %u: %d\n", x, bitcount(x));
    return 0;
}

