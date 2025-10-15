#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>    
#include <string.h>  

#define MAXVAL 100   
#define MAXOP 100    
#define VARNUM 26    

int sp = 0;          
double val[MAXVAL];  
double variables[VARNUM];  
double last_printed = 0.0; 


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
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


int getop(char s[]);


int main(void)
{
    char s[MAXOP];
    double op2;
    int type;

    printf("Enter RPN expression (supports numbers, operators, functions (sin/exp/pow/last), variables (a-z to push, sa-sz to store), Ctrl+D to end):\n");

    while ((type = getop(s)) != EOF) {
        if (type == '0') {  
            push(atof(s));
        } else if (type == 'f') {  
            if (strlen(s) == 1 && islower(s[0])) {
                
                push(variables[s[0] - 'a']);
            } else if (s[0] == 's' && strlen(s) == 2 && islower(s[1])) {
                
                double temp = pop();
                variables[s[1] - 'a'] = temp;
            } else if (strcmp(s, "last") == 0) {
                
                push(last_printed);
            } else if (strcmp(s, "sin") == 0) {
                push(sin(pop()));
            } else if (strcmp(s, "exp") == 0) {
                push(exp(pop()));
            } else if (strcmp(s, "pow") == 0) {
                op2 = pop();
                double base = pop();
                if (base == 0.0 && op2 == 0.0) {
                    push(1.0);
                } else {
                    push(pow(base, op2));
                }
            } else {
                printf("error: unknown function/command %s\n", s);
            }
        } else {
            switch (type) {
                case '+': push(pop() + pop()); break;
                case '*': push(pop() * pop()); break;
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
                case '%':
                    op2 = pop();
                    if ((int)op2 != 0)
                        push((int)pop() % (int)op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '\n':
                    if (sp > 0) {
                        double temp = pop();
                        last_printed = temp;
                        printf("\t%.8g\n", temp);
                    }
                    break;
                default:
                    printf("error: unknown command %s\n", s);
                    break;
            }
        }
    }

    return 0;
}


int getop(char s[])
{
    int i = 0, c;

    
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF) return EOF;

    
    if (c == '\n') {
        s[0] = '\n';
        s[1] = '\0';
        return '\n';
    }

    s[0] = c;
    s[1] = '\0';

    
    if (isdigit(c) || c == '.' || c == '-') {
        
        if (c == '-') {
            int next = getchar();
            if (!isdigit(next) && next != '.') {
                ungetc(next, stdin);
                return c;
            }
            c = next;
            s[++i] = c;
        }

     
        while (isdigit(s[++i] = c = getchar()))
            ;

        if (c == '.') {
            while (isdigit(s[++i] = c = getchar()))
                ;
        }

        s[i] = '\0';

        if (c != EOF)
            ungetc(c, stdin);

        return '0';  
    }

    
    if (isalpha(c)) {
        i = 1;
        while ((c = getchar()) != EOF && !isspace(c)) {
            if (i < MAXOP - 1)
                s[i++] = c;
        }
        s[i] = '\0';
        if (c != EOF)
            ungetc(c, stdin);
        return 'f';  
    }
 
    return c;
}
