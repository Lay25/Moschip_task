#include<stdio.h>
#include<string.h>

void reverse_str(char c[], int start, int end)
{
	if(start>=end)
		return;

	char temp=c[start];
	c[start]=c[end];
	c[end]=temp;

	reverse_str(c, start+1,end-1);
	
}

int main()
{
	char s1[100];
	printf("enter the string that need to be reverse:");
	scanf("%[^\n]", s1);
	
	reverse_str(s1, 0, strlen(s1)-1);
	printf("\n Reverse string : %s\n",s1);
	return 0;
}
