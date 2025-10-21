#include<stdio.h>

#define MAXLINE 100

int get_line(char line[],int maxline);

int main()
{
	int len;
	int max=0;
	char line[MAXLINE];
	char longest[MAXLINE];

	while((len =get_line(line,MAXLINE))>0)
	{
		if(len> max)
		{
			max =len;
			int i;
			for (i = 0; i < MAXLINE - 1 && line[i] != '\0'; i++)
				longest[i] = line[i];
			longest[i] = '\0';
		}
	}
	printf("Longest line length: %d\n", max);
	printf("Text: %s\n", longest);
	return 0;
}

int get_line(char s[],int lim)
{
        int c,i,j;

        for(i=0,j=0;(c=getchar()) != EOF && c !='\n'; i++)
        {
                if(j<lim-1)
                {
                        s[j++]=c;
                }
        }
        if(c=='\n')
        {
                if(j<lim-1)
                {
                        s[j++]=c;
                }
                i++;
        }
        s[j]='\0';
        return i;
}
