#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[], int width) {
    int i = 0;
    unsigned int num;
    int sign = n;

    if (n < 0) {
        num = (unsigned int)(-(n + 1)) + 1; 
    } else {
        num = (unsigned int)n;
    }

    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);

    
    int len = strlen(s);
    if (len < width) {
        
        for (int j = len; j >= 0; j--) {
            s[j + (width - len)] = s[j];
        }
        
        for (int j = 0; j < width - len; j++) {
            s[j] = ' ';
        }
    }
}

int main() {
    char str[50];

    itoa(123, str, 10);
    printf("'%s'\n", str);   

    itoa(-12345, str, 10);
    printf("'%s'\n", str);

    itoa(123456789, str, 5); 
    printf("'%s'\n", str);

    itoa(-2147483648, str, 15);
    printf("'%s'\n", str);

    return 0;
}
