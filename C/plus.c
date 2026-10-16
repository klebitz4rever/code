#include <stdio.h>

int main() 
{
    int a;
    int b;

    printf("Enter two Integers: ");
    scanf("%d %d", &a, &b); 
    printf("%d + %d = %d\n", a, b, a + b);

    return 0;
}