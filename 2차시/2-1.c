//정상 작동함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int i, j;
    int a, b;
    int* arr1, * arr2;
    FILE* fp1;
    FILE* fp2;
    fp1 = fopen("in1.txt", "r");
    fp2 = fopen("in2.txt", "r");
    fscanf(fp1, "%d", &a);
    fscanf(fp2, "%d", &b);
    
    arr1 = (int*)malloc(sizeof(int) * a);
    arr2 = (int*)malloc(sizeof(int) * b);

    for (i = 0;i < a;i++) {
        fscanf(fp1, "%d", &arr1[i]);
    }
    for (i = 0;i < b;i++) {
        fscanf(fp2, "%d", &arr2[i]);
    }
    fclose(fp1);
    fclose(fp2);

    for (i = 0;i < a;i++) 
        for (j = 0;j < b;j++) 
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
            }
    free(arr1);
    free(arr2);
}
