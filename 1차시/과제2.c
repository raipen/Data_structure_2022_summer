#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//파라미터로 결과값을 저장할 공간을 받기
void addArry(int a[], int b[], int c[], int n) {
	for (int i = 0; i < n; i++) {
		c[i] = a[i] + b[i];
	}
}

//결과를 리턴하기
int* addArry2(int a[], int b[], int size) {
	int* c = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		c[i] = a[i] + b[i];
	}
	return c;
}

void printArry(int a[], int n) {
	for (int i = 0; i < n; i++) {
		fprintf(stdout, " %2d", a[i]);
	}
}

void main(){
	int* arr1, * arr2, * result;
	int size;

	//사이즈 입력받기
	printf("Input size: ");
	fscanf(stdin, "%d", &size);

	//입력받은 사이즈 만큼 배열 동적할당하기
	arr1 = (int*)malloc(sizeof(int) * size);
	arr2 = (int*)malloc(sizeof(int) * size);
	result = (int*)malloc(sizeof(int) * size);

	//랜덤으로 배열 채우기
	for (int i = 0; i < size; i++) {
		*(arr1 + i) = rand() % 21;
		*(arr2 + i) = rand() % 21;
	}

	//기존 배열 출력
	printf(" Array1: ");
	printArry(arr1, size);
	printf("\n Array2: ");
	printArry(arr2, size);

	//결과 출력
	printf("\n result: ");
	addArry(arr1, arr2, result, size);
	printArry(result, size);
	/* 위 두줄 대신 아래와 같이 결과를 출력해도 됨
	printArry(addArry2(arr1, arr2, size), size);
	*/
}
