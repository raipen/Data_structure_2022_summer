#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*다 좋은데
free(p[i]); 먼저하고
printf("free arr[%d].\n", i); 얘를 출력하는게
제대로 free 됐는지 확인 하는 방법 이긴 해
-수정함.
*/

int main()
{
	int row, col, i, j;
	printf("row size:");
	scanf("%d", &row);
	printf("col size:");
	scanf("%d", &col);

	int **p = malloc(sizeof(int*) * row);

	for (i = 0;i < row;i++)
	{
		p[i] = malloc(sizeof(int) * col);
	}

	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			p[i][j] = pow(i, 2) + pow(j, 2);
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}

	for (i = 0;i < row;i++)
	{
		free(p[i]);
		printf("free arr[%d].\n", i);
	}
	printf("free arr.");
	free(p);
	return 0;
}
