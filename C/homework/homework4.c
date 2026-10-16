#include <stdio.h>
int main()
{
    int convert;
    printf("请输入待转换的三位数： ");
    scanf("%d", &convert);
    int a = convert / 100;
    int b = convert % 100 / 10;
    int c = convert % 10;
    
    int c_a = a;
    int c_b = b * 10;
    int c_c = c * 100;

    int converted = c_c + c_b + c_a;
    printf("%d", converted);
    return 0;
}