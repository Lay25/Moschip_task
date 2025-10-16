#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define DEFAULT_START 0
#define DEFAULT_TAB 8

int main(int argc, char *argv[]) {
    int m = DEFAULT_START;
    int n = DEFAULT_TAB;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') m = atoi(argv[i]+1);
        else if (argv[i][0] == '+') n = atoi(argv[i]+1);
    }

    int c, col = 0, space_count = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            if ((col + 1 - m) % n == 0 && col + 1 >= m) {
                putchar('\t');
                space_count = 0;
            }
            col++;
        } else {
            for (; space_count > 0; space_count--) putchar(' ');
            putchar(c);
            if (c == '\n') col = 0;
            else col++;
        }
    }

    return 0;
}

