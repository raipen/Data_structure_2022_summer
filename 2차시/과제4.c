#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int row, col;

	printf("row size :");
	scanf("%d", &row);
	printf("col size :");
	scanf("%d", &col);

	int** arr;
	arr = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		*(arr + i) = (int*)malloc(sizeof(int) * col);
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			arr[i][j] = i * i + j * j;
			printf("%4d", arr[i][j]);
		}
		puts("");
	}

	for (int i = 0; i < row; i++) {
		free(arr[i]);
		printf("free arr[%d].\n",i);
	}
	free(arr);
	printf("free arr.\n");
}
