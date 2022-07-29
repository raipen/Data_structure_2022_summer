//실행안됨ㅠㅡㅠ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
main은 잘 짰는데
if (input < 0) printf("Exit"); break;
이 문장이
if (input < 0){
	printf("Exit");
}
break;
라는 의미라서
input < 0 인지와 상관 없이 무조건 break;가 실행되어서 값이 안 나온거임

br의 경우, 일단 printf 하는 값은 n%2 즉, 2로 나누고 남은 값이 되면 됨
cnt의 경우, cnt 내부에서 실행된 cnt에서 바뀐 c의값이 밖에 영향을 안 줘서 c가 0또는 1만 출력될거야 아마

아마 main에 저 break 문제 때문에 br이랑 cnt 체크도 못 해본 거 같은데
한번 다시 짜보고 안 되면 톡으로 연락해
*/


int br(int n) {
	if (n >= 1) {
		br(n / 2);
		printf("%d\n",n%2);
	}

}


int cnt(int n, int c) {
	if (n >= 1) {
		if (n % 2 == 0) c++;
		cnt(n / 2, c);
	}
	return c;
}
	


void main()
{
	int input;

	while (1) {
		printf("Input num: ");
		scanf("%d", &input);
		if (input < 0) printf("Exit"); break;
		printf("2진표현: \n"); br(input);
		printf("%d내 0은 %d개 있다.\n", input, cnt(input, 0));
	}
}
