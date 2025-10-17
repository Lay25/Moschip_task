#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MAXLINES 100

struct tnode {
    char *word;
    int lines[MAXLINES];
    int count;
    struct tnode *left;
    struct tnode *right;
};

char *noise_words[] = {
    "a", "an", "and", "are", "in", "is", "it",
    "of", "on", "or", "that", "the", "this", "to", NULL
};

int bufp = 0;
char buf[100];

void to_lower(char *str) 
{
    	for (; *str; str++) *str = tolower((unsigned char)*str);
}

int noise(char *w) 
{
    	for (int i = 0; noise_words[i] != NULL; i++)
		if (strcmp(w, noise_words[i]) == 0)
	    		return 1;
    	return 0;
}

struct tnode *addtree(struct tnode *p, char *w, int linenum) 
{
    	int cond;
    	if (p == NULL) 
	{
		p = malloc(sizeof(struct tnode));
		p->word = malloc(strlen(w) + 1);
		strcpy(p->word, w);
		p->lines[0] = linenum;
		p->count = 1;
		p->left = p->right = NULL;
    	}
       	else if ((cond = strcmp(w, p->word)) == 0) 
	{
		if (p->lines[p->count - 1] != linenum && p->count < MAXLINES)
		    	p->lines[p->count++] = linenum;
    	}
       	else if (cond < 0)
		p->left = addtree(p->left, w, linenum);
    	else
		p->right = addtree(p->right, w, linenum);
    	return p;
}

void treeprint(struct tnode *p) 
{
    	if (p != NULL) 
	{
		treeprint(p->left);
		printf("%-15s ", p->word);
		for (int i = 0; i < p->count; i++)
	    		printf("%d ", p->lines[i]);
		printf("\n");
		treeprint(p->right);
    	}
}

int getch(void) 
{
    	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) 
{
    	if (bufp < 100)
		buf[bufp++] = c;
}

int getword(char *word, int lim, int *linenum) 
{
    	int c;
    	char *w = word;
    	while (1) 
	{
		while ((c = getch()) != EOF && isspace(c)) 
		{
	    		if (c == '\n') (*linenum)++;
		}
		if (c == EOF) 
		{
	    		*word = '\0';
	    		return EOF;
		}
		if (isalpha(c) || c == '_') 
		{
	    		*w++ = c;
	    		for (; --lim > 1; w++) 
			{
				if (!isalnum(*w = getch()) && *w != '_') 
				{
		    			ungetch(*w);
		    			break;
				}
	    		}
	    		*w = '\0';
	    		return word[0];
		} 
		else if (c == '/') 
		{
	    		if ((c = getch()) == '*') 
			{
				int prev = 0;
				while ((c = getch()) != EOF) 
				{
		    			if (c == '\n') (*linenum)++;
		    			if (prev == '*' && c == '/') break;
		    			prev = c;
				}
	    		}
		       	else
		       	{
				ungetch(c);
	    		}
		}
	       	else if (c == '"') 
		{
	    		while ((c = getch()) != EOF && c != '"') 
			{
				if (c == '\\') getch();
				if (c == '\n') (*linenum)++;
	    		}
		}
    	}
}

void tfree(struct tnode *p) 
{
    	if (p != NULL) 
	{
		tfree(p->left);
		tfree(p->right);
		free(p->word);
		free(p);
    	}
}

int main() 
{
    	struct tnode *root = NULL;
    	char word[MAXWORD];
    	int linenum = 1;
    	int c;

    	while ((c = getword(word, MAXWORD, &linenum)) != EOF) 
	{
		to_lower(word);
		if (isalpha(word[0]) && !noise(word) && strlen(word) > 0)
	    		root = addtree(root, word, linenum);
    	}
    	treeprint(root);
    	tfree(root);
    	return 0;
}

