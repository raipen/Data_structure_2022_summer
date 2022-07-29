#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
 이중for문으로 하는 전치로 구현되어있다. 반드시 시간내서 fast transpose algorithm을 구현할 것
*/

transpose(FILE *f,int row, int col, int non)
{
	int row1 = 0, col1 = 0;
	int val = 0;
	int i = 0,j=0;

	printf("Before Transosing\n");

	int** p = malloc(sizeof(int*) * row);

	for (i = 0;i < row;i++)
	{
		p[i] = malloc(sizeof(int) * col);
	}

	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			p[i][j] = (int)0;
		}
	}
	for (i = 0;i < non;i++)
	{
		fscanf(f, "%d %d %d", &row1, &col1, &val);
		p[row1][col1] = val;
	}
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
	printf("After Transposing\n");
	for (int i = 0;i < col;i++)
	{
		for (int j = 0;j < row;j++)
		{
			printf("%d ", p[j][i]);
		}
		printf("\n");
	}
}

void main()
{
	FILE* fp;
	FILE* fp1;
	int row = 0, col = 0, non = 0;
	int row1 = 0, col1 = 0, non1 = 0;
	fp = fopen("m1.txt", "r");
	if (fp == NULL) {
		printf("cannot find the file");
		return 0;
	}
	fp1 = fopen("m2.txt", "r");
	if (fp1 == NULL) {
		printf("cannot find the file");
		return 0;
	}
	fscanf(fp, "%d %d %d", &row, &col, &non);
	transpose(fp,row, col, non);
	printf("\n");
	fscanf(fp1, "%d %d %d", &row1, &col1, &non1);
	transpose(fp1,row1, col1, non1);

	fclose(fp);
	fclose(fp1);
}
