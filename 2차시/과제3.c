#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
O(n^2)보다 좋은 시간 복잡도로 푼 사람은 두번째임. 아주 잘했음
첫번째 배열에 존재하는 값이 두번째 배열에 존재하는지 BS로 찾기 때문에
O(n*log(n))의 시간복잡도를 가짐

근데 이미 두 배열이 모두 내림차순으로 "정렬"되어 있다는 것을 이용하면 O(n)으로 구현 가능
한번 해보면 좋을 듯
*/

int isSame(int n, int arr[], int head, int tail) {
	while (head <= tail) {
		int mid = (head + tail) / 2;
		if (n == arr[mid]) return 1;
		if (n < arr[mid]) head = mid + 1;
		else tail = mid - 1;
	}
	return 0;
}

void main() {
	FILE* f1 = fopen("in1.txt", "r"), * f2 = fopen("in2.txt", "r");
	int n1, n2, i, cnt = 0;
	int* arr1, * arr2, *arr3;
	fscanf(f1, "%d", &n1);
	fscanf(f2, "%d", &n2);
	arr1 = (int*)malloc(n1 * sizeof(int));
	arr2 = (int*)malloc(n2 * sizeof(int));
	arr3 = (int*)malloc(n1 * sizeof(int));
	for (i = 0; i < n1; i++)
		fscanf(f1, "%d", &arr1[i]);
	for (i = 0; i < n2; i++)
		fscanf(f2, "%d", &arr2[i]);

	for (i = 0; i < n1; i++) {
		if (isSame(arr1[i], arr2, 1, n2)) {
			arr3[cnt] = arr1[i];
			cnt++;
		}
	}
	for (i = 0; i < cnt; i++)
		printf("%d ", arr3[i]);
	free(arr1);
	free(arr2);
	free(arr3);
}
