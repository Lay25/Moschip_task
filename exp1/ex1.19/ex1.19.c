#include<stdio.h>

#define MAXLINE 1000

int get_line(char line[],int maxline);
void rev(char line[]);

int main()
{
	char line[MAXLINE];
	

	while((get_line(line,MAXLINE)) >0)
	{
		rev(line);
		printf("%s",line);
	}
	return 0;
}

int get_line(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n'; i++)
		s[i]=c;
	if(c=='\n')
	{
		s[i]=c;
		i++;
	}
	s[i]='\0';
	return i;
}

void rev(char s[])
{
	int i,j;
	char temp;
	for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i)
		;
	j = i - 1;

	for (int k = 0; k < j - k; ++k)
	{
		temp =s[k];
		s[k]=s[j-k];
		s[j-k]=temp;
	}
}
