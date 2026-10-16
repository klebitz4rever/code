#include <stdio.h>

int main()
{
    int n = 0, m = 0, l = 0, k = 0, roll = 0;
    int min = 1, t = 0, sum = 0, sum1 = 0;
    scanf("%d", &n);
    m = n;
    while (m > 1)   // built the minimum for n digit
    {
        min *= 10;
        m--;
    }
    t = min;
    while (t < 10 * min)   // all the number for n digit
    {
        roll = t;
        m = n;
        sum = 1;
        while (m > 0)
        {
            sum = sum * (roll % 10);
            m--;
        }
        l = n;
        while (l > 0)
        {
            roll = roll / 10;
            k = roll % 10;
            m = n;
            sum1 = 1;
            while (m > 0)
            {
                sum1 = sum1 * k;
                m--;
            }
            sum = sum + sum1;
            l--;
        }
        if (t == sum)
        {
            printf("%d\n", t);
        }
        t++;
    }
    return 0;
}