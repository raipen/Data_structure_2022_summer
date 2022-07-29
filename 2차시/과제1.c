#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
교수님은 테스트 하실 때 in.txt 값을 임의로 바꿔서 실행하심
즉, 항상 값이 9개라는 보장이 없음
fscanf의 리턴이 EOF일때까지==feof의 리턴이 0일때까지 입력받은 숫자의 개수를 tail로 사용해야함
교수님 뿐만 아니라 대부분의 코딩테스트에서도 마찬가지이므로 항상 다양한 입력을 고려해서 코딩하는 습관 들이는게 좋아
*/

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
