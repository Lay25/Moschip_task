#include <stdio.h>

int getline_custom(char *s, int lim) 
{
    	int c;
	char *start = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;
	if (c == '\n')
		*s++ = c;
	*s = '\0';
       	return s - start;
}

int atoi_custom(const char *s) 
{
    	int n = 0, sign = 1;
     	while (*s == ' ' || *s == '\t')
	     	s++;
	if (*s == '+' || *s == '-') 
	{
		sign = (*s == '-') ? -1 : 1;
		s++;
	}
    	while (*s >= '0' && *s <= '9')
	    	n = 10 * n + (*s++ - '0');
       	return sign * n;
}

void reverse_custom(char *s) 
{
    	char *end = s, temp;
	while (*end)
		end++;
    	end--;
	while (s < end) 
	{
		temp = *s;
		*s++ = *end;
	       	*end-- = temp;
    }
}

void itoa_custom(int n, char *s) 
{
    	char *p = s;
    	int sign = n;
	if (n < 0)
		n = -n;
       	do 
	{
	  	*p++ = n % 10 + '0';
	}
       	while ((n /= 10) > 0);
	if (sign < 0)
		*p++ = '-';
    	*p = '\0';
	reverse_custom(s);
}

int main() 
{
    	char line[100];
	int len = getline_custom(line, 100);
      	printf("%d: %s\n", len, line);

     	printf("%d\n", atoi_custom(" -1234 "));

    	char numstr[20];
    	itoa_custom(-5678, numstr);
    	printf("%s\n", numstr);

       	char word[] = "pointer";
    	reverse_custom(word);
    	printf("%s\n", word);

    	return 0;
}

