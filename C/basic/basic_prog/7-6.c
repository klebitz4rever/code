#include <stdio.h>
int main()
{
    float f1, f2;
    int i1;
    char c1;

    scanf("%f %d %c %f", &f1, &i1, &c1, &f2);
    printf("%c %d %.2f %.2f", c1, i1, f1, f2);
    return 0;
}