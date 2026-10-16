#include <stdio.h>

int main()
{
    int maxNumber; //此案例中maxNumber恒定且没有被用户自行输入
    scanf("%d", &maxNumber);
    int isPrime[maxNumber];
    int i;
    int x;
    for ( i=0; i<maxNumber; i++ ) { //i自0遍历至24
        isPrime[i] = 1; //定义isPrime数组的每个元素为1，表示所有数字都被标记为质数
    }
    for ( x=2; x<maxNumber; x++ ) { //x自2遍历至24
        if ( isPrime[x] ) {
            for ( i=2; i*x<maxNumber; i++ ) { // i自2遍历
                isPrime[i*x] = 0; //标记i*x为非质数
            }
        }
    }
    for ( i=2; i<maxNumber; i++ ) {
        if ( isPrime[i] ) {
            printf("%d\t", i); //打印任何仍然被标记为1以表示为质数的数字，其中\t表示制表符
        }
    }
    printf("\n"); //其中\n表示换行符

    return 0;
}