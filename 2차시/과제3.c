#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f1, *f2;
	if ((f1 = fopen("in1.txt", "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}
	if ((f2 = fopen("in2.txt", "r")) == NULL) {
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	int n1, n2, cnt = 0;
	fscanf(f1, "%d", &n1);
	fscanf(f2, "%d", &n2);

	int* in1 = (int*)malloc(sizeof(int) * n1);
	int* in2 = (int*)malloc(sizeof(int) * n2);
	int* inter = (int*)malloc(sizeof(int) * n2);

	for (int i = 0; i < n1; i++)
		fscanf(f1, "%d", &in1[i]);
	for (int i = 0; i < n2; i++)
		fscanf(f2, "%d", &in2[i]);

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			if (in1[i] < in2[j])
				continue;
			else if (in1[i] == in2[j])
			{
				inter[cnt] = in1[i];
				cnt++;
			}
		}
	}

	for(int i = 0; i < cnt; i++)
		printf("%3d", inter[i]);

	free(in1);
	free(in2);
	free(inter);
}
