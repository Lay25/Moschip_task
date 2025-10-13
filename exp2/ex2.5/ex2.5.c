#include<stdio.h>
#include<string.h>
int found(char a[],char b[])
{
	int i,j,k,x,y;
	x=strlen(a);
	y=strlen(b);

	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if(a[i]==b[j])
			{
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	char s1[100],s2[100];
	printf("Enter string s1: ");
        scanf(" %[^\n]", s1);  

        printf("Enter string s2: ");
        scanf(" %[^\n]", s2); 
	int pos= found(s1,s2);
	 printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    if(pos==-1)
    {
	    printf("no match found");
    }
    else
    {
	    printf("First matching character at index: %d (s1[%d] = '%c')\n", pos, pos, s1[pos]);
    }
}
