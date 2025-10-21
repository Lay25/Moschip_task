#include<stdio.h>

#define MAXLINE 100
#define LIMIT 80

int get_line(char line[],int maxline);

int main()
{
	int len;
	int found=0;
	char line[MAXLINE];
	
	while((len =get_line(line,MAXLINE))>0)
	{
		if(len> LIMIT)
		{
			printf("%s",line);
			found =1;
		}
	}
	if(!found)
		printf("No line contains 80 characters.\n");
	return 0;
}

int get_line(char s[],int lim)
{
        int c,i;

        for(i=0;i<lim-1 && (c=getchar()) != EOF && c !='\n'; i++)
		s[i]=c;

	if(c== '\n')
	{
		s[i]=c;
		i++;
	}
        s[i]='\0';
        return i;
}

