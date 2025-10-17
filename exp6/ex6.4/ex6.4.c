#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

void to_lower(char *str) {
    for (; *str; str++) *str = tolower((unsigned char)*str);
}

struct tnode *addtree(struct tnode *p, char *w);
void tree_to_array(struct tnode *p, struct tnode **array, int *index);
int count_nodes(struct tnode *p);
int getword(char *word, int lim);
int getch(void);
void ungetch(int c);
struct tnode *talloc(void);
char *strdup_(char *s);
void tfree(struct tnode *p);

int compare(const void *a, const void *b) {
    struct tnode *nodeA = *(struct tnode **)a;
    struct tnode *nodeB = *(struct tnode **)b;
    if (nodeB->count != nodeA->count) return nodeB->count - nodeA->count;
    return strcmp(nodeA->word, nodeB->word);
}

int bufp = 0;
char buf[100];

int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];
    int c;
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (strlen(word) > 0) {
            to_lower(word);
            root = addtree(root, word);
        }
    }
    if (root != NULL) {
        int num_nodes = count_nodes(root);
        struct tnode **array = malloc(num_nodes * sizeof(struct tnode *));
        if (array == NULL) exit(EXIT_FAILURE);
        int index = 0;
        tree_to_array(root, array, &index);
        qsort(array, num_nodes, sizeof(struct tnode *), compare);
        for (int i = 0; i < num_nodes; i++) {
            printf("%d %s\n", array[i]->count, array[i]->word);
        }
        free(array);
    }
    tfree(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup_(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void tree_to_array(struct tnode *p, struct tnode **array, int *index) {
    if (p != NULL) {
        tree_to_array(p->left, array, index);
        array[*index] = p;
        (*index)++;
        tree_to_array(p->right, array, index);
    }
}

int count_nodes(struct tnode *p) {
    if (p == NULL) return 0;
    return 1 + count_nodes(p->left) + count_nodes(p->right);
}

struct tnode *talloc(void) {
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *strdup_(char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL) strcpy(p, s);
    return p;
}

void tfree(struct tnode *p) {
    if (p != NULL) {
        tfree(p->left);
        tfree(p->right);
        free(p->word);
        free(p);
    }
}

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while ((c = getch()) != EOF && !isalnum(c) && c != '_') {
        if (c == '/') {
            int d = getch();
            if (d == '*') {
                int prev = 0;
                while ((c = getch()) != EOF) {
                    if (prev == '*' && c == '/') break;
                    prev = c;
                }
            } else ungetch(d);
        } else if (c == '"') {
            while ((c = getch()) != EOF && c != '"') {
                if (c == '\\') getch();
            }
        }
    }
    if (c == EOF) {
        *word = '\0';
        return EOF;
    }
    if (isalnum(c) || c == '_') {
        *w++ = c;
        for (; --lim > 1; w++) {
            c = getch();
            if (!isalnum(c) && c != '_') {
                ungetch(c);
                break;
            }
            *w++ = c;
        }
        *w = '\0';
        return word[0];
    }
    *word = '\0';
    return c;
}

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < 100) buf[bufp++] = c;
}

