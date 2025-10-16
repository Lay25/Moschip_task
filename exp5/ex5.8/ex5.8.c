#include <stdio.h>

#define ALLOCSIZE 10000
#define MAXYEAR 10000

static char daytab[2][13] = 
{
    	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{

	int i, leap;
    	if (year < 1 || year > MAXYEAR)
		return -1;
    	if (month < 1 || month > 12)
		return -1;
    	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    	if (day < 1 || day > daytab[leap][month])
		return -1;
    	for (i = 1; i < month; i++)
		day += daytab[leap][i];

    	return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
    	int i, leap, maxday;
    	if (pmonth == NULL || pday == NULL)
		return -1;
    	if (year < 1 || year > MAXYEAR) 
	{
		*pmonth = *pday = 0;
		return -1;
    	}
    	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    	maxday = leap ? 366 : 365;
    	if (yearday < 1 || yearday > maxday) 
	{
		*pmonth = *pday = 0;
		return -1;
    	}
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
    	*pmonth = i;
    	*pday = yearday;
    	return 0;
}

int main(void)
{
	int d, m, day;
	
   	d = day_of_year(2025,7 , 22);

	if (d == -1) printf("Invalid date\n");
    	else printf("2025-07-22 is day %d\n", d);    	

	if (month_day(2024,236, &m, &day) == 0)
		printf(" 2024 day 236 is %d/%d\n", m, day);
    	else
	    	printf("Invalid yearday for 2024\n");
    	return 0;
}

