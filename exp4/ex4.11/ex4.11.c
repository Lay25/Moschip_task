#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100

double val[MAXVAL];
int sp=0;

void push(double f)
{
	if(sp<MAXVAL)
	{
		val[sp++]=f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if (sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	static int buf = 0;
	int c, i =0;

	if (buf !=0)
	{
		c = buf;
		buf = 0;
	}
	else
	{
		c=getchar();
	}
	while (c ==' ' || c =='\t')
	{
		c =getchar();
	}
	if(c==EOF) return EOF;
	s[0]=c;
	s[1]='\0';
	if (isdigit(c) || c == '.' || c == '-' || c == '+') 
	{
		int sign = 1;
                i = 0;
                if (c == '-' || c == '+') 
		{
			int next = getchar();
                        if (!isdigit(next) && next != '.') 
			{
				buf = next;
                                return c;
                        }
			sign = (c == '-') ? -1 : 1;
                        c = next;
                }
		s[i++] = c;
                while (isdigit(c = getchar()))
                {
			s[i++] = c;
		}
                if (c == '.')
	       	{
			s[i++] = c;
                        while (isdigit(c = getchar()))
                        {
				s[i++] = c;
                        }
		}
          	s[i] = '\0';
                if (c != EOF)
		{
			 buf = c;
		}
		if (sign == -1)
		{
			char temp[MAXOP];
                        temp[0] = '-';
                        temp[1] = '\0';
                        strcat(temp, s);
                        strcpy(s, temp);
                }
		return NUMBER;
	}
	return c;
}

int main(void)
{
    char s[MAXOP];
    int type;
    double op2;

    printf("Enter RPN expression (Ctrl+D to end):\n");

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
	        if (sp < 2) { printf("error: not enough operands\n"); break; }
                push(pop() + pop());
                break;
            case '*':
	        if (sp < 2) { printf("error: not enough operands\n"); break; }
                push(pop() * pop());
                break;
            case '-':
		if (sp < 2) { printf("error: not enough operands\n"); break; }
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
		if (sp < 2) { printf("error: not enough operands\n"); break; }
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
		if (sp > 0)
			printf("Result: %.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

    return 0;
}

