//정상 작동함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix {
    int row;
    int col;
    int value;
}mat;

void main()
{
    int** matrix;
    int r, c, non;
    int a, b, d;
    int i, j;
    FILE* fp1;
    fp1 = fopen("m1.txt", "r");
    if (fp1 == NULL) {
        printf("error");
        return 0;
    }

    fscanf(fp1, "%d %d %d", &r, &c, &non);

    matrix = (int**)malloc(sizeof(int*) * r);
    for (i = 0;i < r;i++)
        matrix[i] = (int*)malloc(sizeof(int) * c);

    for (i = 0;i < r;i++) {
        for (j = 0;j < c;j++) {
            matrix[i][j] = 0;
        }
    }

    for (i = 0;i < non;i++) {
        fscanf(fp1, "%d %d %d", &a, &b, &d);
        matrix[a][b] = d;
    }
    fclose(fp1);

    for (i = 0;i < r;i++) {
        for (j = 0;j < c;j++) {
            printf("%3d", matrix[j][i]);
        }
        printf("\n");
    }

    for (i = 0;i < r;i++) {
        free(matrix[i]);
    }
    free(matrix);
}
