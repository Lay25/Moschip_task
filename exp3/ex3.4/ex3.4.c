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

void itoa(int n, char s[]) {
    int i = 0;
    unsigned int num;

    if (n < 0) {
        num = (unsigned int)(-(n + 1)) + 1; 
    } else {
        num = (unsigned int)n;
    }

    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    char str[50];

    itoa(12345, str);
    printf("itoa(12345)  = %s\n", str);

    itoa(-12345, str);
    printf("itoa(-12345) = %s\n", str);

    itoa(-2147483648, str); 
    printf("itoa(INT_MIN) = %s\n", str);

    return 0;
}
