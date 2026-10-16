#include <stdio.h>
#include <math.h>
int main()
{
    int x;
    printf("输入判断数字x：");
    scanf("%d", &x);
    int i = 2;
    int limit = (int)sqrt((double)x);

    if ( x < 2 )
    {
        printf("数字%d不为质数", x);
        return 0;
    }
    

    while ( x % i != 0 && i <= limit )
    {
        i++;
    }
    
    if ( i > limit )
        printf("数字%d为质数", x);
    else
        printf("数字%d不为质数", x);

    return 0;
}