#include <stdio.h>

// 定义这个宏就显示提示，注释掉就不显示
//#define LOCAL_DEBUG 

int main()
{
    int ori;
    
#ifdef LOCAL_DEBUG
    printf("输入： ");
#endif

    scanf("%d", &ori);
    int b = ori / 16 * 10;
    int a = ori % 16;
    int rez =  a + b;
    printf("%d", rez);
    return 0;
}