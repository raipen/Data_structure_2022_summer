//정상 작동함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int row, col;
    int i, j;
    int **arr;
    scanf("%d %d", &row, &col);
    arr = (int**)malloc(sizeof(int*) * row);
    for(i=0;i<row;i++)
        arr[i] = (int*)malloc(sizeof(int) * col);
    for (i = 0;i < row;i++) {
        for (j = 0;j < col;j++) {
            arr[i][j] = pow(i, 2) + pow(j, 2);
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    for (i = 0;i < row;i++)
        free(arr[i]);
    free(arr);
}
