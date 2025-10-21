#include <stdio.h>
#include <ctype.h>

int main()
{
	int c;
	int space=1;

	while((c=getchar()) !=EOF)
	{
		if(isspace(c))
		{
			if(!space)
				putchar('\n');
			space=1;
		}
		else
		{
			putchar(c);
			space=0;
		}
	}
	if(!space)
		putchar('\n');
	return 0;
}

