#include<stdio.h>

#define swap(t,x,y)  { t _temp=(x); (x) = (y); (y) = _temp; }

int main()
{
	int a=10,b=5;
	float p=3.5,q=4.5;
	char c='L',d='K';
        printf("Before swap: a = %d, b = %d\n", a, b);
        swap(int, a, b);
        printf("After swap:  a = %d, b = %d\n\n", a, b);

        printf("Before swap: p = %.2f, q = %.2f\n", p, q);
        swap(float, p, q);
        printf("After swap:  p = %.2f, q = %.2f\n\n", p, q);

        printf("Before swap: c = %c, d = %c\n", c, d);
        swap(char, c, d);
        printf("After swap:  c = %c, d = %c\n", c, d);

        return 0;
}
