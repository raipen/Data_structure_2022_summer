#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ibs(int a[], int n, int b, int c)
{
    int m;
    while (b <= c) {
        m = (b + c) / 2;
        if (a[m] == n)
            return m;
        else if (a[m] > n)
            c = m - 1;
        else
            c = m + 1;
    }
    return -1;
}

int rbs(int a[], int n, int b, int c)
{
    int m;
    if (b <= c) {
        m = (b + c) / 2;
        if (a[m] == n)
            return m;
        else if (n < a[m])
            return rbs(a, n, b, m - 1);
        return rbs(a, n, m + 1, c);
    }
}

void main()
{
    int a[100];
    int i = 0;
    int input;
    FILE* fp;
    fp = fopen("in.txt", "r");
    if (fp == NULL) {
        printf("ERROR");
        return 0;
    }
    while (fscanf(fp, "%d", &a[i]) != EOF)
    {
        i++;
    }
    fclose(fp);
    while (1) {
        scanf("%d", &input);
        if (input < 0)
            return 0;
        /*
        if (ibs(a, input, 0, i - 1) == -1)
            printf("iterative binary search:없음");
        else
            printf("iterative binary search:있음");
        */
         if (rbs(a, input, 0, i-1) == -1)
            printf("recursive binary search:없음");
        else
            printf("recursive binary search:있음");
    }   
}
