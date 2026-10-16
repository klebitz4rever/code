#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int x = -1;
    int a = rand()%100+1;
    int count = 0;

    while ( x != a )
    {
    count++;
    scanf("%d", &x);
    if ( x > a )
        printf("猜大了。\n");
    else if ( x < a )    
        printf("猜小了。\n");
    else 
        printf("猜中。\n");
    }
printf("你总共猜了%d次。", count);
return 0;
}