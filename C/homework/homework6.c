#include <stdio.h>
int main()
{
    int mph;
    scanf("%d", &mph);

    if (mph > 60)
        printf("Speed:%d - Speeding", mph);
    else
        printf("Speed:%d - OK", mph);
    return 0;
}