// 작동되지않음
// 후위표기법 프린트 구현 못함
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    char data;
    struct NODE* next;
}NODE;

NODE* ptop;
NODE* otop;

void PostfixPush(char i)
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = i;
    new->next = ptop;
    ptop = new;    
}

void OperatorsPush(char i)
{
    while(i=='+'||i=='-')
        if (otop == '*' || otop == '%' || otop == '/') {
            cal();
            return 0;
        }           
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = i;
    new->next = otop;
    otop = new;
}

void OperatorsCal()
{
    while (otop!=NULL) {
        if (otop == '(') {
            OperatorsPop();
            return 0;
        }
        cal();
    }
}

void Cal()
{
    int a = (ptop->data) - '0';
    PostfixPop();
    int b = (ptop->data) - '0';
    PostfixPop();
    char op = otop->data;
    OperatorsPop();
    switch (op) {
    case '+':
        PostfixPush((char)(a+b+'0'));
        break;
    case '-':
        PostfixPush((char)(a - b + '0'));
        break;
    case '*':
        PostfixPush((char)(a * b + '0'));
        break;
    case '%':
        PostfixPush((char)(a % b + '0'));
        break;
    case '/':
        PostfixPush((char)(a / b + '0'));
        break;    
    }
}

void PostfixPop()
{
    NODE* top = ptop;
    ptop = top->next;
    free(top);
}

void OperatorsPop()
{
    NODE* top = otop;
    otop = top->next;
    free(top);
}

void main()
{
    char infix;
    FILE* fp;
    if ((fp = fopen("infix.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }

    while ((fscanf(fp, "%c", &infix)) != EOF) {
        if ((infix - '0') >= 80) {
            PostfixPush(infix);
        }
        else {
            if (infix == ')') {
                OperatorsCal();
            }
            else
                OperatorsPop(infix);
        }
    }
    fclose(fp);
    printf("Ecaluation:%d", ptop);
}

/*
(((1+2*3)%4-5)*8)-9
1+2*3*4+5-6%9/2
(1+2)-(3-4)+(5-6)*2
9-(8/7+2)+((2+3*4)/5-7)
*/
