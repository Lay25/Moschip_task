#include<stdio.h>
#include<ctype.h>
#include<math.h>

double atof(const char s[])
{
	double val = 0.0, power = 1.0;
        int i = 0, sign = 1;

	while(isspace(s[i])) i++;

	if(s[i] == '+') i++;
	else if (s[i] == '-') 
	{
		sign = -1;
		i++;
	}

	while(isdigit(s[i]))
	{
		val= 10* val + (s[i]-'0');
		i++;
	}

	while(s[i] == '.')
	{
		i++;
		while(isdigit(s[i]))
        	{
                	val= 10* val + (s[i]-'0');
			power *= 10.0;
                	i++;
        	}
	}
	val= sign* val/power;


	if(s[i] == 'e' || s[i] =='E')
	{
		i++;
                int exp_sign = 1, exp = 0;
		if (s[i] == '+') i++;
                else if (s[i] == '-')
		{
			exp_sign = -1;
			i++;
		}

		while (isdigit(s[i]))
	       	{
			exp = 10 * exp + (s[i] - '0');
                        i++;
                }

		val *= pow(10, exp_sign * exp);
	}
	return val;
}


int main()
{
    char test1[] = "123.45e-6";
    char test2[] = "-0.5E2";
    char test3[] = "6.02e23";
    char test4[] = "42";

    printf("%s -> %g\n", test1, atof(test1));
    printf("%s -> %g\n", test2, atof(test2));
    printf("%s -> %g\n", test3, atof(test3));
    printf("%s -> %g\n", test4, atof(test4));

    return 0;
}




