#include <stdio.h>
int main()
{
    int start;
    int during;
    printf("请输入起始时间与经过时间： ");
    scanf("%d %d", &start, &during);

    int hours_start = start / 100;
    int mins_start = start % 100;
    int hours_during = during / 100 + during % 100 / 60;
    int mins_during = during % 100 % 60;
    int mins_end = mins_start + mins_during % 60;
    int hours_end = hours_during + hours_start + mins_end / 60;

    int end = hours_end * 100 + mins_end;
    printf("%d", end);
    return 0;
}