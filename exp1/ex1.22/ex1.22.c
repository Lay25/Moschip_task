#include <stdio.h>

#define MAXCOL 20  

int main(void) 
{
     	int c, i;
    	char line[MAXCOL + 1]; 
    	int pos =0; 
    	int last_blank = -1;  

    	while ((c = getchar()) != EOF) 
	{
		if (c == ' ' || c == '\t')
		{
			line[pos]=' ';
	    		last_blank = pos;
		}
		else
			line[pos]=c;
		pos++;

		if (c == '\n') 
		{
	    		for (i = 0; i < pos; i++)
				putchar(line[i]);
	    		pos = 0;
	    		last_blank = -1;
		}
	       	else if (pos >= MAXCOL) 
		{
	    		int break_pos;

	    		if (last_blank != -1)
				break_pos = last_blank + 1; 
	    		else
		 		break_pos = pos;        

	    		for (i = 0; i < break_pos; i++)
				putchar(line[i]);
	    		putchar('\n');
			
	    		int j;
	    		for (j = break_pos; j < pos; j++)
				line[j - break_pos] = line[j];

	    		pos -= break_pos;
	    		last_blank = -1;

	    		for (i = 0; i < pos; i++)
				if (line[i] == ' ' || line[i] == '\t')
		    			last_blank = i;
		}
    	}

    
    	for (i = 0; i < pos; i++)
        putchar(line[i]);

	return 0;
}

