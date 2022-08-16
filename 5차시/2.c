#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
typedef struct listqueue {
	int front;
	int rear;
	element* data;
}listqueue;

int size = 0;

void list_init_queue(listqueue* que, int size);
int list_IsEmpty(listqueue* que);
int list_IsFull(listqueue* que, int size);
void list_enqueue(listqueue* que, int index);
int list_dequeue(listqueue* que);
void printlistqueue(listqueue* que);
void freelistqueue(listqueue* que);

void main()
{
	listqueue listqueue;
	int listqueuesize = 0;
	char menu[5] = { NULL };
	int pushindex = 0;
  
	printf("input size:");
	scanf("%d", &listqueuesize);
	size = listqueuesize;
	list_init_queue(&listqueue, listqueuesize);


	printf("Queue size: %d\n", listqueuesize);
	printf("Input:");
	while (scanf("%c", menu) != 'q')
	{
		if (strcmp(menu, "a") == 0) {
			scanf("%d", &pushindex);
			list_enqueue(&listqueue, pushindex);
			//if (list_IsFull(&listqueue,listqueuesize) == 1) { continue; }
			printlistqueue(&listqueue);

		}
		if (menu == 'd')
		{
			list_dequeue(&listqueue);
			printf("List queue:");
			printlistqueue(&listqueue);

		}
		if (menu == 'q')
		{
			freelistqueue(&listqueue);
			printf("quit");
			break;
		}
	}

}

void list_init_queue(listqueue* que, int size)//data에 동적할당
{
	que->data = (int*)malloc(sizeof(int) * size);
	que->front = -1;
	que->rear = 0;
}

int list_IsEmpty(listqueue* que) {
	if (que->rear - que->front == 1)
		return 1;//empty
	else
		return 0;//empty x
}

int list_IsFull(listqueue* que, int size) {
	if (que->rear - que->front == size)
		return 1;//full(capacity-1은 full일때의 pop의 위치)
	else
		return 0;//full x(full이 아님)
}


void list_enqueue(listqueue* que, int index)
{
	if (list_IsFull(que, size) == 1) {
		printf("List queue is full\n");
		return;
	}
	else
	{
		
		que->data[que->rear++] = index;
	}
}

int list_dequeue(listqueue* que)
{
	if (list_IsEmpty(que) == 1) {
		printf("List queue is empty\n");
		return;
	}
	else {
		int data = que->data[++(que->front)];
		return data;
	}
}
void printlistqueue(listqueue* que)
{
	if (list_IsEmpty(que) == 1)
	{
		printf("listqueue is empty\n");
		return;
	}
	else
	{
		printf("List queue:");
		for (int i = que->front+1; i < que->rear;i++)
		{
			printf("%d ", que->data[i]);
		}
		printf("\n");
	}
}

void freelistqueue(listqueue* que) {
	for (int i = que->front+1; i < que->rear;i++)
	{
		free(que->data[i]);
	}
	return;
}
