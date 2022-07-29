#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
완벽함
그냥 이런 표현법도 있다고 알아두면 좋을 거 같아서 알려주는거
countzero같은 경우에는 인자로 cnt를 쓰지 않고, 리턴값에 현재 상태를 더하는 방식으로도 구현 가능
ex)
int countzero(int n){
	if (n >= 1) 
		return n % 2 ? countzero(n / 2) : countzero(n / 2) + 1;
	return 0;
}

*/

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
