#include<stdio.h>

int main()
{
	int lower, upper, step;
	float F,C;

	lower =0;
	step=20;
	upper=300;

	printf("Fahrenheit      Celsius\n"); 
     	
	F=upper;
	while(F>=lower)
	{
		C=(5.0/9.0)*(F-32.0);
		printf("%10.0f      %8.1f\n",F,C);
		F=F-step;
	}
	return 0;
}



