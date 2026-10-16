#include <stdio.h>
int main()
{
    int x;
    double y;
    scanf("%d", &x);
    if ( x > 15 ){
        y = x * 2.5 - 17.5;
    }
    else{
        y = 4 * x / 3.0;
    }
    printf("%.2lf", y);
    return 0;
}