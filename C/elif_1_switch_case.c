#include <stdio.h>
int main()
{
    int type;
    scanf("%d", &type);
    switch ( type )
    {
        case 1:
            printf("现在是早上。");
            break;
        case 2:
            printf("现在是下午。");
            break;
        case 3:
            printf("现在是晚上。");
            break;
        case 4:
            printf("现在是半夜。");
            break;
        default:
            printf("你是不是搞错什么？");
    }
    return 0;
}