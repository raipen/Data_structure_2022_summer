#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
element* stack, capacity = 1, top = -1;
enum bool{ False, True };
typedef enum bool Boolean;

Boolean isFull() {
	if (top == capacity) return True;
	else return False;
}

Boolean isEmpty() {
	if (top < 0) return True;
	else return False;
}

void stackFull() {
	stack = (element*)realloc(stack, 2 * capacity * sizeof(element));
	capacity *= 2;
}

void push(element item) {
	if (isFull()) stackFull();
	stack[++top] = item;
}

void pop() {
	stack[top--];
}

void main() {
	FILE* fp = fopen("in.txt", "r");
	char ch;
	stack = (element*)malloc(sizeof(element));
	while ((ch = fgetc(fp)) != EOF) {
		if (ch >= '0' && ch <= '9') {
			push(ch - '0');
			printf("push item: %c", ch);
			if (isFull(fp))
				printf("\tdoubling: %d", capacity);
			printf("\n");
		}
		else if (ch == 'D') {
			pop();
			if (isEmpty()) printf("stack empty: cannot POP!");
			else printf("pop\n");
		}
		else continue;
		for (int i = 0; i < capacity; i++)
			printf("[%2d]", stack[i]);
		printf("\n");
	}
}
//덜했습니다... 죄송합니다...........
