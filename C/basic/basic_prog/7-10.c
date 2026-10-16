#include <stdio.h>
int main()
{

int years;
int working_hours;
int paying_per_hour;
double paying;
scanf("%d %d", &years, &working_hours);
if( years >= 5 )
    paying_per_hour = 50;
else 
    paying_per_hour = 30;

if( working_hours < 40 )
    paying = working_hours * paying_per_hour;
else
    paying = paying_per_hour * 40 + ( working_hours - 40 ) * paying_per_hour * 1.5;

printf("%.2f", paying);
return 0;
}