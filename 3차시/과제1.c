#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
민정이랑 과제 같이 했니...?

1. printPoly 함수 내부에서 int check를 사용하여 모두 값이 없는 경우를 체크하는데
	그냥 애초에 arr[]에 coef가 0인 값이 안 들어갔다면 어떨까?
	이 경우 add 함수 내부에서 coef가 0인 경우를 처리해주겠지
2. 나머지는 너무 잘 구현함
3. poly a[100], b[100], c[100]; 나도 이런식으로 각 식마다 다른 변수를 쓰는걸 선호하는데
	교수님 코드 중에서 그냥 큰 배열 하나 p[300]; 이런식으로 만들어두고
	각 다항식마다 시작지점을 startA, 끝 지점을 endA 이런식으로 두고 푸는 방법도 있어서
	이것도 알아뒀으면 좋겠음..
	저 방식의 코드는 깃헙에 jiwon 브랜치에 있으니 확인하면 될 듯
*/

typedef struct {
	int coef;
	int exp;
}poly;

void printPoly(poly arr[], int idx) {
	int check = 0;
	for (int i = 0; i < idx; i++) {
		if (arr[i].coef == 0) {
			check++;
			continue;
		}
		printf("%d^%d", arr[i].coef, arr[i].exp);
		if (i < idx - 1) printf(" + ");
	}
	if (check == idx)
		printf("0");
}

int add(poly a[], int a_size, poly b[], int b_size, poly c[]) {
	int i = 0, j = 0, k = 0;
	while (i < a_size && j < b_size) {
		if (a[i].exp > b[j].exp) 
			c[k++] = a[i++];
		else if (a[i].exp == b[j].exp) {
			c[k].exp = a[i].exp;
			c[k].coef = a[i].coef + b[j].coef;
			i++; j++; k++;
		}
		else 
			c[k++] = b[j++];
	}
	return k;
}

void main() {
	FILE* f1 = fopen("a.txt", "r"), * f2 = fopen("b.txt", "r");
	poly a[100], b[100], c[100];
	int ia = 0, ib = 0;
	while (!feof(f1)) {
		fscanf(f1, "%d %d", &a[ia].coef, &a[ia].exp);
		ia++;
	}fclose(f1);
	while (!feof(f2)) {
		fscanf(f2, "%d %d", &b[ib].coef, &b[ib].exp);
		ib++;
	}fclose(f2);
	printf("A(x) : ");
	printPoly(a, ia);
	printf("\nB(x) : ");
	printPoly(b, ib);
	int idx = add(a, ia, b, ib, c);
	printf("\n\nC(x) : ");
	printPoly(c, idx);
}
