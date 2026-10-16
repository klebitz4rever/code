#include <stdio.h>

int main()
{
    printf("请输入两个整数： ");
    int a,b;
    scanf("%d %d", &a, &b);
    double c = (a+b)/2.0;
    
    printf("%d 和 %d 的平均值为： %f\n", a, b ,c);
}