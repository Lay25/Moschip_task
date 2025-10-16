#include <stdio.h>
#include <string.h>

#define MAXLEN 1000
#define MAXLINES 1000

int getline_custom(char *s, int lim) 
{
    	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
    	if (c == '\n') 
	{
		s[i] = c;
		i++;
    	}
    	s[i] = '\0';
	return i;
}

int readlines(char (*lines)[MAXLEN], int maxlines) 
{
    	char line[MAXLEN];
    	int len, nlines = 0;
    	while (nlines < maxlines && (len = getline_custom(line, MAXLEN)) > 0) 
	{
		if (len > 0) 
		{
	    		strcpy(*(lines + nlines), line);
	    		nlines++;
		}
    	}
    	return nlines;
}

int main() 
{
    	char lines[MAXLINES][MAXLEN];
    	int nlines;
    	printf("Enter lines (Ctrl+D to end):\n");
    	nlines = readlines(lines, MAXLINES);
    	printf("\nLines read: %d\n", nlines);
    	for (int i = 0; i < nlines; i++)
		printf("Line %d: %s", i + 1, *(lines + i));
    	return 0;
}

