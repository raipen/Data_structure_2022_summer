#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Infix: (((1+2*3)%4-5)*8)-9
Postfix: 123*4%58*9
Infix: 1+2*3*4+5-6%9/2
Postfix: 1-23*4*5+69%2
Infix: (1+2)-(3-4)+(5-6)*2
Postfix: 1/2+3-4-5+62
Infix: 9-(8/7+2)+((2+3*4)/5-7)
Postfix: 9*87/2+2+34*5/7
*/



int top = 0;

int compare(char cal);
void push(char stack[],  char pu);
char pop(char stack[]);
int isempty(char stack[]);
char peek(char stack[]);

void main()
{
	FILE* fp;
	char cal[100] = { NULL };
	char stack[20] = { NULL };
	if ((fp = fopen("infix.txt", "r")) == NULL)
	{
		printf("cannot find the file");
		return 0;
	}
	for (int i = 0;i < 4;i++) {
		fscanf(fp, "%s", cal);// 파일 1줄 받음.
		printf("Infix: %s\n",cal);//infix 출력.
		printf("Postfix: ");
		for (int j = 0;j < strlen(cal);j++) {
			if (cal[j] >= '0' && cal[j] <= '9')//숫자일 경우
				printf("%c", cal[j]);
			else { //연산자일 경우
				if(compare(cal[j]) <= compare(peek(stack)))
				{
					if (cal[j] == '(' || cal[j] == ')') continue;
					printf("%c", pop(stack));
					push(stack, cal[j]);
				}
				else  push(stack, cal[j]);
			}

		}
		if (isempty(stack) == 0)
		{
			for (int i = 0; i < strlen(stack)+1;i++)
			{
				if (stack[i] == '('||stack[i]==')') continue;
				else { 
					printf("%c", stack[i]);
				}
			}
		}
		printf("\n");
	}

	fclose(fp);
}

int compare(char cal)
{
	switch (cal)
	{
		case '*': case '/': case '%':
			return 3;
		case '+': case '-':
			return 2;
		case '(': case ')':
			return 1;
	}
}

void push(char stack[], char pu)
{
	top++;
	stack[top] = pu;
}

char pop(char stack[])
{
	if (isempty(stack) == 1) return -1;
	else {
		top--;
		return stack[top+1];
	}
}

int isempty(char stack[])
{
	if (top == -1) return 1;//empty
	else return 0;
}

char peek(char stack[])
{
	if (isempty(stack) == 0) return stack[top];
	else return 0;
}

