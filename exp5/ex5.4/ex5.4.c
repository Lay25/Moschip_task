#include<stdio.h>


int strend(char *s, char *t)
{
	int s_len=0,t_len=0;

	while(*s !='\0')
	{
		s++;
		s_len++;
	}

	while(*t !='\0')
	{
		t++;
                t_len++;
	}

	if(s_len < t_len)
		return 0;

	s += (s_len - t_len);

	while(*s && *t !='\0')
	{
		if( *s != *t)
		{
			return 0;
		}
		s++;
		t++;
	}
	return 1;
}

int main()
{
	char s[100], t[100];
    	printf("Enter string s: ");
	scanf("%[^\n]", s);
	getchar(); 
      	printf("Enter string t: ");
       	scanf("%[^\n]", t);

        if(strend(s,t))
	{
		printf(" \"%s\" occurs at the end of \"%s\".\n", t, s);
	}
	else
		printf(" \"%s\"  doesn't occurs at the end of \"%s\".\n", t, s);

    	return 0;
}
