#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
    
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}

int Count_Digit ( const int N, const int D ){
    int cnt = 0;
    int temp;
    if (N < 0){
        temp = -N;
    }
    else if(N > 0){
        temp = N;
    }
    else{
        return (D == 0) ? 1 : 0;
    }
    while (temp > 1){
        if (temp % 10 == D){
            cnt++;
        }
        temp /= 10;
    }
    return cnt;
}