#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
 이중for문으로 하는 전치로 구현되어있다. 반드시 시간내서 fast transpose algorithm을 구현할 것
*/

int main()
{
	FILE* f;
	int row, col, non;
	int r, c, v;

	if ((f = fopen("m1.txt", "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	fscanf(f, "%d %d %d", &row, &col, &non);

	printf("Before Transposing\n");

	int** mat;
	mat = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++)
		*(mat + i) = (int*)malloc(sizeof(int) * col);
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			mat[i][j] = 0;
	}

	for (int i = 0; i < non; i++)
	{
		fscanf(f, "%d %d %d", &r, &c, &v);
		mat[r][c] = v;
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			printf("%3d ", mat[i][j]);
		printf("\n");
	}

	printf("\nAfter Transposing\n");

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			printf("%3d ", mat[j][i]);
		printf("\n");
	}

	for (int i = 0; i < row; i++)
		free(mat[i]);
	free(mat);

}
