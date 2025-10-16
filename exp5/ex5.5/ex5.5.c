#include<stdio.h>
char str_cpy(char *s, char *t, int a)
{

	while (a-- > 0 && *t != '\0')
	{
		*s++= *t++;
	}

	while (a-- > 0 )
	{
		*s++= '\0';
	}
	
	
}

char str_cat(char *s, char *t, int a)
{

	while(*s != '\0')
		s++;

	while ( a-- > 0 && *t != '\0')
	{
		*s++ = *t++;
	}
	*s='\0';

}

char str_cmp(char *s, char *t, int a)
{
	while (a-- > 0 && *s != '\0' && *t != '\0')
	{
		if(*s != *t)
		{
			return (unsigned char)*s - (unsigned char)*t;
		}
		s++;
		t++;
	}
	if (a < 0)
	{
		return 0;
	}
	return (unsigned char)*s - (unsigned char)*t;
}

int main()
{
	char s1[100],s2[100];
	int n;

	printf("enter the string 1:");
	scanf("%[^\n]",s1);
	getchar();
	printf("enter the string 2:");
	scanf("%[^\n]",s2);
	getchar();

	printf("enter the number of character:");
	scanf("%d",&n);
	getchar();

	str_cpy(s1,s2,n);
	printf("After string copy: %s\n", s1);

	printf("enter the string 1:");
        scanf("%[^\n]",s1);
        getchar();
        printf("enter the string 2:");
        scanf("%[^\n]",s2);
        getchar();

	str_cat(s1,s2,n);
        printf("After string concatenated: %s\n", s1);

	printf("enter the string 1:");
        scanf("%[^\n]",s1);
        getchar();
        printf("enter the string 2:");
        scanf("%[^\n]",s2);
        getchar();

        int cmp=str_cmp(s1,s2,n);
	if (cmp < 0)
	{
		printf("strncmp_custom: \"%s\" < \"%s\"\n", s1, s2);
	}
	else if (cmp > 0)
	{
		printf("strncmp_custom: \"%s\" > \"%s\"\n", s1, s2);
	}
	else
	{
		printf("strncmp_custom: \"%s\" == \"%s\" (first %d characters)\n", s1, s2, n);
	}

	return 0;
}




