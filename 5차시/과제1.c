//작동안됨..........포기

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[1000];
int top = -1;

int pop()
{
	if (top < 0)
		return top;
	return stack[top--];
}

char push(char token)
{
	stack[++top] = token;
}

int number(char token)
{
	if ('0' <= token && token <= '9')
		return 1;
	else
		return 0;
}

int inthestack(char token)
{
	switch (token)
	{
	case'(':
	case')':return 10;
	case'*':
	case'/':return 5;
	case'+':
	case'-':return 2;
	}
}

int Priority(char token)
{
	switch (token)
	{
	case'(':return 1;
	case')':return 10;
	case'*':
	case'/':return 5;
	case'+':
	case'-':return 2;
	}
}

void convert(char* infix, char* postfix)
{
	int cnt = 0;
	char token;

	for (int i = 0; infix[i] != 0; i++)
	{
		token = infix[i];
		if (number(token) == 1)
			postfix[cnt++] = token;
		else
		{
			if (token == ')')
			{
				while (postfix[cnt - 1] != '('){
					postfix[cnt++] = pop();
				}
				cnt--;
			}

			while (inthestack(stack[top]) > Priority(token)){
				postfix[cnt++] = pop();
			}

			push(token);
		}
	}

	while (postfix[cnt - 1] != NULL) {
		postfix[cnt++] = pop();
	}
}


int evaluate(char* postfix)
{
	char token, op1, op2;
	for (int i = 0; postfix[i] != 0; i++)
	{
		token = postfix[i];
		if (number(token) == 1)
			push(atoi(token));
		else
		{
			op1 = pop(), op2 = pop();
			switch (token)
			{
			case '*':
				push(op2 * op1);
				break;
			case '/':
				push(op2 / op1);
				break;
			case '+':
				push(op2 + op1);
			    break;
			case '-': 
				push(op2 -op1); 
				break;
			}
		}
	}

	return pop();
}

int main()
{
	char infix[1000], postfix[1000];
	stack[0] = 0;

	FILE* f;
	if ((f = fopen("infix.txt", "r")) == NULL)
	{
		printf("파일이 열리지 않습니다.\n");
		exit(1);
	}

	while (fscanf(f, "%s", infix) != EOF)
	{
		printf("Infix: %s\n", infix);
		convert(infix, postfix);
		printf("Postfix: %s\n", postfix);
		printf("Evaluation: %d\n", evaluate(postfix));
		puts("");
	}

	fclose(f);
}
