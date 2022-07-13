#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ibs(int* arr, int start, int end, int num);
void rbs(int* arr, int start, int end, int num);

//정상작동
int main()
{
    int arr[9], num;

    FILE* f;
    if ((f = fopen("in.txt", "r")) == NULL) {
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }

    for (int i = 0; i < 9; i++)
        fscanf(f, "%d", &arr[i]);

    fclose(f);

    int start = 0;
    int end = (sizeof(arr) / sizeof(int)) - 1;

    do{
        printf("Input number: ");
        scanf("%d", &num);
        if (num < 0)
            break;
        ibs(arr, start, end, num);
        rbs(arr, start, end, num);
    } while (1);

    printf("Exit\n");
    return 0;
}

void ibs(int *arr,int start,int end, int num)
{
	while (start <= end)
	{
        int mid = (start + end) / 2;

		if (num > arr[mid])
            start = mid + 1;

		else if (num < arr[mid])
            end = mid - 1;

        else
        return printf("iterative binary search :있음\n");
	}

	return printf("iterative binary search :없음\n");
}

void rbs(int* arr, int start, int end, int num)
{
    if (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] < num)
            return rbs(arr, mid + 1, end, num);

        else if (arr[mid] > num)
            return rbs(arr, start, mid - 1, num);

        else
            return  printf("recursive binary search :있음\n");
    }

    else 
        return printf("recursive binary search :없음\n");
}
