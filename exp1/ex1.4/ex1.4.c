#include<stdio.h>

int main()
{
	int lower,step,upper;
	float C,F;

	lower=0;
	step=20;
	upper=300;

	printf(" Celsius        Fahrenheit\n");

	C=lower;
	while(C<=upper)
	{
		F=(9.0/5.0) *C +32.0;
		printf("%8.1f %10.0f\n",C,F);
		C=C+step;
	}
	return 0;
}

