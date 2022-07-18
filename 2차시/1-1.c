#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//21 리턴 자체가 안됨. 63 80 99 121없음으로 리턴됨

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

void main()
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
