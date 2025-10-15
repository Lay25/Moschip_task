#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100   // maximum stack depth
#define MAXOP 100    // max size of operand or operator

int sp = 0;          // stack pointer
double val[MAXVAL];  // value stack

/* push: push f onto stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* get next operator or numeric operand */
int getop(char s[]);

/* main calculator loop */
int main(void)
{
    char s[MAXOP];
    double op2;
    int type;

    printf("Enter RPN expression (numbers and operators separated by space, Ctrl+D to end):\n");

    while ((type = getop(s)) != EOF) {
        if (type == '0') {  // number
            push(atof(s));
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
                    if (sp > 0)
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

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i = 0, c;

    // skip whitespace
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF) return EOF;

    s[0] = c;
    s[1] = '\0';

    // not a number
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    // handle negative numbers
    if (c == '-') {
        int next = getchar();
        if (!isdigit(next) && next != '.') {
            ungetc(next, stdin);
            return c;  // minus operator
        }
        c = next;
        s[++i] = c;
    }

    // integer part
    while (isdigit(s[++i] = c = getchar()))
        ;

    // fractional part
    if (c == '.') {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetc(c, stdin);

    return '0';  // signal a number
}
