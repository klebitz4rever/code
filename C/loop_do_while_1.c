#include <stdio.h>
int main()
{
    int x;
    int n = 0;

    scanf("%d", &x);
    do
    {
        x /= 10;
        n += 1;
    }while ( x > 0 );
    printf("%d", n);
    return 0;
}