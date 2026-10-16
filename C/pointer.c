#include <stdio.h>

// 函数声明
void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    // 1. 初始化数组
    int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min, max;

    // 2. 调用函数，传入数组名（首地址）、数组长度，以及min和max的地址
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    
    // 3. 打印结果
    printf("min=%d,max=%d\n", min, max);

    return 0;
}

// 函数定义：查找数组中的最大值和最小值
void minmax(int a[], int len, int *min, int *max)
{
    int i;
    // 4. 初始将最小值和最大值设为数组的第一个元素
    *min = *max = a[0];

    // 5. 遍历数组查找最大最小值
    for (i = 1; i < len; i++) {
        if (a[i] < *min) {  // 如果当前元素比当前最小值小
            *min = a[i];    // 更新最小值
        }
        if (a[i] > *max) {  // 如果当前元素比当前最大值大
            *max = a[i];    // 更新最大值
        }
    }
}