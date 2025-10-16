#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_lines(void *v[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *, const char *);
int reversecmp(const char *, const char *);

int numeric = 0;
int reverse = 0;

int main(int argc, char *argv[]) {
    int nlines;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0)
            numeric = 1;
        else if (strcmp(argv[i], "-r") == 0)
            reverse = 1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (numeric) {
            if (reverse)
                qsort_lines((void **)lineptr, 0, nlines - 1, reversecmp);
            else
                qsort_lines((void **)lineptr, 0, nlines - 1, (int (*)(const void*, const void*))numcmp);
        } else {
            if (reverse)
                qsort_lines((void **)lineptr, 0, nlines - 1, reversecmp);
            else
                qsort_lines((void **)lineptr, 0, nlines - 1, (int (*)(const void*, const void*))strcmp);
        }
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[], int maxlines) {
    char line[MAXLEN];
    int nlines = 0;
    char *p;

    while (fgets(line, MAXLEN, stdin) != NULL) {
        if (nlines >= maxlines)
            return -1;
        int len = strlen(line);
        if (line[len-1] == '\n')
            line[len-1] = '\0';
        p = malloc(len);
        if (p == NULL)
            return -1;
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    for (int i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort_lines(void *v[], int left, int right, int (*comp)(const void *, const void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_lines(v, left, last-1, comp);
    qsort_lines(v, last+1, right, comp);
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int numcmp(const char *s1, const char *s2) {
    double v1 = atof(s1), v2 = atof(s2);
    if (v1 < v2) return -1;
    else if (v1 > v2) return 1;
    else return 0;
}

int reversecmp(const char *s1, const char *s2) {
    return -strcmp(s1, s2);
}

