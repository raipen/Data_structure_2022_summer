#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
