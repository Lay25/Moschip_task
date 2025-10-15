#include <stdio.h>
#include <stdlib.h>   
#include <ctype.h>    
#include <string.h>   

#define MAXLINE 1000  
#define MAXVAL 100    

int getop(char s[]);
void push(double);
double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXLINE];
    char line[MAXLINE];

    while (fgets(line, MAXLINE, stdin) != NULL)  
    {
        int pos = 0;
        while ((type = getop_from_line(s, line, &pos)) != '\0')  
        {
            switch (type)
            {
            case '0':  
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}



int sp = 0;          
double val[MAXVAL];   

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}


int getop_from_line(char s[], char line[], int *pos)
{
    int i = 0;
    char c;

    
    while ((c = line[*pos]) == ' ' || c == '\t')
        (*pos)++;

    if (c == '\0')
        return '\0'; 

    s[0] = c;
    s[1] = '\0';
    (*pos)++;

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = line[*pos]))
            (*pos)++;
    if (c == '.')
        while (isdigit(s[++i] = c = line[*pos]))
            (*pos)++;
    s[i] = '\0';
    return '0';  
}

