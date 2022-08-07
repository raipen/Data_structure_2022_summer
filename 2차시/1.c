// 작동O

//ibs 실행 안됨, rbs 값 제대로 출력 안함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1. ibs에서 else 내부 고침
2. rbs에서 못 찾은 경우(b가 c보다 커진 경우)에는 return -1;을 하도록 추가
*/

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
            b = m + 1; //c = m+1;에서 b = m+1;로 수정 n이 a[m]보다 큰 경우에는 m+1~c 사이의 범위를 찾아야하므로 b의 값을 변경해주어야한다.
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
    return -1; //b가 c보다 커질때까지 a[m]==n인 경우가 없었다는 뜻이므로 -1을 리턴
}

int main()
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
        
        if (ibs(a, input, 0, i - 1) == -1)
            printf("iterative binary search:없음");
        else
            printf("iterative binary search:있음");
        if (rbs(a, input, 0, i-1) == -1)
            printf("recursive binary search:없음");
        else
            printf("recursive binary search:있음");
    }   
}
