#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int n;
	printf("Input size: ");
	scanf("%d", &n);

	srand(time(NULL));
	int* arr1 = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * n);

	printf("Array1: ");
	for (int i = 0; i < n; i++)
	{
		arr1[i] = (rand() % 20);
		printf("%3d", arr1[i]);
	}

	printf("\nArray2: ");
	for (int i = 0; i < n; i++)
	{
		arr2[i] = (rand() % 20);
		printf("%3d", arr2[i]);
	}

	printf("\nresult: ");
	for (int i = 0; i < n; i++)
		printf("%3d", arr1[i] + arr2[i]);

	free(arr1);
	free(arr2);
}
