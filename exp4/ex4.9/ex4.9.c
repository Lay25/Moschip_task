#include<stdio.h>
#include<string.h>

#define BUFSIZE 100
int bufp =0;
char buf[BUFSIZE];

int getch(void)
{
	return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
	if(c==EOF)
	{
		return ;
	}
	if (bufp>=BUFSIZE)
	{
		printf("ungetch: too many character.\n");
	}
	else
	{
		buf[bufp++]=c;
	}

}

int main()
{
	int c;
	printf("enter the few charachter:\n");

	while((c=getch())!= EOF)
	{
		if (c == 'x')
	       	{
			printf("Pushing back 'x'...\n");
                        ungetch(c);
                }
                else if (c == 'e')
                {
			printf("Trying to push back EOF...\n");
                        ungetch(EOF);
	        }
		else
		{
			putchar(c);
		}
	}
	printf("End of the input\n");
	return 0;
}



