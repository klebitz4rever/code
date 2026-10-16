#include <stdio.h>
int main()
{
    //初始化
    int price = 0;
    int cash = 0;
    //交互内容
    printf("请输入金额：");
    scanf("%d", &price);
    printf("请输入票面：");
    scanf("%d", &cash);
    //执行判断
    if ( cash >= price )
    {
        printf("找零： %d\n", cash - price);
    }
    else
    {
        printf("钱不够");
    }
    return 0;
}