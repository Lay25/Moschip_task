#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
void qsort_custom(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(const char *, const char *);
int strcmp_fold_dir(const char *, const char *);

int numeric = 0;
int reverse = 0;
int fold = 0;
int directory = 0;

int main(int argc, char *argv[])
{
    	int nlines;
    	int c;
    	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
	    		switch (c) 
			{
		    		case 'n':
					numeric = 1;
					break;
		    		case 'r':
					reverse = 1;
					break;
		    		case 'f':
					fold = 1;
					break;
		    		case 'd':
					directory = 1;
					break;
		    		default:
					printf("sort: illegal option %c\n", c);
					return 1;
	    		}
    	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		qsort_custom((void **) lineptr, 0, nlines-1,
	   			(int (*)(void*,void*))(numeric ? numcmp : strcmp_fold_dir), reverse);
		writelines(lineptr, nlines, reverse);
		return 0;
    	} 
	else 
	{
		printf("input too big to sort\n");
		return 1;
    }
}

void qsort_custom(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
    	int i, last;
    	void swap(void *v[], int, int);
    	if (left >= right)
		return;
    	swap(v, left, (left + right)/2);
    	last = left;
    	for (i = left+1; i <= right; i++)
		if (reverse ? (*comp)(v[i], v[left]) > 0 : (*comp)(v[i], v[left]) < 0)
		    	swap(v, ++last, i);
    	swap(v, left, last);
    	qsort_custom(v, left, last-1, comp, reverse);
    	qsort_custom(v, last+1, right, comp, reverse);
}

void swap(void *v[], int i, int j)
{
    	void *temp;
    	temp = v[i];
    	v[i] = v[j];
    	v[j] = temp;
}

int numcmp(const char *s1, const char *s2)
{
    	double v1, v2;
    	v1 = atof(s1);
    	v2 = atof(s2);
    	if (v1 < v2)
		return -1;
    	else if (v1 > v2)
		return 1;
    	else
		return 0;
}

int strcmp_fold_dir(const char *s1, const char *s2)
{
    	char a, b;
    	do 
	{
		while (directory && *s1 && !isalnum(*s1) && !isspace(*s1))
	    		s1++;
		while (directory && *s2 && !isalnum(*s2) && !isspace(*s2))
	    		s2++;
		a = fold ? tolower(*s1) : *s1;
		b = fold ? tolower(*s2) : *s2;
		if (a == b) 
		{
	    		if (*s1 == '\0')
				return 0;
	    		s1++;
	    		s2++;
		} 
		else
	    		return a - b;
    	} while (1);
}

int readlines(char *lineptr[], int maxlines)
{
    	int len, nlines;
    	char *p, line[1000];
    	nlines = 0;
    	while (fgets(line, sizeof(line), stdin) != NULL) 
	{
		len = strlen(line);
		if (line[len-1] == '\n')
	    		line[len-1] = '\0';
		if ((p = malloc(len)) == NULL || nlines >= maxlines)
	    		return -1;
		strcpy(p, line);
		lineptr[nlines++] = p;
    	}
    	return nlines;
}

void writelines(char *lineptr[], int nlines, int reverse)
{
    	int i;
    	if (reverse)
		for (i = nlines - 1; i >= 0; i--)
	    		printf("%s\n", lineptr[i]);
	else
		for (i = 0; i < nlines; i++)
	    		printf("%s\n", lineptr[i]);
}

