#include <stdio.h>
#include <ctype.h>

int main() 
{
    	int c, length, max_length, i, j;
    	length = 0;
    	max_length = 0;
    	while ((c = getchar()) != EOF) 
	{
		if (isspace(c)) 
		{
	    		if (length > max_length)
				max_length = length;
	    		length = 0;
		}
	       	else
	       	{
	    		length++;
		}
    	}
    	if (length > max_length)  
		max_length = length;

   
    	int word_lengths[max_length + 1];
    	for (i = 0; i <= max_length; i++)
		word_lengths[i] = 0;


    	freopen(NULL, "r", stdin);

   
    	length = 0;
    	while ((c = getchar()) != EOF) 
	{
		if (isspace(c)) 
		{
	    		if (length > 0)
				word_lengths[length]++;
	    		length = 0;
		}
	       	else
	       	{
	    		length++;
		}
    	}
    	if (length > 0)
		word_lengths[length]++;

    	printf("Word length histogram:\n");
    	for (i = 1; i <= max_length; i++) 
	{
		if (word_lengths[i] > 0) 
		{
	    		printf("%2d: ", i);
	    		for (j = 0; j < word_lengths[i]; j++)
				putchar('*');
	    		printf("\n");
		}
    	}

    	return 0;
}

