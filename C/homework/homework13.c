#include <stdio.h>
int main()
{
    double a = 2, b = 1, t,s = 0;
    int i;
    int n = 1;
    scanf("%d", &n);

    for ( i = 1; i <= n; ++i )
    {
        t = a;
        s += a/b;
        a += b;
        b = t;
    }
    printf("%.2lf", s);

    return 0;
}