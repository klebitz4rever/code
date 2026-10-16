#include <stdio.h>
int main()
{
    printf("请输入a与b的值： ");
    int a, b;
    scanf("%d %d",&a, &b);
    int tempora;

    tempora = a;
    a = b;
    b = tempora;
    printf("a=%d, b=%d\n", a,b);
    return 0;
}