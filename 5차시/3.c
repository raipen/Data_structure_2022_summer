#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list* next;
}NODE;

void printlist(NODE* h) {
	NODE* p = h;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

NODE* inputlist(NODE* h, int data)
{
	NODE* node, * p, * q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	p = h;
	q = h;
	while (p != NULL) { //왼쪽값이 더 크면 바꿔줌.
		if ((p->data) > data)
		{
			break;
		}
		q = p;
		p = p->next;
	}

	if (p == h) { //건너뛰고 다음 노드와 연결시켜줌
		node->next = h;
		h = node;
	}
	else { //그냥 넣어줌
		node->next = p;
		q->next = node;
	}
	return h;
}

void main()
{
	int i, data;
	NODE* header = NULL;
	FILE* fp;
	if ((fp = fopen("list.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}
	while(fscanf(fp,"%d",&data)!=EOF)
	{
		if(data%2==0)
		header = inputlist(header, data);
	}
	printlist(header);
}
