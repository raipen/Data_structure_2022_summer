#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* next;
}node;
typedef node* nodePointer;

nodePointer creatNode(int input) {
	nodePointer cur = (node*)malloc(sizeof(node));
	cur->data = input;
	cur->next = NULL;
	return cur;
}

nodePointer insertSorted(nodePointer h, nodePointer cur) {
	nodePointer p = h, q = h;
	while (p) {
		if (p->data > cur->data) break;
		q = p;
		p = p->next;
	}
	if (p == h) {
		cur->next = h;
		h = cur;
	}
	else {
		cur->next = p;
		q->next = cur;
	}
	return h;
}

void printNode(nodePointer h) {
	nodePointer p = h;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
}

void main() {
	FILE* fp = fopen("list.txt", "r");
	nodePointer head = NULL, cur;
	int input;
	while (!feof(fp)) {
		fscanf(fp, "%d", &input);
		if (input % 2 == 0) {
			cur = creatNode(input);
			head = insertSorted(head, cur);
		}
	}
	fclose(fp);
	printNode(head);
}
