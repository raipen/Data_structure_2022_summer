#include <stdio.h>
#include <stdlib.h>

typedef enum {CHAR,INT} TYPE;
typedef struct {
    TYPE type;
    union {
        int i;
        char c;
    } data;
} element;
typedef enum {FALSE,TRUE} BOOL;
typedef struct{
    element* data;
    int top,capacity;
}stack;

stack* newStack(){
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->top = -1;
    temp->capacity = 1;
    temp->data = (element*)malloc(sizeof(element)*temp->capacity);
    return temp;
}

BOOL isFull(stack* s){
    return (s->capacity-1 == s->top);
}

BOOL isEmpty(stack* s){
    return s->top == -1;
}

void push(stack* s,element value){
    if(isFull(s)){
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(element) * (s->capacity));
    }
    s->data[++(s->top)] = value;
}

element pop(stack* s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty: connot POP!");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(stack* s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty: connot POP!");
        exit(1);
    }
    return s->data[(s->top)];
}

void printElement(element item){
    if(item.type==CHAR)
        printf("%c",item.data.c);
    else
        printf("%d",item.data.i);
}

void printStack(stack* s){
    while(!isEmpty(s))
        printElement(pop(s));
    printf("\n");
}

char* readInfixFromFile(FILE* filePointer){
    char* str = (char*)malloc(sizeof(char)*100);
    fscanf(filePointer, "%s", str);
	return str;
}

BOOL isNumber(char c){
    return (c>='0' && c<='9');
}

typedef enum { lparlen, rparlen, plus, minus, times, divide, mod, eos, operand } precedence;
int OP[] = { 0, 19, 12, 12, 13, 13, 13, 0 };
int IP[] = { 20, 0, 12, 12, 13, 13, 13, 0 };

precedence getToken(char operator) {
    switch (operator) {
    case'(':
        return lparlen;
    case')':
        return rparlen;
    case'+':
        return plus;
    case'-':
        return minus;
    case'/':
        return divide;
    case'*':
        return times;
    case'%':
        return mod;
    case'\0':
        return eos;
    default:
        return operand;
    }
}

int inPrecedence(char operator){
    return IP[getToken(operator)];
}

int outPrecedence(char operator){
    return OP[getToken(operator)];
}

char* convertInfixToPostfix(char* infix){
    char* postfix = (char*)malloc(sizeof(char)*100);
    int indexOfPostfix = 0;

    stack* operatorStack = newStack();

    for(int i=0;infix[i];i++){  //infix의 문자들을 순서대로 확인함.
        if(isNumber(infix[i]))
            postfix[indexOfPostfix++] = infix[i];   //숫자는 바로 출력
        else{
            //연산자는 지보다 높거나 같은게 먼저 드가있으면 걔가 먼저 계산되어야 하니까 빼내줘야함.
            int curPrecedence = inPrecedence(infix[i]);
            while(!isEmpty(operatorStack)&&outPrecedence(peek(operatorStack).data.c)>=curPrecedence){
                char temp = pop(operatorStack).data.c;
                if(temp=='(')
                    break;
                postfix[indexOfPostfix++] = temp;
            }
            //그 담에 지보다 더 우선순위 높은게 뒤에 올수도 있으니 일단 무조건 push 해놔야함
            if(infix[i]!=')'){
                element temp = {CHAR,{infix[i]}};
                push(operatorStack,temp);
            }
        }
    }

    while(!isEmpty(operatorStack))//스택에 남은거 전부 출력
        postfix[indexOfPostfix++] = pop(operatorStack).data.c;
    postfix[indexOfPostfix] ='\0';
    return postfix;
}

int EvaluationPostfix(char* postfix){
    stack* valueStack = newStack();
    for(int i=0;postfix[i];i++){
        if(isNumber(postfix[i])){
            element temp = {INT,{postfix[i]-'0'}};
            push(valueStack,temp);
        }else{
            int a = pop(valueStack).data.i;
            int b = pop(valueStack).data.i;
            int v;
            switch(postfix[i]){
                case '+': v = b + a;break;
                case '-': v = b - a;break;
                case '*': v = b * a;break;
                case '/': v = b / a;break;
                case '%': v = b % a;break;
            }
            element temp = {INT,{v}};
            push(valueStack,temp);
        }
    }
    return pop(valueStack).data.i;
}


int main(void){
    FILE* filePointer = fopen("infix.txt", "r");
    while(!feof(filePointer)){
        char* infix = readInfixFromFile(filePointer);
        char* postfix = convertInfixToPostfix(infix);
        int calculationResult = EvaluationPostfix(postfix);

        printf("Infix: %s\n", infix);
        printf("Postfix: %s\n", postfix);
        printf("Evaluation: %d\n\n",calculationResult);

        free(infix);
        free(postfix);
    }
}