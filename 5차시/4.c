#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list* next;
}NODE;

void printlist(NODE* h);
int checkist(NODE* h, int input);//노드를 삭제하되 해당 노드가 리스트에 없을 때 메시지를 출력함.
NODE* inputlist(NODE* h, int data);
NODE* deleteNode(NODE* head, int data);

void main()
{
	int i, data,input=0;
	NODE* header = NULL;
	FILE* fp;
	if ((fp = fopen("list.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}
	printf("리스트:\n");
	while (fscanf(fp, "%d", &data) != EOF)
	{
		header = inputlist(header, data);
	}
	printlist(header);
	while (1)
	{
		printf("Input number: ");
		scanf("%d", &input);
		if (input < 0) break;
		int che = input % 10;
		if (che >= 0 && che <= 4)header = inputlist(header, input);
		else if (che >= 5 && che <= 9)
		{
			if(checkist(header,input)==0) continue;
			else header = deleteNode(header, input);
		}
		printlist(header);
	}

}

void printlist(NODE* h) {
	NODE* p = h;
	while (p != NULL) {
		printf("[%d]", p->data);
		p = p->next;
	}
	printf("\n");
}

int checkist(NODE* h, int input) {
	NODE* p = h;
	while (p != NULL) {
		if (p->data == input)
		{
			return 1;
		}
		p = p->next;
	}
	printf("삭제할 수 %d 없음.\n", input);
	return 0;
}


NODE* inputlist(NODE* h, int data)
{
	NODE* node, * p, * q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	p = h;
	q = h;
	while (p != NULL) { //왼쪽값이 더 크면 바꿔줌.
		if ((p->data) < data)
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

NODE* deleteNode(NODE* head, int data)
{
	NODE* node, * p, * q;

	node = (NODE*)malloc(sizeof(NODE));
	node->data = data;

	p = head;
	q = head;
	while (p != NULL) {//삭제해야할 노드 찾기
		if (p->data == data)//찾으면 멈춤.
		{
			break;
		}
		if ((p->data) < data)//가장 큰 값이므로 더 체크할 필요 x
		{
			return head;
		}
		q = p;
		p = p->next;
	}
	if (p == NULL) return head;//다 돌면 삭제필요없음.
	else if (p == head) {//p가 맨 끝일때
		head = head->next;
		free(p);
		return head;
	}
	else {//p가 맨 끝이 아닐때
		q->next = p->next;
		free(p);
		return head;
	}

}
