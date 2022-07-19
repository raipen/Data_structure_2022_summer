#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binaryCreate(int);
int countZero(int);

int main(void)
{
    int num;
    scanf("%d", &num);
    printf("input num: %d\n", num);

    if (num < 0)
        printf("Exit\n");

    int binary = binaryCreate(num);
    printf("2진 표현: %d\n", binary);
    
    int cnt;
    cnt = countZero(num);
    printf("%d내 0은 %d개 있다.\n", num, cnt);

    return 0;
}

int binaryCreate(int num){
    if (num == 0)
        return 0;
    int result = (num % 2) + binaryCreate(num/2)*10;
    return result;
}

int countZero(int num){
    if (num == 0){
        return 1;
    }
    if (num == 1){
        return 0;
    }
    switch(num % 2){
    case 0:
        return (countZero(num/2) + 1);
        break;
    case 1:
        return countZero(num/2);
        break;
    }

    return 0;
}