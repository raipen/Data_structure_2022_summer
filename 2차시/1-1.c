#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//21 리턴 자체가 안됨. 63 80 99 121없음으로 리턴됨
// 1. ""void""" main 인데 return 0;가 있음. VS에선 문제 없으나 다른 C언어 컴파일러에선 무조건 오류남
// 2. ibs와 rbs 모두 mid 검사 값이 잘못됨 ( l + h /2 가 아니라 (l+h)/2 .. 더하기 먼저 하도록 괄호를 했어야함)
// 3. 배열의 크기가 기준이 되어서 함수를 시작하면 안 됨. 자료의 개수로 해야함. 일단 이 코드 상에서는 자료의 개수도 9개고 size-1도 9라서 작동함.
// 3번 보충: 네 코드 기준으로 int size = i;로 하고 ibs(a, 0, size, n)로 호출 되어야함

int ibs(int a[], int l, int h, int n)
{
	while (l <= h)
	{
		int mid = l + h / 2;
		if (a[mid] == n)
		{
			return mid;
		}
		if (n < a[mid])
		{
			h = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}

int rbs(int a[], int l, int h, int n)
{
	int mid;
	if (h < l) return -1;
	mid = l + h / 2;
	if (a[mid] > n)
		return rbs(a, l, mid - 1, n);
	else if (a[mid] < n)
		return rbs(a, mid + 1, h, n);
	else
		return mid;
}

int main()
{
	FILE* fp;
	int a[10];
	int n, i = 0, m;
	//파일 열기
	if ((fp = fopen("in.txt", "r")) == NULL)
	{
		printf("cannot find");
		return 0;
	}
	//파일 자료 배열로 받기
	while (fscanf(fp, "%d", &m) != EOF)
	{
		a[i] = m;
		i++;
	}
	//파일닫기
	fclose(fp);

	//배열 크기
	int size = sizeof(a) / sizeof(a[0]);
	
	//출력
	while (1)
	{
		printf("Input number: ");
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Exit");
			return 0;
		}
		printf("iterative binary search: ");
		if (ibs(a, 0, size - 1, n) == -1)
		{
			printf("없음\n");
		}
		else
		{
			printf("있음\n");
		}

		printf("recuresive binary search: ");

		if (rbs(a, 0, size - 1, n) == -1)
		{
			printf("없음\n");
		}
		else
		{
			printf("있음\n");
		}
	}
}
