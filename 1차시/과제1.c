#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[30];
	int score[3];
	int avg;
}student;

void main()
{
	struct student stu[6] = { -1 };

	FILE* fp;
	char ch, file[100];
	int i = 0;
	fp = fopen("score.txt", "r");

	if (fp == NULL)
	{
		printf("Cannot find the file\n");
		exit(0);
	}

	for (i = 0; fscanf(fp, "%s %d %d %d", stu[i].name, &stu[i].score[0], &stu[i].score[1], &stu[i].score[2]) != EOF; i++)
	{
		stu[i].avg = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2])/3;
  }

	for (i = 0; i < 5; i++)
	{
		printf("%s %d\n", stu[i].name,stu[i].avg);
  }
  fclose(fp);
}
