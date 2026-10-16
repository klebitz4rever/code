#include <stdio.h>

int main() 
{
    int hour1, min1;
    int hour2, min2;

    printf("输入时1与分1： ");
    scanf("%d %d", &hour1, &min1);
    printf("输入时2与分2： ");
    scanf("%d %d", &hour2, &min2);
    int minute1 = min1 + hour1 * 60;
    int minute2 = min2 + hour2 * 60;
    int difference = minute1 - minute2;

    printf("时间差为： %d小时%d分。", difference/60, difference%60);

    return 0;
}
