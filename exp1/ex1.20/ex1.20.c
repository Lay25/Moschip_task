#include<stdio.h>

#define TABSIZE 2

int main()
{
	int c, pos=0;

	while((c=getchar()) != EOF)
	{
		if(c=='\t')
		{
			int spaces = TABSIZE - (pos % TABSIZE);
			for(int i=0;i<spaces;i++)
			{
				putchar(' ');
				pos++;
			}
		}
		else if(c=='\n')
		{
			putchar(c);
			pos=0;
		}
		else
		{
			putchar(c);
			pos++;
		}
	}
	return 0;
}

