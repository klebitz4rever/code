#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i, j, k;
    int count = 0;

    i = a;
    while ( i <= a + 3 ){
        j = a;
        while ( j <= a + 3 ){
            k = a;
            while ( k <= a + 3 ){
                 if ( i != j ){
                    if( i != k ){
                        if ( j != k ){
                            count++;
                            printf("%d%d%d",i ,j ,k);
                            if ( count == 6 ){
                                printf("\n");
                                count = 0;
                            } else {
                                printf(" ");
                            }
                        }
                    }
                 }
                k++;
            }
            j++;
        }
        i++;
    }
    return 0;
}