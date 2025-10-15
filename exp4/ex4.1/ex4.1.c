#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]);

int main(void)
{
    char s[100] ;
    char t[100] ;

    printf("Enter string s1: ");
    scanf(" %[^\n]", s);
    printf("Enter string s2: ");
    scanf(" %[^\n]", t);

    int pos = strindex(s, t);

    if (pos >= 0)
        printf("Rightmost occurrence of \"%s\" in \"%s\" is at index %d\n", t, s, pos);
    else
        printf("\"%s\" not found in \"%s\"\n", t, s);

    return 0;
}

int strindex(char s[], char t[])
{
    int i, j, k;
    int len_s = strlen(s);
    int len_t = strlen(t);

    for (i = len_s - len_t; i >= 0; i--) {  
        for (j = i, k = 0; k < len_t && s[j] == t[k]; j++, k++)
            ; 
        if (k == len_t)   
		return i;      
    }

    return -1;  
}
		

