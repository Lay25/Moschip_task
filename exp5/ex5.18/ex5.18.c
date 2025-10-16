#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKEN 100
#define NAME 1
#define PARENS 2
#define BRACKETS 3

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);
void dcl(void);
void dirdcl(void);
int getch(void);
void ungetch(int);
void errmsg(char *);

int main(void)
{
    	while (gettoken() != EOF) 
	{
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
	    		errmsg("syntax error");
		printf("%s: %s %s\n", name, out, datatype);
    	}
    	return 0;
}

void dcl(void)
{
    	int ns;
    	for (ns = 0; gettoken() == '*';)
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
	    		errmsg("error: missing )");
    	}
       	else if (tokentype == NAME)
		strcpy(name, token);
    	else
		errmsg("error: expected name or (dcl)");

    	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
	    		strcat(out, " function returning");
		else 
		{
	    		strcat(out, " array");
	    		strcat(out, token);
	    		strcat(out, " of");
		}
}

int gettoken(void)
{
    	int c, getch(void);
    	void ungetch(int);
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
	    		return tokentype = '(';
		}
    	}
       	else if (c == '[') 
	{
		for (*p++ = c; (*p++ = getch()) != ']'; )
	    		if (*(p - 1) == '\n' || *(p - 1) == EOF) 
			{
				errmsg("error: missing ]");
				break;
	    		}
		*p = '\0';
		return tokentype = BRACKETS;
    	}
       	else if (isalpha(c)) 
	{
		for (*p++ = c; isalnum(c = getch()); )
	    		*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
    	}
       	else
		return tokentype = c;
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
    	if (bufp >= BUFSIZE)
		errmsg("ungetch: too many characters");
    	else
		buf[bufp++] = c;
}

void errmsg(char *s)
{
    	printf("%s\n", s);
    	while (tokentype != '\n' && tokentype != EOF)
		tokentype = gettoken();
}

