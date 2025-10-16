#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK 100

double stack[MAX_STACK];
int sp = 0;

void push(double value) {
    if (sp < MAX_STACK) {
        stack[sp++] = value;
    } else {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

double pop() {
    if (sp > 0) {
        return stack[--sp];
    } else {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: No expression provided\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        char *endptr;
        double value = strtod(arg, &endptr);

        if (*endptr == '\0') {
            push(value);
        } else {
            if (strcmp(arg, "+") == 0) {
                if (sp >= 2) {
                    double b = pop();
                    double a = pop();
                    push(a + b);
                } else {
                    printf("Error: Not enough operands for +\n");
                    return 1;
                }
            } else if (strcmp(arg, "-") == 0) {
                if (sp >= 2) {
                    double b = pop();
                    double a = pop();
                    push(a - b);
                } else {
                    printf("Error: Not enough operands for -\n");
                    return 1;
                }
            } else if (strcmp(arg, "*") == 0) {
                if (sp >= 2) {
                    double b = pop();
                    double a = pop();
                    push(a * b);
                } else {
                    printf("Error: Not enough operands for *\n");
                    return 1;
                }
            } else if (strcmp(arg, "/") == 0) {
                if (sp >= 2) {
                    double b = pop();
                    double a = pop();
                    if (b != 0) {
                        push(a / b);
                    } else {
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                } else {
                    printf("Error: Not enough operands for /\n");
                    return 1;
                }
            } else {
                printf("Error: Unknown operator '%s'\n", arg);
                return 1;
            }
        }
    }

    if (sp == 1) {
        printf("%f\n", stack[0]);
        return 0;
    } else if (sp > 1) {
        printf("Error: Too many operands left on the stack\n");
        return 1;
    } else {
        printf("Error: No result to evaluate\n");
        return 1;
    }
}

