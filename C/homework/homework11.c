#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int i,j;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= i; j++)
            printf("%d*%d=%d ", j, i, i*j);
        puts("");
    }

    return 0;
}