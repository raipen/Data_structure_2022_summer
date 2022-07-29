#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
굿
*/


void main() {
	int** arr;
	int row, col;
	printf("row size : ");
	scanf("%d", &row);
	printf("col size : ");
	scanf("%d", &col);
	arr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		arr[i] = (int*)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++) {
			arr[i][j] = i * i + j * j;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < row; i++) {
		free(arr[i]);
		printf("free arr[%d].\n", i);
	}
	free(arr);
	printf("free arr.");
}
