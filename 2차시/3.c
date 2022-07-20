//실행됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
