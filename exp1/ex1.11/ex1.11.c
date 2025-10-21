#include<stdio.h>
#include<ctype.h>

int main()
{
	int c,nw,nl,nc,state;
	
	int space;

	
	nw =0;
	nl=0;
	nc=0;

	while((c=getchar()) != EOF)
	{
		nc++;
		if(c=='\n')
			nl++;
		else if(isspace(c) )
		{
			space=1;
		}
		else
		{
			if(space)
			{
				nw++;
			}
			space=0;
		}
	}
	printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
	return 0;
}

