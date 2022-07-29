#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 1000

/*
1. 먼가 avail2랑 avail3의 역할이 바뀌 느낌....
2. 과연 이중 for문이 맞는가?, 각 반복문 상황에서 항상 i++과 j++이 일어나는 것이 맞는가? 에 대해 생각해볼 것
	i++과 j++을 for문 선언부에서 하는 것이 아니라 for문 내부에서 조건에 따라 하는 방식을 고려해볼 것
	지금과 같은 이중for문 으로 구현하는 경우에는 A식의 각 항의 지수와 같은 지수를 가진 항을 B에서 찾아 더하는 방식이 적합할 듯?
	고려해서 혼자 한번 짜보고 안 되면 카톡하셈. 비대면으로라도 화면공유해서 설명해줌. 텍스트로 하기엔 설명해줄 내용이 너무 많다.
*/

typedef struct {
	int coef; //계수
	int expon; //지수
}polynominal;

polynominal term[MAX_TERMS]; 
int avail = 0;//다음 번 빈 슬롯의 array index 번호 유지

int printpoly(FILE* f)
{
	while (fscanf(f, "%d %d", &term[avail].coef, &term[avail].expon) != EOF)
	{
		printf("%d^%d + ", term[avail].coef, term[avail].expon);
		avail++;
	}
	printf("\n");
}

void main()
{
	FILE* fp, * fp1;
	int i = 0;

	if ((fp = fopen("a.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}
	if ((fp1 = fopen("b.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}

	//파일에서 식 받아서 출력
	printf("A(x):");
	printpoly(fp);
	
	int avail1 = avail;//a식의 끝이 avail1.

	printf("B(x):");
	printpoly(fp1);

	int avail2 = avail;//b식의 끝이 avail2.
	int avail3 = avail2;//c식 시작점이 avail3.

	//A(x)+B(x) 구현.근데 덜함.
	for (int i = 0;i < avail1;i++)
	{
		for (int j = avail1;j < avail3;j++)
		{
			if (term[i].expon > term[j].expon)
			{
				term[avail2].expon = term[i].expon;
				term[avail2].coef = term[i].coef;
				avail2++;
				i++;
			}
			else if (term[i].expon == term[j].expon)
			{
				term[avail2].expon = term[i].expon;
				term[avail2].coef = term[i].coef + term[j].coef;
				avail2++;
				i++;
			}
		}
	}

	//C(x)출력
	printf("C(x):");
	for (int i = avail3;i < avail2;i++)
	{
		if (term[i].coef == 0)
			continue;
		printf("%d^%d + ", term[i].coef, term[i].expon);
	}

}
