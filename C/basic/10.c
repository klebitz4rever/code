#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
    
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

void Print_Factorial ( const int N ){
    if ( N == 0 ){
        printf("1\n");
        return;
    }
    else if ( N < 0 ){
        printf("Invalid input");
        return;
    }
    long long temp = 1;
    for ( int i = 1; i <= N; i++ ){
        temp *= i;
    }
    printf("%lld\n", temp);
}