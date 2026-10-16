#include <stdio.h>
int main()
{
    int i, j;
    scanf("%d:%d", &i, &j);
    if ( i >= 0 && i < 12)
        printf("%d:%d AM", i, j);
    else if ( 12 < i )
        printf("%d:%d PM", i - 12, j);
    else if ( i == 24 )
        printf("%d:%d PM", i - 24, j);
    else 
        printf("%d:%d PM", i, j);

    return 0;
}