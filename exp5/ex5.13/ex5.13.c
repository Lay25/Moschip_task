#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 10000
#define MAXLEN 1000

char *alloc(int n);
int readlines(char **lineptr, int maxlines);
void writelines(char **lineptr, int nlines, int n);

char *lineptr[MAXLINES];
static char allocbuf[MAXLINES * MAXLEN];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + sizeof(allocbuf) - allocp >= n)
    {
        char *p = allocp;
        allocp += n;
        return p;
    } else
        return NULL;
}

int readlines(char **lineptr, int maxlines) {
    int nlines = 0;
    char line[MAXLEN];
    while (fgets(line, MAXLEN, stdin) != NULL) {
        int len = strlen(line);
        char *p = alloc(len + 1);
        if (p == NULL || nlines >= maxlines) return -1;
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char **lineptr, int nlines, int n) {
    int start = nlines > n ? nlines - n : 0;
    for (int i = start; i < nlines; i++)
        fputs(lineptr[i], stdout);
}

int main(int argc, char *argv[]) {
    int n = 10;
    if (argc == 2 && argv[1][0] == '-') {
        n = atoi(argv[1] + 1);
        if (n <= 0) n = 10;
    }

    int nlines = readlines(lineptr, MAXLINES);
    if (nlines < 0) {
        printf("input too big to process\n");
        return 1;
    }
    writelines(lineptr, nlines, n);
    return 0;
}

