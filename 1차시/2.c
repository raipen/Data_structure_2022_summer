// 작동O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int input, i;
    int* a1;
    int* a2;
    scanf("%d", &input);
    printf("Input size: %d\n", input);
    a1 = (int*)malloc(sizeof(int) * input);
    a2 = (int*)malloc(sizeof(int) * input);
    printf("Array1:  ");
    for (i = 0;i < input;i++) {
        a1[i] = rand() % 21;
        printf("%3d", a1[i]);
    }
    printf("\nArray2:  ");
    for (i = 0;i < input;i++) {
        a2[i] = rand() % 21;
        printf("%3d", a2[i]);
    }
    printf("\nresult:  ");
    for (i = 0;i < input;i++)
        printf("%3d", a1[i] + a2[i]);
    free(a1);
    free(a2);
}
