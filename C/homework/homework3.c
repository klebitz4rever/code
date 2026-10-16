#include <stdio.h>
int main()
{
    int starting;
    int during;
    printf("请输入起始时间和经过时间： ");
    scanf("%d %d", &starting, &during);
    int mins_starting = starting / 100 * 60 + starting % 100;
    int mins_ending = mins_starting + during;

    int ending = mins_ending / 60 * 100 + mins_ending % 60;
    printf("%04d\n", ending);
    return 0;
    
} 