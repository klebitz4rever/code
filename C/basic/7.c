#include <stdio.h>
#include <math.h>

int IsTheNumber ( const int N );

int main()
{
    int n1, n2, i, cnt;
    
    scanf("%d %d", &n1, &n2);
    cnt = 0;
    for ( i=n1; i<=n2; i++ ) {
        if ( IsTheNumber(i) )
            cnt++;
    }
    printf("cnt = %d\n", cnt);

    return 0;
}

int IsTheNumber ( const int N ){
    int s = (int) sqrt((double)N);
    if (s * s != N)
        return 0;
    
    int digits[10] = {0};
    int temp = N;
    while (temp > 0) {
        int d = temp % 10;
        digits[d]++;
        if (digits[d] >= 2)
            return 1;
        temp /= 10;}

    return 0; 
}