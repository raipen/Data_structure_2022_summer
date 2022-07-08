#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct pscore {
	char name[10];
	int sub1;
	int sub2;
	int sub3;
	float sum;
}pscore;

int main()
{
	pscore p[5];
	FILE* f, * fp;

	f = fopen("score.txt", "r");
	fp = fopen("result.txt", "w");

	for (int i = 0; fscanf(f, "%s %d %d %d", p[i].name, &p[i].sub1, &p[i].sub2, &p[i].sub3) != EOF; i++)
	{
		p[i].sum = p[i].sub1 + p[i].sub2 + p[i].sub3;
		fprintf(fp, " %6s %6.1f\n", p[i].name, p[i].sum / 3);
		printf(" %6s %6.1f\n", p[i].name, p[i].sum / 3);
	}

	fclose(f);
	fclose(fp);
}
