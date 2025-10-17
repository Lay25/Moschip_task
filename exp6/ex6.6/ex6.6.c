#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
#define HASHSIZE 101

struct nlist {
    char *name;
    char *defn;
    struct nlist *next;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(*np));
        np->name = strdup(name);
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free(np->defn);
    }
    np->defn = strdup(defn);
    return np;
}

void undef(char *name) {
    unsigned h = hash(name);
    struct nlist *np = hashtab[h];
    struct nlist *prev = NULL;
    while (np) {
        if (strcmp(np->name, name) == 0) {
            if (prev) prev->next = np->next;
            else hashtab[h] = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            return;
        }
        prev = np;
        np = np->next;
    }
}

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while ((c = getchar()) != EOF && isspace(c)) putchar(c);
    if (c == EOF) return EOF;

    if (isalpha(c) || c == '_') {
        *w++ = c;
        for (; --lim > 0; w++) {
            c = getchar();
            if (!isalnum(c) && c != '_') {
                ungetc(c, stdin);
                break;
            }
            *w++ = c;
        }
        *w = '\0';
        return word[0];
    }

    *w++ = c;
    *w = '\0';
    return c;
}

int main() {
    char word[MAXWORD], name[MAXWORD], defn[MAXWORD];
    int c;
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (strcmp(word, "#define") == 0) {
            getword(name, MAXWORD);
            getword(defn, MAXWORD);
            install(name, defn);
        } else if (strcmp(word, "#undef") == 0) {
            getword(name, MAXWORD);
            undef(name);
        } else if (isalpha(word[0]) || word[0] == '_') {
            struct nlist *np = lookup(word);
            if (np) printf("%s", np->defn);
            else printf("%s", word);
        } else {
            printf("%s", word);
        }
    }
    return 0;
}

