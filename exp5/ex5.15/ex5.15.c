#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXLINES 1000
#define MAXLEN 1000

char *lineptr[MAXLINES];
int numeric =0;
int reverse =0;
int fold=0;

int readlines(char *lineptr[],int maxlines);
void writelines(char *lineptr[],int nlines);
void qsort_lines(void *v[], int left, int right, int (*comp)(const void *, const void *));
int numcmp(const char *, const char *);
int strcmp_fold(const char *, const char *);

int main(int argc, char *argv[])
{
	int nlines;

	for(int i=1;i< argc;i++)
	{
		if(strcmp(argv[i],"-n") ==0)
			numeric =1;
		else if(strcmp(argv[i],"-r") ==0)
			reverse =1;
		else if (strcmp(argv[i],"-f") ==0)
			fold =1;
	}

	if ((nlines=readlines(lineptr,MAXLINES)) >=0)
	{

		if(numeric)
			qsort_lines((void **)lineptr, 0, nlines - 1, (int (*)(const void*, const void*))numcmp);
		else if (fold)
			qsort_lines((void **)lineptr, 0, nlines - 1, (int (*)(const void*, const void*))strcmp_fold);
		else
			qsort_lines((void **)lineptr, 0, nlines - 1, (int (*)(const void*, const void*))strcmp);

		if (reverse)
		{
			for(int i=nlines-1;i>=0;i--)
				printf("%s\n",lineptr[i]);
		}
		else
		{
			writelines(lineptr,nlines);
		}
		return 0;
	}
	else
	{
		printf("error: input too big to sort\n");
		return 1;
	}
}

int readlines(char *lineptr[],int maxlines)
{
	char line[MAXLEN];
	int nlines =0;
	char *p;

	while (fgets(line,MAXLEN,stdin)!=NULL)
	{
		if (nlines >= maxlines)
			return -1;
		int len =strlen(line);
		if (line[len - 1] == '\n')
			line[len - 1] == '\0';
		p=malloc(len);
		if (p== NULL)
			return -1;
		strcpy(p,line);
		lineptr[nlines++]=p;
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

void qsort_lines(void *v[], int left, int right, int (*comp)(const void *, const void *))
{
	int i,last;
	void swap(void *[],int,int);
	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v,++last,i);
	swap(v,left,last);
	qsort_lines(v, left, last - 1, comp);
	qsort_lines(v, last + 1, right, comp);
}

void swap(void *v[], int i, int j)
{
	void *temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
int numcmp(const char *s1,const char *s2)
{
	double v1 = atof(s1), v2 = atof(s2);
	if (v1 < v2) return -1;
	else if (v1 > v2) return 1;
	else return 0;
}

int strcmp_fold(const char *s1, const char *s2)
{
	for (; tolower(*s1) == tolower(*s2); s1++, s2++)
		if(*s1=='\0')
			return 0;
	return tolower(*s1)-tolower(*s2);
}





