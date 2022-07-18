#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binaryrepresentation(int n)
{
	if (n > 0)
	{
		binaryrepresentation(n / 2);
		printf("%d", n%2);
	}
}


int numzero(int n)
{
	if (n > 0)
	{
		if (n % 2 == 0)
		{
			return numzero(n / 2) + 1;
		}
		else
		{
			return numzero(n / 2);
		}
	}
}

void main()
{
	int n = 0;
	while (1)
	{
		printf("Input num: ");
		scanf("%d", &n);
		if (n < 0)
		{
			printf("Exit");
			break;
		}
		printf("2진표현: ");
		binaryrepresentation(n);
		if(n%2==1)
			printf("\n%d내 0은 %d개 있다\n", n, numzero(n/2)-1);
		else
			printf("\n%d내 0은 %d개 있다\n", n, numzero(n/2));
	}
}
