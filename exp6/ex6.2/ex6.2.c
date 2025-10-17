#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define DEFAULTPREFIX 6
#define BUFSIZE 100

struct tnode {
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

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

int getword(char *word, int lim);
struct tnode *addtree(struct tnode *p, char *w, int num, int *found);
void treeprint(struct tnode *p, int num);
int compare(char *s, char *t, int num);

int main(int argc, char *argv[]) {
    struct tnode *root = NULL;
    char word[MAXWORD];
    int num = DEFAULTPREFIX;
    int found;

    if (argc == 2)
        num = atoi(argv[1]);

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) || word[0] == '_') {
            found = 0;
            root = addtree(root, word, num, &found);
        }
    }

    treeprint(root, num);
    return 0;
}

struct tnode *talloc(void);
char *strdup_(char *s);

struct tnode *addtree(struct tnode *p, char *w, int num, int *found) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup_(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        ;
    else if (compare(w, p->word, num))
        p->match = p->right ? 1 : 1;
    else if (cond < 0)
        p->left = addtree(p->left, w, num, found);
    else
        p->right = addtree(p->right, w, num, found);
    return p;
}

void treeprint(struct tnode *p, int num) {
    if (p != NULL) {
        treeprint(p->left, num);
        if (p->match)
            printf("%s\n", p->word);
        treeprint(p->right, num);
    }
}

int compare(char *s, char *t, int num) {
    int i = 0;
    for (; *s == *t; s++, t++, i++)
        if (*s == '\0')
            return 0;
    return i >= num;
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_(char *s) {
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *word, int lim) {
    int c, d;
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_') {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
    } else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c)
                break;
    } else if (c == '/') {
        if ((d = getch()) == '*') {
            while ((c = getch()) != EOF)
                if (c == '*' && (c = getch()) == '/')
                    break;
        } else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

