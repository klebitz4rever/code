#include <stdio.h>
int main()
{
    int a;
    int b;
    int temp;
    scanf("%d %d", &a, &b);

    while ( b!=0 )
    {
        temp = a % b;
        a = b;
        b = temp;
        printf("a=%d, b=%d, temp=%d\n", a, b, temp);
    }
    printf("gcd=%d\n", a);
    return 0;
}