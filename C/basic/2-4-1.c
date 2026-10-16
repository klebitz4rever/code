#include <stdio.h>

int is( int number );//原型声明
void count_sum( int a, int b );//原型声明

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    if (is(a)) printf("%d is counted.\n", a);
    if (is(b)) printf("%d is counted.\n", b);
    count_sum(a, b);

    return 0;
}

int is ( int number )//函数定义
{
    int sum = 0;
    int temp = number;

    while ( temp > 0 ){
        sum += temp % 10;
        temp /= 10;
    }

    if ( sum == 5 ){
        return 1;
    }else{
        return 0;
    }
}




void count_sum( int a, int b )//函数定义
{
    int count = 0;
    int sum = 0;

    for ( int i = a; i <= b; i++){
        if(is(i)){
            count++;
            sum += i;
        }
    }

    printf("count = %d, sum = %d\n", count, sum);
}