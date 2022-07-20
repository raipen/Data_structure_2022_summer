//실행됨
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
