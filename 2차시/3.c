// 시간복잡도 줄일 수 있도록 수정. 작동O

//1. 반복되는 부분이 너무 많음. 이럴땐 함수로 묶어주는 것도 좋음
//2. 두 자료가 내림차순으로 이루어져있다는 것을 사용하면 이중for문을 쓰지 않고 구현 가능
// 즉, 시간복잡도를 O(n^2)에서 O(n)으로 줄일 수 있음.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Comparison(int arr1[], int arr2[], int a, int b)
{
    int i = 0, j = 0;
    while (!(i == a && j == b)) {
        if (arr1[i] == arr2[j]) {
            printf("%d  ", arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] > arr2[j]) {
            i++;
        }            
        else {
            j++;
        }
    }
}

void main()
{
    int i, j;
    int a, b;
    int* arr1, * arr2;
    FILE* fp1;
    FILE* fp2;
    fp1 = fopen("in1.txt", "r");
    fp2 = fopen("in2.txt", "r");
    fscanf(fp1, "%d", &a);
    fscanf(fp2, "%d", &b);

    arr1 = (int*)malloc(sizeof(int) * a);
    arr2 = (int*)malloc(sizeof(int) * b);

    for (i = 0;i < a;i++) {
        fscanf(fp1, "%d", &arr1[i]);
    }
    for (i = 0;i < b;i++) {
        fscanf(fp2, "%d", &arr2[i]);
    }
    fclose(fp1);
    fclose(fp2);

    Comparison(arr1, arr2, a, b);

    free(arr1);
    free(arr2);
}
