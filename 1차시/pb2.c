#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void addMatrix(int a[], int b[], int c[], int n) {
	for (int i = 0;i < n;i++) {
		c[i] = a[i] + b[i];
	}
}

void printMatrix(int a[],int n){
	for (int i = 0;i < n;i++) {
		fprintf(stdout," %2d", a[i]);
	}
}

void main()
{
	int* arr1, * arr2, * result;
	int size;

	printf("Input size: ");
	fscanf(stdin, "%d", &size);
	arr1 = (int*)malloc(sizeof(int) * size);
	arr2 = (int*)malloc(sizeof(int) * size);
	result = (int*)malloc(sizeof(int) * size);

	for (int i = 0;i < size;i++) {
		*(arr1 + i) = rand() % 21;
		*(arr2 + i) = rand() % 21;
	}
	addMatrix(arr1,arr2,result, size);
	printf(" Array1: ");
	printMatrix(arr1, size);
	printf("\n Array2: ");
	printMatrix(arr2, size);
	printf("\n result: ");
	printMatrix(result, size);
}