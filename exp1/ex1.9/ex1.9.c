#include <stdio.h>

int main() 
{
    	int c, lastc = 0;

    	while ((c = getchar()) != EOF) 
	{
		if (c != ' ' || lastc != ' ')
	    		putchar(c);
		lastc = c;
    	}

    	return 0;
}

