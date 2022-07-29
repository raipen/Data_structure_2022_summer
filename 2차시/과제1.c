#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void ibs(int* arr, int start, int end, int num);
void rbs(int* arr, int start, int end, int num);

/*
1. 문제에서 주어진 in.txt에는 문제 없지만
    보통 채점할때는 어떤 in.txt 가 주어질 지 알 수 없다는 생각으로 코드를 짜야함
    즉, int arr[9];로 9칸만 딱 만들어두는 것보다는 대충 큰 값으로 잡아두는게 좋음
    그리고 end의 경우에도 arr[]로부터 할당된 공간의 크기를 대입하는것이 아니라
    fscanf로 가지고 온 값의 개수를 end로 삼아야함.

*/

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
