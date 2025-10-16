#include<stdio.h>

void str_cat(char *s,char *t)
{
	char *start =s;
	while(*s !='\0')
		s++;

       *s=' ';
       s++;      

	while( *t != '\0')
	{
		*s=*t;
		s++;
		t++;
	}
}

void main()
{
	char s1[100],s2[100];
	printf("enter the string1:");
	scanf("%[^\n]",s1);
	getchar();
	printf("enter the string2:");
        scanf("%[^\n]",s2);

	str_cat(s1,s2);
	printf("concatenated string:%s\n",s1);
}




