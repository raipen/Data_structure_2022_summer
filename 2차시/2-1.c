#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void main()
{
	FILE* fp;
	FILE* fp1;
	int n, n1,i;
	fp = fopen("in1.txt", "r");
	if(fp== NULL)
	{
		printf("Cannot find the file\n");
		return 0;
	}
	fp1 = fopen("in2.txt", "r");
	if (fp1 == NULL)
	{
		printf("Cannot find the file\n");
		return 0;
	}
	fscanf(fp, "%d", &n);
	fscanf(fp1, "%d", &n1);

	int* p = (int*)malloc(sizeof(int) * n);
	int* p1 = (int*)malloc(sizeof(int) * n1);
	
	for (i = 0;i < n;i++)
	{
		fscanf(fp, "%d", &p[i]);
	}
	for (i = 0;i < n1;i++)
	{
		fscanf(fp1,"%d", &p1[i]);
	}
	for (i = 0;i < n;i++)
	{
		for (int j = 0;j < n1;j++)
		{
			if (p[i] == p1[j])
			{
				printf("%d ", p[i]);
			}
		}
	}

	fclose(fp);
	fclose(fp1);
	free(p);
	free(p1);
}
