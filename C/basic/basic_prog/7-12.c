#include <stdio.h>
int main()
{
    int a, b;
    char c;
    scanf("%d %c %d", &a, &c, &b);
    
    if ( c == '+' || c == '-' || c == '*' || c == '/' || c == '%' )
        switch (c)
        {
        case '+':
            printf("%d", a + b);
            break;
        case '-':
            printf("%d", a - b);
            break;
        case '*':
            printf("%d", a * b);
            break;
        case '/':
            if (b == 0)
            {
                printf("ERROR");
            }
            else
            {
                printf("%d", a / b);
            }
            break;
        case '%':
            if (b == 0)
            {
                printf("ERROR");
            }
            else
            {
                printf("%d", a % b);
            }
        default:
            break;
    }
    else
    {
        printf("ERROR");
        return 0;
    }
    return 0;
}