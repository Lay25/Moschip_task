#include<stdio.h>

#define TABSIZE 4

int main(void)
{
	int c, pos = 0, space_count = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			space_count++;
			pos++;
			if(pos% TABSIZE ==0)
			{
				putchar('\t');
				space_count=0;
			}
		}
		else
		{
			while (space_count > 0)
			{
				putchar(' ');
				space_count--;
			}

			putchar(c);

			if(c=='\n')
				pos=0;
			else pos++;
		}
	}
	return 0;
}
