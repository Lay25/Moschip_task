#include<stdio.h>
#include<string.h>

int squeeze(char a[], char b[])
{
    int i,j,k,x,y,found;
    k=0;
    x=strlen(a);
    y=strlen(b);

    for (i=0; i<x; i++)
    {
        found=0;
        for(j=0;j<y;j++)
        {

            	if(a[i]==b[j])
            	{
                	found=1;
                	break;
            	}
	    

        }
        if (!found)
        {
            a[k++] = a[i];
        }

    }
    a[k] = '\0';
    
}

int main()
{
    char s1[100],s2[100];
    printf("Enter string s1: ");
    scanf(" %[^\n]", s1);
    printf("Enter string s2: ");
    scanf(" %[^\n]", s2);
    squeeze(s1, s2);
    printf("Result: %s\n", s1);

    return 0;
}
