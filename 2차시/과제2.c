#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void bin(int num)
{
    if (num > 1)
    {
        bin(num / 2);
        printf("%d", num % 2);
    }
    else
       return printf("%d", num);
}

int zero(int num, int count)
{
    if (num == 1)
        return count;
    else if (num == 0)
        return ++count;

    if (num % 2 != 0)
        zero(num / 2, count);
    else
        zero(num / 2, ++count);
}

int main()
{
    int num, count = 0;

    do{
        printf("Input number: ");
        scanf("%d", &num);
        if (num < 0)
            break;
        printf("2진표현: "); bin(num); printf("\n");
        printf("%d내 0은 %d개 있다.\n", num, zero(num, count));

    } while (1);

    printf("Exit\n");
    return 0;
}
