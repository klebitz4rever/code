#include <stdio.h>
int main()
{
    int type;

    scanf("%d", &type);

    if ( type == 1 )
        printf("现在是早上。");
    else if ( type == 2 )
        printf("现在是下午。");
    else if ( type == 3 )
        printf("现在是晚上。");
    else if ( type == 4 )
        printf("现在是半夜。");
    else
        printf("你是不是搞错什么？");
        
    return 0;
}