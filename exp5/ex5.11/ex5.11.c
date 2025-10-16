#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 1000
#define DEFAULT_TAB 8

int tabstops[100];
int n_tabs = 0;

int next_tab(int col) {
    if (n_tabs == 0) 
        return col + (DEFAULT_TAB - col % DEFAULT_TAB);
    for (int i = 0; i < n_tabs; i++)
        if (tabstops[i] > col)
            return tabstops[i];
    return col + 1; 
}

void entab_line(char *line) {
    int i = 0, col = 0;
    while (line[i]) {
        if (line[i] == ' ') {
            int start = i;
            int next = next_tab(col);
            while (line[i] == ' ' && col < next) {
                i++;
                col++;
            }
            int n_spaces = i - start;
            int n_tabs = 0;
            int pos = col - n_spaces;
            while (pos < col && next_tab(pos) <= col) {
                n_tabs++;
                pos = next_tab(pos);
            }
            for (int t = 0; t < n_tabs; t++)
                putchar('\t');
            for (int s = 0; s < col - start - n_tabs * DEFAULT_TAB; s++)
                putchar(' ');
        } else {
            putchar(line[i]);
            if (line[i] == '\n')
                col = 0;
            else
                col++;
            i++;
        }
    }
}

void detab_line(char *line) {
    int col = 0;
    for (int i = 0; line[i]; i++) {
        if (line[i] == '\t') {
            int n = next_tab(col) - col;
            for (int j = 0; j < n; j++)
                putchar(' ');
            col += n;
        } else {
            putchar(line[i]);
            if (line[i] == '\n')
                col = 0;
            else
                col++;
        }
    }
}

int main(int argc, char *argv[]) {
       if (argc > 1) {
        for (int i = 1; i < argc && i <= 100; i++)
            tabstops[n_tabs++] = atoi(argv[i]);
    }

    char line[MAXLINE];
    while (fgets(line, MAXLINE, stdin) != NULL) {
        entab_line(line);
        
    }
    return 0;
}

