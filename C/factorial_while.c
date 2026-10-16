#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int x = 1;
    int result = 1;

    while ( x <= n )
    {
        result *= x;
        x++;
    }
    printf("%d", result);
    return 0;
}