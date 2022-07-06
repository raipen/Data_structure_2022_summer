#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n,s=0,i;
	

	scanf("%d", &n);

	int* arr1 = (int*)malloc(sizeof(int) * n);
	int* arr2 = (int*)malloc(sizeof(int) * n);
	int*sum = (int*)malloc(sizeof(int) * n);
	
	
	srand(s);
	for (i = 0; i < n; i++) {
		arr1[i] = (rand() % 20);
	}
	for (i = 0; i < n; i++) {
		arr2[i] = (rand() % 20);
	}
	for (i = 0; i < n; i++) {
		sum[i] = arr1[i] + arr2[i];
	}

	for (i = 0; i < n; i++) {
		printf("%d ", arr1[i]);
	}
	printf("\n");

	for (i = 0; i < n; i++) {
		printf("%d ", arr2[i]);
		}
	printf("\n");

	for (i = 0; i < n; i++) {
		printf("%d ", sum[i]);
	}
	printf("\n");

	free(arr1);
	free(arr2);
	free(sum);



}
