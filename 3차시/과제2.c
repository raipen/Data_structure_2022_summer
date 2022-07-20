#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int row;
	int col;
	int val;
}tuple;

void printMatrix(tuple t[]) {
	int arr[100][100] = { 0 };
	for (int i = 1; i <= t[0].val; i++)
		arr[t[i].row][t[i].col] = t[i].val;
	for (int i = 0; i < t[0].row; i++) {
		for (int j = 0; j < t[0].col; j++) 
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

tuple* transpose(tuple t[]) {
	tuple res[50];
	int i, count[50] = { 0 }, idx[50];
	res[0].row = t[0].col;
	res[0].col = t[0].row;
	res[0].val = t[0].val;
	for (i = 1; i <= t[0].val; i++) {
		count[t[i].col]++;
	}
	idx[0] = 1;
	for (i = 1; i <= t[0].val; i++) {
		idx[i] = idx[i - 1] + count[i - 1];
	}
	for (i = 1; i <= t[0].val; i++) {
		res[idx[t[i].col]].row = t[i].col;
		res[idx[t[i].col]].col = t[i].row;
		res[idx[t[i].col]].val = t[i].val;
		idx[t[i].col]++;
	}
	return res;
}

void main() {
	FILE* f1, * f2;
	tuple t1[100], t2[100];
	int i;
	f1 = fopen("m1.txt", "r");
	f2 = fopen("m2.txt", "r");
	fscanf(f1, "%d %d %d", &t1[0].row, &t1[0].col, &t1[0].val);
	fscanf(f2, "%d %d %d", &t2[0].row, &t2[0].col, &t2[0].val);
	for(i = 1; i <= t1[0].val; i++)
		fscanf(f1, "%d %d %d", &t1[i].row, &t1[i].col, &t1[i].val);
	for (i = 1; i <= t2[0].val; i++)
		fscanf(f2, "%d %d %d", &t2[i].row, &t2[i].col, &t2[i].val);
	fclose(f1);
	fclose(f2);

	printMatrix(t2);
	printf("\n");
	printMatrix(transpose(t2));
}
