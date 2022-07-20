#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 1000

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
