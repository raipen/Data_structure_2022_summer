#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
정말 잘 했는데 더했을 때 0이 되는 항를 어떻게 처리하면 좋을까?
생각보다 간단해. 한 두줄만 추가하면 됨.
한번 해결해서 올려보고 나한테 톡해줘
해결 못해도 톡 ㅇㅇ
*/

typedef struct {
	int coef;
	int expo;
}type;

int main()
{
	type p[1000], p1[1000], p2[1000];
	int n, n1, count = 0, count1=0;
	int startp=0, finalp, startp1=0, finalp1,temp;
	FILE* f, * fp;

	if ((f = fopen("a.txt", "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	if ((fp = fopen("b.txt", "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	printf("A(x): ");
	for (int i = 0; fscanf(f, "%d %d", &p[i].coef, &p[i].expo) != EOF; i++)
		count++;

	for (int i = 0; i<count; i++)
	{
		if (i == count - 1)
			printf("%d^%d", p[i].coef, p[i].expo);
		else
			printf("%d^%d + ", p[i].coef, p[i].expo);
	}

	printf("\nB(x): ");
	for (int i = count; fscanf(fp, "%d %d", &p[i].coef, &p[i].expo) != EOF; i++)
		count1++;

	for (int i = count; i < count1+count; i++)
	{
		if (i == count1 + count - 1)
			printf("%d^%d", p[i].coef, p[i].expo);
		else
			printf("%d^%d + ", p[i].coef, p[i].expo);
	}

	int count2 = count1 + count;
	finalp = count - 1;
	startp1 = count;
	finalp1 = count2 - 1;

	fclose(f);
	fclose(fp);

	while (startp <= finalp && startp1 <= finalp1) {

		if (p[startp].expo > p[startp1].expo)  
		{
			p[count2].coef = p[startp].coef;       
			p[count2].expo = p[startp].expo;
			count2++;
			startp++;
		}
		else if (p[startp].expo < p[startp1].expo)   
		{
			p[count2].coef = p[startp1].coef;        
			p[count2].expo = p[startp1].expo; 
			startp1++;
			count2++;
		}
		else
		{
			temp = p[startp].coef + p[startp1].coef;
			p[count2].coef = temp;
			p[count2].expo = p[startp].expo;
			count2++;
			startp++;
			startp1++;
		}
	}


	for (; startp <= finalp; startp++)
	{
		p[count2].coef = p[startp].coef;
		p[count2].expo = p[startp].expo;
		count2++;
	}

	for (; startp1 <= finalp1; startp1++)
	{
		p[count2].coef = p[startp1].coef;
		p[count2].expo = p[startp1].expo;
		count2++;
	}


	printf("\n\nC(x): ");

	for (int i = count1 + count; i < count2; i++)
	{
		if (i == count2 - 1)
			printf("%d^%d", p[i].coef, p[i].expo);
		else
			printf("%d^%d + ", p[i].coef, p[i].expo);
	}

}
