#include<stdio.h>

int FtoC(float f)
{
	return (5.0/9.0)*(f-32.0);
}

int main()
{
	int lower, upper, step;
	float F,C;

	lower =0;
	step=20;
	upper=300;

	printf("Fahrenheit      Celsius\n"); 
     	
	F=lower;
	while(F<=upper)
	{
		C=FtoC(F);
		printf("%10.0f      %8.1f\n",F,C);
		F=F+step;
	}
	return 0;
}
