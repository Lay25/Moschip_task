#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        if (np == NULL) return NULL;
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

int undef(char *name) {
    unsigned hashval = hash(name);
    struct nlist *np = hashtab[hashval];
    struct nlist *prev = NULL;

    while (np != NULL) {
        if (strcmp(name, np->name) == 0) {
            if (prev == NULL)
                hashtab[hashval] = np->next;
            else
                prev->next = np->next;
            free(np->name);
            free(np->defn);
            free(np);
            return 1;  // Successfully removed
        }
        prev = np;
        np = np->next;
    }
    return 0;  // Name not found
}

int main() {
    install("foo", "123");
    install("bar", "456");

    printf("Before undef:\n");
    struct nlist *np = lookup("foo");
    if (np) printf("%s => %s\n", np->name, np->defn);

    undef("foo");

    printf("After undef:\n");
    np = lookup("foo");
    if (np)
        printf("%s => %s\n", np->name, np->defn);
    else
        printf("foo not found\n");

    return 0;
}

