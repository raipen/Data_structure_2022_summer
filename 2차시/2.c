// 작동O
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cnt;

void BinaryRepresentation(int n)
{
    if (n > 0) {
        BinaryRepresentation(n / 2);
        printf("%d", n % 2);
    }
}

int CountZero(int n)
{
    if (n == 0)
        return cnt;
    if (n % 2 == 0)
        cnt++;
    CountZero(n / 2);
}


void main()
{
    int input;
    while (1) {
        printf("Input num: ");
        scanf("%d", &input);
        if (input < 0) {
            printf("Exit");
            break;
        }
        printf("2진표현: ");
        BinaryRepresentation(input);
        cnt = 0;
        printf("\n%d내 0은 %d개 있다.\n", input, CountZero(input));
    }
}
