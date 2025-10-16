#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS, ARGUMENTS };

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
int getch(void);
void ungetch(int);
void dcl(void);
void dirdcl(void);

int main() 
{
     	while (gettoken() != EOF) 
	{
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
	    		printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
    	}
    	return 0;
}

void dcl(void) 
{
    	int ns;
    	for (ns = 0; gettoken() == '*'; )
		ns++;
    	dirdcl();
    	while (ns-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void) 
{
    	int type;
    	if (tokentype == '(') 
	{
		dcl();
		if (tokentype != ')')
	    		printf("error: missing )\n");
    	}
       	else if (tokentype == NAME) {
		strcpy(name, token);
	}
       	else 
	{
		printf("error: expected name or (dcl)\n");
    	}
    	while ((type = gettoken()) == PARENS || type == BRACKETS || type == ARGUMENTS) 
	{
		if (type == PARENS)
	    		strcat(out, " function returning");
		else if (type == BRACKETS) 
		{
	    		strcat(out, " array");
	    		strcat(out, token);
	    		strcat(out, " of");
		}
	       	else if (type == ARGUMENTS) 
		{
	    		strcat(out, " function taking ");
	    		strcat(out, token);
	    		strcat(out, " returning");
		}
    	}
}

int gettoken(void) 
{
    	int c;
	char *p = token;
    	while ((c = getch()) == ' ' || c == '\t')
		;
    	if (c == '(') 
	{
		if ((c = getch()) == ')') 
		{
			strcpy(token, "()");
	    		return tokentype = PARENS;
		}
	       	else 
		{
	    		ungetch(c);
	    		int i = 0;
	    		token[i++] = '(';
	    		while ((c = getch()) != ')' && c != EOF)
				token[i++] = c;
	    		token[i++] = ')';
	    		token[i] = '\0';
	    		return tokentype = ARGUMENTS;
		}
    	}
       	else if (c == '[') 
	{
		for (*p++ = c; (*p = getch()) != ']'; )
	    		p++;
		p++;
		*p = '\0';
		return tokentype = BRACKETS;
    	}
       	else if (isalpha(c)) 
	{
		for (*p++ = c; isalnum(c) || c=='_' || c==' '; c = getch())
	    		*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;    
	}
	else 
	{
		return tokentype = c;
    	}
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) 
{
    	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    	if (bufp < BUFSIZE)
		buf[bufp++] = c;
}

