#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
	int n;
	int* d1, * d2;
	printf("Input size : ");
	scanf("%d", &n);
	d1 = (int*)malloc(n * sizeof(int));
	d2 = (int*)malloc(n * sizeof(int));
	srand((unsigned int)time(NULL));
	printf("Array 1: ");
	for (int i = 0; i < n; i++) {
		d1[i] = rand() % 21;
		printf("%d ", d1[i]);
	}
	printf("\nArray 2: ");
	for (int i = 0; i < n; i++) {
		d2[i] = rand() % 21;
		printf("%d ", d2[i]);
	}
	printf("\nresult: ");
	for (int i = 0; i < n; i++) 
		printf("%d ", d1[i] + d2[i]);
	free(d1); free(d2);
}
