//실행됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
이 문제 푼 사람 중에 가장 좋은 시간 복잡도를 가지고 있음
첫번째 배열에 존재하는 값이 두번째 배열에 존재하는지 BS로 찾기 때문에
O(n*log(n))의 시간복잡도를 가짐
근데 이미 두 배열이 모두 내림차순으로 "정렬"되어 있다는 것을 이용하면 O(n)으로 구현 가능
한번 해보면 좋을 듯
*/


int intersection(int a[], int n, int f, int l)
{
	while (f <= l) {
		int mid = (f + l) / 2;
		if (n == a[mid])return 1;
		if (n < a[mid])f = mid + 1;
		else l = mid - 1;
	}
	return 0;
}
void main()
{
	FILE* fp1 = fopen("in1.txt", "r");
	if (fp1 == NULL) {
		printf("파일 없음 ㅅㄱ\n");
		exit(1);
	}
	FILE* fp2 = fopen("in2.txt", "r");
	if (fp2 == NULL) {
		printf("파일 없음 ㅅㄱ\n");
		exit(1);
	}

	int n1, n2,i,cnt=0;
	
	fscanf(fp1, "%d", &n1);
	fscanf(fp2, "%d", &n2);

	int* arr1 = (int*)malloc(n1*sizeof(int));
	int* arr2 = (int*)malloc(n2* sizeof(int));
	int* arr3 = (int*)malloc(n1 * sizeof(int));

	for (i = 0; i < n1; i++) {
		fscanf(fp1, "%d", &arr1[i]);
	}

	for (i = 0; i < n2; i++) {
		fscanf(fp2, "%d", &arr2[i]);
	}

	for (i = 0; i < n1; i++) {
		if (intersection(arr2, arr1[i], 1, n2)) {
			arr3[cnt] = arr1[i];
			cnt++;
		}
	}

	for (i = 0; i < cnt; i++) {
		printf("%d ", arr3[i]);
	}

	free(arr1);
	free(arr2);
	free(arr3);


}
