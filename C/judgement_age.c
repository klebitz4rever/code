#include <stdio.h>
int main()
{
    const int minor = 35;
    int age = -1;

    printf("请输入你的年龄： ");
    scanf("%d", &age);

    printf("你的年龄为%d岁。\n", age);

    if ( age < minor )
    {
        printf("我还年轻不想死\n哦不对我不是DOOM SLAYER\n");
    }
    printf("不！我就是DOOM SLAYER！");
    return 0;
    
}