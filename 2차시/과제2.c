#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
1. bin함수의 리턴형은 void이므로 return 뒤에 값이 존재하면 안 됨. visual studio가 이상해서 정상 실행되지만
    다른 정상적인 컴파일러에선 오류 발생.
2. 0일때 bin이 0을 출력하도록 if(num>1)로 조건을 주고. 아닌 경우에 print 하는 아이디어 굿.
3. count를 인자로 주는 것이 아니라. 계속 리턴 시켜 값을 더해 나가는 방식도 있음.
    int zero(int num)
    {
        if (num == 1)
            return 0;
        else if (num == 0)
            return 1;

        if (num % 2 != 0)
            return zero(num / 2);
        else
            return 1 + zero(num / 2);
    }
*/

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

//정상작동

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
