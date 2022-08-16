//상여자 특:디버깅안함 (그래서망함)
//화면에아무것도안떠요...중간중간에 테스트 좀 해볼걸..../
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int coef, expon;
	struct node* next;
}poly;

void printList(poly *h) {
	if (!h) 
		printf("empty list\n");
	else {
		poly* p = h;
		while (p) {
			printf("[%d,%d] ", p->coef, p->expon);
			p = p->next;
		}
	}
	printf("\n");
}

poly* append(poly* h, int co, int ex) {
	poly* p, * node;
	node = (poly*)malloc(sizeof(poly));
	node->next = NULL;
	node->coef = co, node->expon = ex;
	if (!h)
		h = node;
	else {
		p = h;
		while (p->next)
			p = p->next;
		p->next = node;
	}
	return h;
}

void createPoly(FILE* f, poly** h) {
	int co, ex;
	while (!feof(f)) {
		fscanf(f, "%d %d", &co, &ex);
		*h = append(*h, co, ex);
	}
}

poly* padd(poly *h1, poly *h2) {
	poly* p = h1, * q = h2, *head = NULL;
	while (p && q) {
		if (p->expon == q->expon) {
			head = append(head, p->coef + q->coef, p->expon);
			p = p->next;
			q = q->next;
		}
		else if (p->expon > q->expon) {
			head = append(head, p->coef, p->expon);
			p = p->next;
		}
		else {
			head = append(head, q->coef, q->expon);
			q = q->next;
		}
	}
	return head;
}

void erase(poly** h) {
	free(*h);
	*h = NULL;
}

void main() {
	FILE* f1 = fopen("poly1.txt", "r"), * f2 = fopen("poly2.txt", "r");
	poly* head1 = NULL, * head2 = NULL, *head3 = NULL;
	head1->next = NULL, head2->next = NULL, head3->next = NULL;
	createPoly(f1, &head1);
	createPoly(f2, &head2);
	fclose(f1);
	fclose(f2);
	head3 = padd(head1, head2);
	printf("%10s", "poly A:"); 
	printList(head1);
	printf("%10s", "poly B:");
	printList(head2);
	printf("%10s", "poly(A+B):");
	printList(head3);
	erase(&head1);
	erase(&head2);
	erase(&head3);
	printf("%10s", "poly A:");
	printList(head1);
	printf("%10s", "poly B:");
	printList(head2);
	printf("%10s", "poly(A+B):");
	printList(head3);
}
