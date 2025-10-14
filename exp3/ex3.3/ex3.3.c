#include <stdio.h>
#include <ctype.h>

void expand(const char s1[], char s2[]) {
    int i, j;
    char c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] != '\0') {
            
            char start = c;
            char end   = s1[i+1];

            if ((islower(start) && islower(end) && start < end) ||
                (isupper(start) && isupper(end) && start < end) ||
                (isdigit(start) && isdigit(end) && start < end)) {

                for (char k = start; k <= end; k++)
                    s2[j++] = k;
                i += 2; 
                continue;
            } else {
                
                s2[j++] = c;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main() {
    char input1[] = "a-z";
    char input2[] = "A-Z0-9";
    char input3[] = "a-b-c";
    char input4[] = "-a-z-";
    char output[200];

    expand(input1, output);
    printf("Expand \"%s\" -> %s\n", input1, output);

    expand(input2, output);
    printf("Expand \"%s\" -> %s\n", input2, output);

    expand(input3, output);
    printf("Expand \"%s\" -> %s\n", input3, output);

    expand(input4, output);
    printf("Expand \"%s\" -> %s\n", input4, output);

    return 0;
}
