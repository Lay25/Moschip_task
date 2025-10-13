#include<stdio.h>

int invert(unsigned x,int p,int n)
{

	unsigned mask= ((1U << n)-1) << (p+1-n);
	return x^ mask;
}

int main()
{

	unsigned x = 0b10101010; 
        int p = 5;
        int n = 3;
	unsigned result = invert(x, p, n);
	printf("x = 0b");
	for(int i=7;i>=0;i--)
	{
		 printf("%d", (x >> i) & 1);
	}
	printf("\nresult = 0b");
	for(int i=7;i>=0;i--)
        {
                 printf("%d", (result >> i) & 1);
        }
	printf("\nDecimal result: %u\n", result);
	return 0;
}
