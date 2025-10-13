#include <stdio.h>

void main()
{
    int i=0,c;
    int lim = 100;
    char s[100];
    while (i<lim-1)
    {
        c= getchar();
        if(c == '\n')
        {
            break;
        }
        if( c == EOF)
        {
            break;
        }
        s[i]=c;
        ++i;
    }
     s[i] = '\0';   // terminate the string

    printf("\nYou entered: %s\n", s);

}