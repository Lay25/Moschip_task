#include<stdio.h>

#define ALLOCSIZE 10000
#define MAXYEAR 10000

static char daytab[2][13] = {
	{ 0,31,28,31,30,31,30,31,31,30,31,30,31 },
        { 0,31,29,31,30,31,30,31,31,30,31,30,31 }
};

int day_of_year(int year, int month,int day)
{
	if (year < 1 || year > MAXYEAR)
		return -1;
    	if (month < 1 || month > 12)
		return -1;

	int leap;
	char *p;

	leap=((year % 4 == 0 && year % 100 !=0) || year % 400 ==0);
	p= *(daytab+leap);

	while(--month)
		day += *++p;

	return day;
}

int month_day(int year, int yearday, int *pmonth,int *pday)
{
	if (pmonth == NULL || pday == NULL)
		return -1;
    	if (year < 1 || year > MAXYEAR) 
	{
		*pmonth = *pday = 0;
		return -1;
    	}

	int leap;
	char *p;
	
	leap=((year % 4 == 0 && year % 100 !=0) || year % 400 ==0);
	p = *(daytab+leap);

	while(yearday> *++p)
		yearday -= *p;

	*pmonth=p-*(daytab+leap);
	*pday=yearday;
	
	return 0;
}

int main()
{
	int d, m, day;

   	d = day_of_year(2004,2 , 25);

	if (d == -1) printf("Invalid date\n");
    	else printf("2004-05-25 is day %d\n", d);

	if (month_day(2004,225, &m, &day) == 0)
		printf(" 2004 day 225 is %d/%d\n", m, day);
    	else
	    	printf("Invalid yearday for 2004\n");
    	return 0;

}
