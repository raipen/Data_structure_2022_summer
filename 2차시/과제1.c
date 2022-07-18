#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int iterative(int n, int arr[]) {
	int head = 0, tail = 9;
	while (head <= tail) {
		int mid = (head + tail) / 2;
		if (n == arr[mid]) return 1;
		if (n > arr[mid]) head = mid + 1;
		else tail = mid - 1;
	}
	return 0;
}

int recursive(int n, int arr[], int head, int tail) {
	if (head <= tail) {
		int mid = (head + tail) / 2;
		if (n == arr[mid]) return 1;
		if (n > arr[mid]) return recursive(n, arr, mid + 1, tail);
		else return recursive(n, arr, head, mid - 1);
	}
	return 0;
}

void main() {
	FILE* f = fopen("in.txt", "r");
	int arr[9], n;
	for (int i = 0; i < 9; i++)
		fscanf(f, "%d", &arr[i]);
	fclose(f);
	while (1) {
		printf("Input number : ");
		scanf("%d", &n);
		if (n < 0) break;
		printf("iterative binary search : %s\n", iterative(n, arr) ? "있음" : "없음");
		printf("recursive binary search : %s\n", recursive(n, arr, 0, 9) ? "있음" : "없음");
	}
}
