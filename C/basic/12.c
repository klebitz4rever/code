#include <stdio.h>

int even( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);
    
    return 0;
}

int even( int n ){
    float temp = n / 2;
    int temp_2 = temp;
    if (temp_2 * 2 == n){
        return 1;
    }
    return 0;
}