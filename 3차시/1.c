//실행됨
/*
1. print 함수 내부에서 int c를 사용하여 모두 값이 없는 경우를 체크하는데
	그냥 애초에 a[]에 coef가 0인 값이 안 들어갔다면 어떨까?
	이 경우 add 함수 내부에서 coef가 0인 경우를 처리해주겠지
2. 나머지는 너무 잘 구현함
3. poly a[100], b[100], c[100]; 나도 이런식으로 각 식마다 다른 변수를 쓰는걸 선호하는데
	교수님 코드 중에서 그냥 큰 배열 하나 p[300]; 이런식으로 만들어두고
	각 다항식마다 시작지점을 startA, 끝 지점을 endA 이런식으로 두고 푸는 방법도 있어서
	이것도 알아뒀으면 좋겠음..
	저 방식의 코드는 깃헙에 jiwon 브랜치에 있으니 확인하면 될 듯
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial
{
	int coef;
	int exp;

}poly;

void print(poly a[], int n) {
	int c = 0, i;
	for (i = 0; i < n; i++) {
		if (a[i].coef == 0) {
			c++;
			continue;
		}
		printf("%d^%d", a[i].coef, a[i].exp);
		if (i < n - 1)printf(" + ");
	}
	if (c == n)
		printf("0");

}

int add(poly a[], int a_, poly b[], int b_, poly c[]) {
	int i=0, j=0, k=0;
	while (i < a_ && j < b_) {
		if (a[i].exp > b[j].exp)
			c[k++] = a[i++];
		else if (a[i].exp == b[j].exp) {
			c[k].exp = a[i].exp;
			c[k].coef = a[i].coef + b[j].coef;
			i++;
			j++;
			k++;
		}
		else
			c[k++] = b[j++];
	}
	return k;
}

void main() {
	FILE* fp1 = fopen("a.txt", "r");
	FILE* fp2 = fopen("b.txt", "r");
	poly a[100], b[100], c[100];
	int ac = 0, bc = 0;
	while (!feof(fp1)) {
		fscanf(fp1, "%d %d", &a[ac].coef, &a[ac].exp);
		ac++;
	}
	fclose(fp1);
	while (!feof(fp2)) {
		fscanf(fp2, "%d %d", &b[bc].coef, &b[bc].exp);
		bc++;
	}
	fclose(fp2);
	printf("A(x) : ");
	print(a, ac);
	printf("\nB(x) : ");
	print(b, bc);
	int n = add(a, ac, b, bc, c);
	printf("\n");
	printf("C(x) : ");
	print(c, n);

}
