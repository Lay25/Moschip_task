#include<stdio.h>

unsigned rightrot(unsigned x, int n)
{
	unsigned mask= (((1U << n)-1) & x) << (8-n);
	unsigned m= x >> n;
	return  mask + m;	
}

int main() 
{
    unsigned x = 0b10110010; 
    int n;
    printf("enter the no of bit you want to rotate");
    scanf("%d",&n);

    unsigned result = rightrot(x, n);

    printf("x      = 0b");
    for (int i = 7; i >= 0; i--)
    {
	    printf("%d", (x >> i) & 1);
    }
    printf("\nresult = 0b");
    for (int i = 7; i >= 0; i--) 
    {
	    printf("%d", (result >> i) & 1);
    }
    printf("\nDecimal result: %u\n", result);

    return 0;
}

