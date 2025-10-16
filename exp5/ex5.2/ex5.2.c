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


int getfloat(float *pn) 
{
    	int c, sign;
    	float fraction, power;

    	while (isspace(c = getch()))
	    	;
    
     	if (!isdigit(c) && c != '+' && c != '-' && c != '.' && c != EOF) 
	{
		if (c != EOF) 
		{
		    	ungetch(c);  
		}
	       	return 0; 
    	}

	sign = 1;
       	if (c == '+' || c == '-') 
	{
	       	sign = (c == '-') ? -1 : 1;
	       	c = getch();  
	}

    
    	for (*pn = 0; isdigit(c); c = getch()) 
	{
		*pn = 10 * *pn + (c - '0');
	}

    	if (c=='.')
	{
		c = getch();
		fraction = 0.1f;  
		while (isdigit(c)) 
		{
		      	*pn += (c - '0') * fraction;  
	       		fraction *= 0.1f;
	       		c = getch();
		}
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
    	float num;
    	int result;

	printf("Enter a floating-point number: ");
       	result = getfloat(&num);  
      
	if (result != 0) 
	{   
		printf("The floating-point number read is: %f\n", num);
    	}
       	else 
	{
        printf("No valid floating-point number was entered.\n");
    	}

	return 0;
}
