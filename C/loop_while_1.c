#include <stdio.h>
int main()
{
    int x;
    int n = 0;
    scanf("%d", &x);

    while (x > 0)
    {
        n += 1;
        x /= 10;
    }
    if (x == 0 && n == 0)
    {
        n = 1;
    }
    
    printf("%d", n);

    return 0;
}