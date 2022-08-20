#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	int top;
	int* data;
	int capacity;
}Stack;


void Initialize(Stack* stk)
{
	stk->data = (int*)malloc(sizeof(int));
	stk->top = -1;
	stk->capacity = 1;
}

int isEmpty(Stack* stk) {
	if (stk->top == -1)
		return 1;
	return 0;
}

void pop(Stack* stk) {
	if (!isEmpty(stk))
		stk->top--;
}

void push(Stack* stk, int value) {

	if (stk->top < stk-> capacity - 1)
	{
		stk->top++;
		stk->data[stk->top] = value;
	}
	else
	{
		stk->capacity = stk->capacity * 2;
		stk->data = (int*)realloc(stk->data, stk->capacity * sizeof(int));
		printf("   doubling: %d", stk->capacity);
		push(stk, value);
	}
}

void printstack(Stack* stk){
	if(!isEmpty(stk))
	{
		for (int i = 0; i <= stk->top; i++)
			printf("[ %d] ", stk->data[i]);
		puts("");
	}
}

int main()
{
	Stack stack;
	Initialize(&stack);
	int num;
	char ch;
	FILE* f;
	if ((f = fopen("in.txt", "r")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	while (fscanf(f, "%c", &ch) != EOF) {
		
		if (ch =='|') {
			fscanf(f, "%d", &num);
			printf("push item: %d", num);
			push(&stack, num);
			puts("");
			printstack(&stack);
		}
		
		if (ch =='D') {
			printf("pop\n");
			pop(&stack);
			printstack(&stack);
		}
		
		if (isEmpty(&stack) == 1)
		{
			printf("stack empty : cannot POP!\n");
			break;
		}
	}

	fclose(f);
}
