#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct stack {
	int top;
	int* data;
	int capacity;
}stack;

void initialize(stack* sta);
int IsEmpty(stack* sta);
int IsFull(stack* sta);
void push(stack* sta, int val);
void pop(stack* sta);
void printstack(stack* sta);

void main()
{
	FILE* fp;
	stack stack;
	char che = 0;
	int val = 0;
	if ((fp = fopen("in.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}
	initialize(&stack);
	while (fscanf(fp, "%c", &che) != EOF)
	{
		if (che == 'I')
		{
			fscanf(fp, "%d", &val);
			if(IsFull(&stack)==1)printf("push item: %d ", val);
			else printf("push item: %d\n", val);
			push(&stack,val);
			printstack(&stack);
		}
		else if (che == 'D')
		{
			printf("pop\n");
			pop(&stack);
			printstack(&stack);
		}
	}
	fclose(fp);
}

void initialize(stack* sta)//data에 동적할당
{
	sta->data = (int*)malloc(sizeof(int) * 1);
	sta->top = -1;
	sta->capacity = 1;
}

int IsEmpty(stack* sta) {
	if (sta->top <= -1)
		return 1;//empty(원래 top 값이 -1이므로)
	else
		return 0;//empty x(stack에 값이 들어있음)
}

int IsFull(stack* sta) {
	if (sta->top >= sta->capacity - 1)
		return 1;//full(capacity-1은 full일때의 pop의 위치)
	else
		return 0;//full x(full이 아님)
}

void push(stack* sta, int val)
{
	if (sta->top < sta->capacity - 1)//full이 아닌경우
	{
		sta->top++;
		sta->data[sta->top] = val;
	}
	else
	{
		sta->capacity=sta->capacity*2;
		sta->data = (int*)realloc(sta->data, sta->capacity * sizeof(int));
		printf("doubling: %d\n", sta->capacity);
		push(sta, val);
	}
}

void pop(stack* sta)
{
	if (IsEmpty(sta) == 1)
		printf("stack empty: cannot POP!\n");
	else
	{
		int value = sta->data[sta->top];
		sta->top--;
	}
}

void printstack(stack* sta)
{
	if (IsEmpty(sta) == 1)
	{
		printf("stack is empty\n");
	}
	else
	{
		printf("%d ", sta->top + 1);//stacksize
		for (int i = sta->top; i >=0;i--)
		{
			printf("[%d]", sta->data[sta->top - i]);
		}
		printf("\n");
	}
}
