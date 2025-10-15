#include <string.h>
#include <stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(const char s[]) {
    int len = strlen(s);
    while (len > 0)
        ungetch(s[--len]);   
}

int main(void) {
    char s[] = "abc";
    ungets(s);

    int c;
    while ((c = getch()) != EOF)
        putchar(c);
    return 0;
}

