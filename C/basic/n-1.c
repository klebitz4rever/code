#include <stdio.h>
#include <math.h> // 必须包含此头文件才能使用 round()

int main()
{
    int centi, foot, inch;
    scanf("%d", &centi);
    double total_feet = centi / 30.48;
    foot = (int)total_feet;
    inch = (int)round((total_feet - foot) * 12);
    
    printf("%d %d\n", foot, inch);
    
    return 0;
}