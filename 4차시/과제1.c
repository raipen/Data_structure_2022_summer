#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int element;
typedef enum{ False, True }Boolean;
element* stack, capacity = 1, top = -1;

Boolean isFull() {
	return (top == capacity - 1);
}

Boolean isEmpty() {
	return (top == -1);
}

void push(element item) {
	if (isFull() == True) {
		capacity *= 2;
		stack = (element*)realloc(stack, sizeof(element) * capacity);
	}
	stack[++top] = item;
}

void pop() {
	stack[top--];
}

void main() {
	FILE* fp = fopen("in.txt", "r");
	char ch;
	int cnt = 0;
	stack = (element*)malloc(sizeof(element));
	while ((ch = fgetc(fp)) != EOF) {
		if (ch >= '0' && ch <= '9') {
			push(ch - '0');
			printf("push item: %c", ch);
			if (top - 1 == (int)(pow(2, cnt)) - 1) {
				printf("\tdoubling: %d", capacity);
				cnt++;
			}
			printf("\n");
		}
		else if (ch == 'D') {
			pop();
			if (isEmpty() == True) {
				printf("stack empty: cannot POP!");
				continue;
			}
			else printf("pop\n");
		}
		else continue;
		for (int i = 0; i <= top; i++)
			printf("[%2d]", stack[i]);
		printf("\n");
	}
}
