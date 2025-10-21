#include<stdio.h>

#define MAXLINE 1000

int get_line(char line[],int maxline);
void remove_trailing(char line[]);

int main()
{
	char line[MAXLINE];
	int len;

	while((len=get_line(line,MAXLINE)) >0)
	{
		remove_trailing(line);
		if(line[0] !='\0')
			printf("%s\n",line);
	}
	return 0;
}

int get_line(char s[],int lim)
{
	int c,i;
	for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n'; i++)
		s[i]=c;
	s[i]='\0';
	return i;
}

void remove_trailing(char s[])
{
	int i=0,j=0;
	int space_seen=0;

	while(s[i] !='\0')
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (!space_seen)
			{
				s[j++] = ' ';
				space_seen = 1;
			}
		}
		else
		{
			s[j++] = s[i];
			space_seen=0;
		}
		i++;
	}
	
	if(j>0 && s[j-1] ==' ')
		j--;

	s[j] = '\0';
	
}

