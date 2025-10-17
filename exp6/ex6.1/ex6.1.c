#include <stdio.h>
#include <ctype.h>

#define MAXWORD 100

int getword(char *word, int lim);
int getch(void);
void ungetch(int);

char buf[100];
int bufp = 0;

int main() 
{
    	char word[MAXWORD];
    	while (getword(word, MAXWORD) != EOF) 
	{
		printf("%s\n", word);
    	}
    	return 0;
}

int getword(char *word, int lim) 
{
    	int c;
    	char *w = word;
	
    	while ((c = getch()) != EOF && isspace(c))
		;

    	if (c == EOF)
		return EOF;
    	*w++ = c;
	
    	if (c == '_' || isalpha(c)) 
	{
		while (--lim > 0 && (isalnum(c = getch()) || c == '_'))
	    		*w++ = c;
		if (c != EOF)
	    		ungetch(c);
    	}
       	else if (c == '"') 
	{
		while (--lim > 0 && (c = getch()) != EOF) 
		{
	    		*w++ = c;
	    		if (c == '"')
				break;
	    		if (c == '\\' && --lim > 0) 
			{    
		    		c = getch();
				*w++ = c;
	    		}
		}
    	}
       	else if (c == '\'') 
	{
		while (--lim > 0 && (c = getch()) != EOF) 
		{
	    		*w++ = c;
	    		if (c == '\'')
				break;
	    		if (c == '\\' && --lim > 0) 
			{
				c = getch();
				*w++ = c;
	    		}
		}
    	}
       	else if (c == '/') 
	{
		int next = getch();
		if (next == '/') 
		{
	    		*w++ = next;
	    		while (--lim > 0 && (c = getch()) != EOF && c != '\n')
				*w++ = c;
		}
	       	else if (next == '*') 
		{ 
	     		*w++ = next;
	    		int prev = 0;
	    		while (--lim > 0 && (c = getch()) != EOF) 
			{
				*w++ = c;
				if (prev == '*' && c == '/')
		    			break;
				prev = c;
	    		}
		}
	       	else
	       	{
	    		ungetch(next);
		}
     	}
       	else if (c == '#') 
	{
		while (--lim > 0 && (c = getch()) != EOF && c != '\n')
	    		*w++ = c;
    	}

    	*w = '\0';
    	return word[0];
}

int getch(void) 
{
    	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    	if (bufp < sizeof(buf))
		buf[bufp++] = c;
}

