#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    int i;
    scanf("%d",&n);

    if ( n < 0 ){
        return 0;
    }
    
    for ( i = 0; i <= n; i++ ){
        int res = pow(3,i);
        printf("pow(3,%d) = %d\n" ,i ,res);
    }

    return 0;
}