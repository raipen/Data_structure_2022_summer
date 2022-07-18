#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printbin(int n) {
	if (n >= 1) {
		printbin(n / 2);
		printf("%d", n % 2);
	}
}

int countzero(int n, int cnt) {
	if (n >= 1) 
		return n % 2 ? countzero(n / 2, cnt) : countzero(n / 2, cnt + 1);
	return cnt;
}

void main() {
	int n;
	while (1) {
		printf("Input num : ");
		scanf("%d", &n);
		if (n < 0) break;
		printf("이진 표현 : "); printbin(n);
		printf("\n%d내 0은 %d개 있다.\n", n, countzero(n, 0));
	}
}
