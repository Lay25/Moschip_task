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

void itob(int n, char s[], int b) {
    int i = 0;
    unsigned int num;
    int sign = n;

    if (n < 0) {
        num = (unsigned int)(-(n + 1)) + 1; // avoid overflow for INT_MIN
    } else {
        num = (unsigned int)n;
    }

    do {
        int digit = num % b;
        if (digit < 10)
            s[i++] = digit + '0';
        else
            s[i++] = digit - 10 + 'A';  // for bases > 10
    } while ((num /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    char str[100];

    itob(255, str, 2);
    printf("255 in base 2  = %s\n", str);

    itob(255, str, 8);
    printf("255 in base 8  = %s\n", str);

    itob(255, str, 16);
    printf("255 in base 16 = %s\n", str);

    itob(-255, str, 16);
    printf("-255 in base 16 = %s\n", str);

    itob(-2147483648, str, 16); // INT_MIN
    printf("INT_MIN in base 16 = %s\n", str);

    return 0;
}
