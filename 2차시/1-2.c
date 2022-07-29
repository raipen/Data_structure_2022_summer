#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 1. numzero함수에서 n==0이 된 경우에 어떤 값을 리턴할지 안 정해둬서 오류가 남. n>0이상일땐 지금 방식이 맞고, 아닐땐 return 0;를 해야함.
// 밑에는 그냥 팁
// 2. binaryRepresentation, numZero 등 으로 단어 기준으로 첫 글자 대문자로 해주는게 가독성 좋음
// 3. 개수를 세는 함수의 경우 보통 이름에 num 보다는 count를 넣음 countZero(n);

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
