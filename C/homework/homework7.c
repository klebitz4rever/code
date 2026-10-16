#include <stdio.h>
int main()
{
    int day;
    scanf("%d", &day);
    int a = day % 5;

    if (a > 3 || a == 0)
        printf("Drying in day %d", day);
    else
        printf("Fishing in day %d", day);
    return 0;
}