#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binaryCreate(int);
int countZero(int);

int main(void)
{
    int num;
    /*여기서부터 while(1)로 return 0; 앞부분까지 감싸주고,
    num<0일때 Exit 출력과 함께 break; 해주면
    음수가 들어올때까지 무한 반복 가능*/
    scanf("%d", &num);
    printf("input num: %d\n", num);

    if (num < 0)
        printf("Exit\n");

    int binary = binaryCreate(num); //이 함수가 최종적으로 이진수로 표현된 값을 리턴해준다는 점에서 진짜 작명도 잘 했고 함수 자체도 잘 돌아감 
    printf("2진 표현: %d\n", binary);
    
    /*다만 2진수를 출력하는 위 두줄에 한가지 문제가 있는데...
    binaryCreate(1023) == 1111111111(1이 10개)이고
    binaryCreate(1024) == 10000000000(1뒤에 0이 10개)인데
    int의 최대 표현 가능 수는 2,147,483,647 이라서 1024의 답이 제대로 저장될 수 없어 ㅠㅠ
    그래서 1024 이상의 수를 이진수로 출력하기 위해서는 binaryCreate()가 int를 호출해주는 방식을 쓰기 힘들어

    그래서 그냥 끝에서부터 한번에 한가지 수를 출력하는 방식으로 코드를 짜는 편이야.
    ex)
    int main(){
        int input;
        while(1){
            scanf("%d",&input);
            if(input<0){
                fprintf(stderr,"Error: invalid input number %d\n",input);
                break;
            }
            printf("2진 표현: ");
            printBinary(input);
            printf("\n");
        }
        return 0;
    }

    void printBinary(int num){
        if(num){
            printBinary(num / 2);
            printf("%d\n",num % 2);
        }
    }


    */

    int cnt;
    cnt = countZero(num); //얘는 그냥 그저 완벽 그 자체
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
    // 이거 스위치문 안 쓰고
    // return countZero(num/2) + ((num+1) % 2);
    // 라고 한줄만 적었어도 됨
    // 이건 코딩적인건 아니고.. 그냥 수학적으로 활용하는 팁.
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