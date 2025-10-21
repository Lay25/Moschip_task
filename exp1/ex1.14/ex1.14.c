#include <stdio.h>

#define MAX_CHAR 128

int main() 
{
    	int c;
    	int freq[MAX_CHAR] = {0};
	
    	while ((c = getchar()) != EOF) 
	{
		if (c >= 0 && c < MAX_CHAR)
	    		freq[c]++;
    	}

    	printf("Character frequency histogram:\n");
    	for (int i = 0; i < MAX_CHAR; i++) 
	{
		if (freq[i] > 0) 
		{
	    		if (i == '\n')
				printf("\\n : ");
	    		else if (i == '\t')
				printf("\\t : ");
	    		else if (i == ' ')
				printf("' ' : ");
	    		else
				printf(" %c  : ", i);

	    		for (int j = 0; j < freq[i]; j++)
				putchar('*');
	    		printf("\n");
		}
    	}

    	return 0;
}

