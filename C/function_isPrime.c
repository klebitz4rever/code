#include <stdio.h>
int isPrime(int i)
{
    int ret = 1;
    int k;
    for( k = 2; k < i-1; k++){
        if ( i % k == 0 ){
            ret = 0;
            break;
        }
    }
    return ret;
}

int main()
{
    int m, n;
    int sum = 0;
    int count = 0;
    int i;

    scanf("%d %d", &m, &n);
    // m = 10, n = 31;
    if ( m==1 ) m=2; 
    for ( i = m; i <= n; i++){
        if ( isPrime(i) ){
            sum += i;
            count++;
        }
    }
    printf("%d %d\n", count, sum);

    return 0;
}