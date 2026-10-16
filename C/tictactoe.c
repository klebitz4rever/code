#include <stdio.h>
int main()
{
const int size = 3;
int i, j, numOfO, numOfX;
int result = -1;
int board[size][size];
//读入矩阵
for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
        scanf("%d", &board[i][j]);

//检查行
for ( i = 0; i<size && result == -1; i++ ){
    numOfO = numOfX = 0;
    for ( j = 0; j<size; j++ ){
        if ( board[i][j] == 0 )
            numOfO ++;
        else if ( board[i][j] == 1 )
            numOfX ++;
    }
    if (numOfO == size)
        result = 0;
    else if (numOfX == size)
        result = 1;
}

//检查列
if ( result == -1 ){
    for ( j = 0; j<size && result == -1; j++ ){
        numOfO = numOfX = 0;
        for ( i = 0; i<size; i++ ){
            if ( board[i][j] == 0 )
                numOfO ++;
            else if ( board[i][j] == 1 )
                numOfX ++;
        }
        if (numOfO == size)
            result = 0;
        else if (numOfX == size)
            result = 1;
    }
}

//检查正对角线
    if (result == -1) {
        numOfO = numOfX = 0;
        for (i = 0; i < size; i++) {
            if (board[i][i] == 0)
                numOfO ++;
            else if (board[i][i] == 1)
                numOfX ++;
        }
        if (numOfO == size)
            result = 0;
        else if (numOfX == size)
            result = 1;
    }

//检查反对角线
    if (result == -1) {
        numOfO = numOfX = 0;
        for (i = 0; i < size; i++) {
            if (board[i][size - 1 - i] == 0)
                numOfO++;
            else if (board[i][size - 1 - i] == 1)
                numOfX++;
        }
        if (numOfO == size)
            result = 0;
        else if (numOfX == size)
            result = 1;
    }

//输出结果
    printf("%d\n", result);

    return 0;
}