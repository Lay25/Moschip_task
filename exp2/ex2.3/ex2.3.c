#include <stdio.h>

int hexToInt(const char *hex) {
    int result = 0;
    char ch;
    while ((ch = *hex++) != '\0') {
        int value;
        if (ch >= '0' && ch <= '9')
            value = ch - '0';
        else if (ch >= 'A' && ch <= 'F')
            value = ch - 'A' + 10;
        else if (ch >= 'a' && ch <= 'f')
            value = ch - 'a' + 10;
        else {
            printf("Invalid hex digit: %c\n", ch);
            return -1;
        }
        result = result * 16 + value;
    }
    return result;
}

int main() {
    char hexStr[3];
    printf("Enter hex number: ");
    scanf("%s", hexStr);

    int decimal = hexToInt(hexStr);
    if (decimal != -1)
        printf("Decimal value: %d\n", decimal);

    return 0;
}
