//미완..
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int code, num;
	char score[3];
}element;
typedef element* stackPointer;
typedef struct Stack {
	element data;
	stackPointer link;
}stack;
typedef enum { False, True }Boolean;
stackPointer top;
int capacity = 1;


Boolean isFull() {
	
}

Boolean isEmpty() {
	
}

element stackEmpty() {

}

void push(int i, element item) {
	stackPointer temp;
	temp = (element*)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
}

element pop(int i) {
	stackPointer temp = top[i];
	element item;
	if (!temp)
		return stackEmpty();
	item = temp->link;
	free(temp);
	return item;
}

void main() {
	FILE* fp = fopen("score.txt", "r");
	flcose(fp);
}
