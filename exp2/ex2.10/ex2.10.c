#include<stdio.h>
#include<string.h>

int lower( char a[])
{
	int i,j,x;
	x =strlen(a);
	for(i=0;i<x;i++)
	{
		a[i]=(a[i] >= 'A' && a[i] <= 'Z')? (a[i] +'a' -'A'): a[i];
	}
	
}

int main()
{
	char s1[100];
	printf("enter the string");
	scanf("%[^\n]",s1);
	lower(s1);
	printf("Converted string: %s \n",s1);
	return 0;

}
