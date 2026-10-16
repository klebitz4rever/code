#include <stdio.h>
int main()
{
    int centimeter;
    printf("请输入厘米单位制下身高： ");
    scanf("%d", &centimeter);
    
    int foot = centimeter / 30.48;
    int inch = (centimeter/30.48 - foot) * 12;
    printf("%d %d", foot, inch);
    return 0;
}