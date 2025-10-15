#include <stdio.h>

int buf = 0;      
int buf_full = 0; 

int getch(void)
{
    if (buf_full) {
        buf_full = 0;     
        return buf;
    } else {
        return getchar(); 
    }
}

void ungetch(int c)
{
    if (buf_full)
        printf("ungetch: too many characters\n");
    else {
        buf = c;
        buf_full = 1;     
    }
}

int main(void)
{
    int c;

    c = getchar();    
    printf("Read: %c\n", c);

    ungetch(c);       
    printf("Pushed back: %c\n", c);

    printf("Next getch() will return: %c\n", getch());

    return 0;
}

