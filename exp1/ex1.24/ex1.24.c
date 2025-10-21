#include <stdio.h>

int main() 
{
    	int c;
    	int paren = 0, brace = 0, bracket = 0;
    	int in_string = 0, in_char = 0;
    	int in_comment = 0;
    	int prev = 0;

    	while ((c = getchar()) != EOF) 
	{
		if (in_comment) {
	    		if (prev == '*' && c == '/') 
			{
				in_comment = 0;
				c = 0;
	    		}
		}
	       	else if (in_string) 
		{
	    		if (c == '"' && prev != '\\') 
				in_string = 0;
		}
	       	else if (in_char) 
		{
	    		if (c == '\'' && prev != '\\') 
				in_char = 0;
		}
	       	else 
		{
	    		if (prev == '/' && c == '*')
		       	{
				in_comment = 1;
				prev = 0;
				continue;
	    		}
	    		if (prev == '/' && c == '/') 
			{
                
				while ((c = getchar()) != EOF && c != '\n')
		    			;
	    		}
		       	else if (c == '"') 
			{
				in_string = 1;
	    		}
		       	else if (c == '\'') 
			{
				in_char = 1;
	    		}
		       	else if (c == '(')
		       	{
				paren++;
	    		}
		       	else if (c == ')') 
			{
				paren--;
	    		} 
			else if (c == '{')
		       	{
				brace++;

	     		}
		       	else if (c == '}') 
			{
				brace--;
	    		} 
			else if (c == '[')
		       	{
				bracket++;
	    		}
		       	else if (c == ']') 
			{
				bracket--;
	    		}
		}

		if (c != '/')
	    		prev = c;
    	}

    	if (paren != 0)
		printf("Unmatched parentheses: %d\n", paren);
    	if (brace != 0)
		printf("Unmatched braces: %d\n", brace);
    	if (bracket != 0)
		printf("Unmatched brackets: %d\n", bracket);
    	if (paren == 0 && brace == 0 && bracket == 0)
		printf("All parentheses, braces, and brackets are matched.\n");

    	return 0;
}

