#include <stdio.h>
int main()
{
    int x;
    int sum = 0;
    int count = 0;
    double average = -1;

  
    do {
        scanf("%d", &x);
        if ( x != -1) {
            sum += x;
            count ++;
        }  
    } while (x != -1);    
    average = sum / count * 1.0;
    printf("%f", average);
    return 0;
}