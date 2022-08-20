#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_TERMS 1000
typedef int type;

typedef struct {
	type coef; //계수
	type expon; //지수
}polynominal;

polynominal term[MAX_TERMS] = { 0 };//a,b식을 넣는 배열
polynominal cal[MAX_TERMS] = { 0 };//c식을 넣는 배열
int avail = 0;//a식의 길이

void printpoly(FILE* f);
void printcal(int clength);
int calculation(int alength, int blength, int avail3);

int main()
{
	FILE* fp, * fp1;

	int alength,blength,clength;//각각의 식의 길이
	int avail2,avail3;//a식 끝부분의 배열위치, term배열의 길이(b식의 끝부분)
	
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
	avail2 = avail-1;
	printf("B(x):");
	printpoly(fp1);
	avail3 = avail-1;

	alength = avail2 + 1;
	blength = avail3 -avail2;

	//A(x)+B(x) 구현
	clength= calculation(alength, blength, avail3);

	//C(x)출력
	printcal(clength);
	return 0;
}

void printpoly(FILE* f)
{
	while (fscanf(f, "%d %d", &term[avail].coef, &term[avail].expon) != EOF)
	{
		printf("%d^%d ", term[avail].coef, term[avail].expon);

		if (term[avail].expon != 0 && term[avail].coef != 0) { printf("+ "); }
		avail++;
	}
	printf("\n");
}

void printcal(int clength) {
	printf("\nC(x): ");

	int count = 0;
	int m;
	//C(x)에 항이 없을 때(다 더해서 0)
	for (m = 0;m < clength;m++) {
		if (cal[m].coef == 0)count++;
	}
	if (count == clength) {
		printf("0");
		return 0;
	}

	//C(x)에 항이 하나라도 있을 때
	for (m = 0;m < clength;m++) {
		if (cal[m].coef == 0)continue;
		printf("%d^%d ", cal[m].coef, cal[m].expon);
		if (cal[m].expon != 0) { printf("+ "); }
	}
	return 0;
}

int calculation(int alength, int blength, int avail3) {
	int maxfirst, minfirst, maxend;//긴 식의 처음 위치,짧은 식의 처음 위치,긴 식의 끝부분
	int clength = 0;//clength를 구하기위해 사용.
	int max, min;//두 식중에 더 긴 식을 max 더 작은 식을 min.
	if (alength <= blength) {
		min = alength;
		max = blength;
		maxfirst = min;
		minfirst = 0;
		maxend = avail3 + 1;
	}
	else {
		min = blength;
		max = alength;
		maxfirst = 0;
		minfirst = min + 1;
		maxend = min + 1;
	}

	while (maxfirst != maxend) {//
		if (term[minfirst].expon > term[maxfirst].expon) {
			cal[clength].expon = term[minfirst].expon;
			cal[clength].coef = term[minfirst].coef;
			clength++;
			minfirst++;
		}
		else if (term[minfirst].expon == term[maxfirst].expon) {
			cal[clength].expon = term[minfirst].expon;
			cal[clength].coef = term[minfirst].coef + term[maxfirst].coef;
			clength++;
			minfirst++;
			maxfirst++;
		}
		else {
			cal[clength].expon = term[maxfirst].expon;
			cal[clength].coef = term[maxfirst].coef;
			maxfirst++;
			clength++;
		}
	}
	return clength;
}
