//망함ㅋㅋ..
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int *Q, front = -1, rear = -1, size;
typedef enum { false, true }boolean;

boolean isFull() {
	return rear - front == size;
}

void enQ(int input) {
	if (isFull() == true)
		return;
	else
		Q[++rear] = input;
}

boolean isEmpty() {
	return rear == front;
}

void deQ() {
	if (isEmpty() == true)
		return;
	else
		Q[front++] = 0;
}

void printQ() {
	if (isFull() == true)
		printf("List queue is full!\n");
	else if (isEmpty() == true)
		printf("List queue is empty!\n");
	else {
		printf("List queue: ");
		for (int i = front + 1; i <= rear; i++)
			printf("%d ", Q[i]);
		printf("\n");
	}
}

void main() {
	int num;
	char ch;
	printf("input size:");
	scanf("%d", &size);
	printf("Queue size : %d\n", size);
	Q = (int*)malloc(sizeof(int) * size);
	while (1) {
		printf("input:");
		scanf("\n%c", &ch);
		if (ch == 'q') break;
		else if (ch == 'a') {
			scanf("%d", &num);
			enQ(num);
		}
		else
			deQ();
		printQ();
	}
	free(Q);
}
