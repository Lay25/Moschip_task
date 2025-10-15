#include<stdio.h>
#include<string.h>

void itoa_re(int a, char c[])
{
	static int i=0;
	if(a<0)
	{
		c[i++]='-';
		a=-a;
	}
	if(a/10)
	{
		itoa_re(a/10,c);
	}
	c[i++]=a % 10 + '0';
	c[i]='\0';
}

int main()
{
	char s1[100];
	int num;

	printf("enter the number:");
	scanf("%d",&num);

	itoa_re(num,s1);

	printf("\n string: %s\n",s1);
       
	return 0;
}
