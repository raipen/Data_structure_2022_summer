#include <stdio.h>
#include <time.h>
#define SWAP(a,b,c) c=a, a=b, b=c
#define MAX_SIZE 1001

void sort(int l[], int n) {
	int i, j, m, t;
	for (i = 0;i < n - 1;i++) {
		m = i;
		for (j = i + 1;j < n;j++) {
			if (l[j] < l[m]) {
				m = j;
			}
		}
		SWAP(l[i], l[m], t);
	}
}

void main(void) {
	int i, n, step = 10;
	int a[MAX_SIZE];
	double d;
	clock_t start;
	printf("     n\ttime\n");
	for (n = 0;n <= 1000;n += step) {

		for (i = 0;i < n;i++)
			a[i] = n - i;
			
		start = clock();
		sort(a, n);
		d = ((double)(clock() - start)) / CLOCKS_PER_SEC;
		printf("%6d\t%f\n", n, d);
		if (n == 100) step = 100;
	}
}