#include <stdio.h>
int main()
{
    int A,B,C;

    scanf("%d %d %d", &A, &B, &C);

    if( A != B && A == C )
        printf("B");
    else if( A != B && B == C )
        printf("A");
    else if( A == B && A != C )
        printf("C");
    return 0;
}