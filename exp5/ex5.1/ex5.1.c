#include <stdio.h>
#include <ctype.h>  

#define BUFSIZE 100 

char buf[BUFSIZE];  
int bufp = 0;       


void ungetch(int c) 
{
	if (bufp >= BUFSIZE) 
	{
		printf("ungetch: too many characters\n");
	}
       	else 
	{
		buf[bufp++] = c;  
	}
}


int getch(void) 
{
	return (bufp > 0) ? buf[--bufp] : getchar();  
}


int getint(int *pn) 
{
    	int c, sign;


	while (isspace(c = getch()))
		;
    
	if (!isdigit(c) && c != '+' && c != '-' && c != EOF) 
	{
		ungetch(c);  
		return 0;    
	}

	sign = 1;
	if (c == '+' || c == '-') 
	{
		sign = (c == '-') ? -1 : 1;
		c = getch();  
		if(!isdigit)
		{
			ungetch(c);
			if (c != EOF) 
			{
				ungetch((sign == 1) ? '+' : '-');  
	     		}
			*pn = 0;  
			return 0; 
		}
      	}

	for (*pn = 0; isdigit(c); c = getch()) 
	{
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;  

    	if (c != EOF) 
	{
		ungetch(c);  
	}

    	return c; 
}

int main(void) 
{
    	int num;
	int result;

    	printf("Enter an integer: ");
	result = getint(&num);  

	if (result != 0 || num != 0) 
	{  
		printf("The integer read is: %d\n", num);
	}
	else 
	{
			printf("No valid integer was entered.\n");		
	}
	
    	return 0;
}
