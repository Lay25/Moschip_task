#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXVAL 100   // maximum stack depth
#define MAXOP 100    // max size of operand or operator

int sp = 0;          // stack pointer
double val[MAXVAL];  // value stack

/* push: push f onto stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: return top element without popping */
double peek(void) {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* duplicate top element */
void duplicate(void) {
    if (sp > 0)
        push(val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* swap top two elements */
void swap(void) {
    if (sp >= 2) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else
        printf("error: not enough elements to swap\n");
}

/* clear the stack */
void clear(void) {
    sp = 0;
}

/* get next operator or numeric operand */
int getop(char s[]) {
    int i = 0, c;

    // skip whitespace
    while ((c = getchar()) == ' ' || c == '\t')
        ;

    if (c == EOF) return EOF;

    s[0] = c;
    s[1] = '\0';

    // operator (not number)
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    // handle negative numbers
    if (c == '-') {
        int next = getchar();
        if (!isdigit(next) && next != '.') {
            ungetc(next, stdin);
            return '-'; // minus operator
        }
        c = next;
        s[++i] = c;
    }

    // integer part
    while (isdigit(s[++i] = c = getchar()))
        ;

    // fraction part
    if (c == '.') {
        while (isdigit(s[++i] = c = getchar()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetc(c, stdin);

    return '0'; // signal number
}

/* main RPN calculator loop */
int main(void) {
    char s[MAXOP];
    double op2;
    int type;

    printf("Enter RPN expression (Ctrl+D to end):\n");

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
                case '?':  // print top
                    printf("top: %.8g\n", peek());
                    break;
                case 'd':  // duplicate top
                    duplicate();
                    break;
                case 's':  // swap top two
                    swap();
                    break;
                case 'c':  // clear stack
                    clear();
                    break;
                case '\n': // print top of stack
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
