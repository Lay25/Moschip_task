#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];
int numeric = 0;
int reverse = 0;
int fold = 0;
int directory = 0;
int field = 0;

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort_custom(void *v[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int strcmp_fold_dir(const char *, const char *, int fold, int directory);
char *get_field(const char *line, int field);

int main(int argc, char *argv[])
{
    	int nlines;
    	while (--argc > 0 && (*++argv)[0] == '-') 
	{
		switch ((*argv)[1]) 
		{
			case 'n': numeric = 1; break;
			case 'r': reverse = 1; break;
			case 'f': fold = 1; break;
			case 'd': directory = 1; break;
			case 'k': if (argc > 1) { field = atoi(*++argv) - 1; argc--; } break;
			default: break;
		}
    	}

    	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
	{
		qsort_custom((void **)lineptr, 0, nlines - 1,
	   			(int (*)(void *, void *))strcmp_fold_dir);
		writelines(lineptr, nlines);
		return 0;
    	}
       	else 
	{
		printf("input too big to sort\n");
		return 1;
    	}
}

char *get_field(const char *line, int f)
{
    	static char buf[1000];
    	int i = 0, j = 0, cfield = 0;
    	while (line[i] != '\0') 
	{
		if (isspace(line[i])) 
		{
	    		while (isspace(line[i])) i++;
	    		cfield++;
	    		if (cfield > f) break;
		}
	       	else
	       	{
	    		if (cfield == f) buf[j++] = line[i];
	    		i++;
		}
    	}
    	buf[j] = '\0';
    	return buf;
}

int compare(const char *s1, const char *s2)
{
    	char *f1 = get_field(s1, field);
    	char *f2 = get_field(s2, field);
    	int result;
    	if (numeric)
		result = numcmp(f1, f2);
    	else
		result = strcmp_fold_dir(f1, f2, fold, directory);
    	return reverse ? -result : result;
}

void qsort_custom(void *v[], int left, int right, int (*comp)(void *, void *))
{
    	int i, last;
    	void swap(void *v[], int, int);
    	if (left >= right) return;
    	swap(v, left, (left + right) / 2);
    	last = left;
    	for (i = left + 1; i <= right; i++)
		if (compare(v[i], v[left]) < 0)
	    		swap(v, ++last, i);
    	swap(v, left, last);
    	qsort_custom(v, left, last - 1, comp);
    	qsort_custom(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
    	void *temp = v[i];
    	v[i] = v[j];
    	v[j] = temp;
}

int numcmp(const char *s1, const char *s2)
{
    	double v1 = atof(s1), v2 = atof(s2);
    	if (v1 < v2) return -1;
    	else if (v1 > v2) return 1;
    	else return 0;
}

int strcmp_fold_dir(const char *s1, const char *s2, int fold, int directory)
{
    	char a, b;
    	do 
	{
		while (directory && *s1 && !isalnum(*s1) && !isspace(*s1)) s1++;
		while (directory && *s2 && !isalnum(*s2) && !isspace(*s2)) s2++;
		a = fold ? tolower(*s1) : *s1;
		b = fold ? tolower(*s2) : *s2;
		if (a == b) 
		{
	    		if (*s1 == '\0') return 0;
	    		s1++; s2++;
		}
	       	else return a - b;
    	} while (1);
}

int readlines(char *lineptr[], int maxlines)
{
    	int len, nlines = 0;
    	char *p, line[1000];
    	while (fgets(line, sizeof(line), stdin) != NULL) 
	{
		len = strlen(line);
		if (line[len - 1] == '\n') line[len - 1] = '\0';
		if ((p = malloc(len)) == NULL || nlines >= maxlines) return -1;
		strcpy(p, line);

		lineptr[nlines++] = p;
	}
    	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    	for (int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

