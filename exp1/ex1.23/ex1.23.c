#include <stdio.h>

int main() 
{
    	int c, d;
    	int in_string = 0;
    	int in_char = 0;

    	while ((c = getchar()) != EOF) 
	{
		if (in_string) 
		{
	    		putchar(c);
	    		if (c == '\\') 
			{
				if ((d = getchar()) != EOF) 
				{
					putchar(d);
				}
	    		}
		       	else if (c == '"')
		       	{
				in_string = 0;
	    		}
		}
	       	else if (in_char) 
		{
	    		putchar(c);
	    		if (c == '\\') 
			{  
				if ((d = getchar()) != EOF) 
				{
		    			putchar(d);
				}
	    		} 
			else if (c == '\'') 
			{
				in_char = 0;
	    		}
		}
	       	else
	       	{
	    		if (c == '"') 
			{
				in_string = 1;
				putchar(c);
	    		}
		       	else if (c == '\'') 
			{
				in_char = 1;
				putchar(c);
	    		}
		       	else if (c == '/') 
			{
				d = getchar();
				if (d == '/') 
				{ 
		    			while ((c = getchar()) != EOF && c != '\n')
						;
		    			if (c == '\n')
						putchar('\n');
				}
			       	else if (d == '*') 
				{
		    			int prev = 0;
		    			while ((c = getchar()) != EOF) 
					{
						if (prev == '*' && c == '/')
			    				break;
						prev = c;
		    			}
				}
			       	else
			       	{
		    			putchar(c);
		    			if (d != EOF)
						putchar(d);
				}
	    		}
		       	else
		       	{
				putchar(c);
	    		}
		}
    	}

    	return 0;
}

