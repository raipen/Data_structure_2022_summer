#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE* nodePointer;
typedef struct NODE {
	int data;
	nodePointer next;
}node;

nodePointer creatNode(int input) {
	nodePointer cur = (node*)malloc(sizeof(node));
	cur->data = input;
	cur->next = NULL;
	return cur;
}

nodePointer insertSorted(nodePointer h, nodePointer cur) {
	nodePointer p = h, q = h;
	while (p) {
		if (p->data < cur->data) break;
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

nodePointer append(nodePointer h, nodePointer cur) {
	nodePointer p = h;
	if (h == NULL)
		h = cur;
	else {
		while (p->next)
			p = p->next;
		p->next = cur;
	}
	return h;
}

void deleteNode(nodePointer *h, nodePointer cur) {
	if ((*h)->data == cur->data) {
		(*h) = (*h)->next;
		return;
	}
	nodePointer p = (*h);
	while (p) {
		if (p->next->data == cur->data) {
			p->next = p->next->next;
			return;
		}
		p = p->next;
	}
}

int exist(nodePointer h, nodePointer cur) {
	nodePointer p = h;
	while (p) {
		if (p->data == cur->data) return 1;
		p = p->next;
	}
	return 0;
}

void printList(nodePointer h) {
	nodePointer p = h;
	while (p) {
		printf("[%3d]", p->data);
		p = p->next;
	}
	printf("\n");
}

void main() {
	FILE* fp = fopen("list.txt", "r");
	nodePointer head = NULL, cur;
	int input;
	while (!feof(fp)) {
		fscanf(fp, "%d", &input); 
		cur = creatNode(input); 
		head = append(head, cur);
	}
	fclose(fp);
	printf("리스트:\n");
	printList(head);

	while (1) {
		printf("input number: ");
		scanf("%d", &input);
		if (input == -1) break;
		cur = creatNode(input);
		if (input % 10 < 5) {
			head = insertSorted(head, cur);
		}
		else {
			if (!exist(head, cur)) printf("삭제할 수 없음.\n");
			else
				deleteNode(&head, cur);
		}
		printList(head);
	}
}
