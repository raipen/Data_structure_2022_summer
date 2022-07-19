//실행안됨ㅠㅡㅠ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int br(int n) {
	if (n >= 1) {
		br(n / 2);
		printf("%d\n");
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
