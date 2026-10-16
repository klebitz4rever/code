#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    double res = 1;

    for( ;n > 0; n-- )
    {
        res *= n;
    }
    printf("%lf", res);
    return 0;
}