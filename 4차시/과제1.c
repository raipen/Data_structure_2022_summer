#include <stdio.h>
#include <stdlib.h>

typedef int element;
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
        printf("\tdoubling: %d",s->capacity);
    }
    s->data[++(s->top)] = value;
}

element pop(stack* s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty: connot POP!");
        return -1;
    }
    return s->data[(s->top)--];
}

void printStack(stack* s){
    printf("\n");
    for(int i=0; i<=s->top; i++)
        printf("[%2d]", s->data[i]);
    printf("\n");
}

void pushWithPrint(stack* s,element value){
    printf("push item: %d",value);
    push(s,value);
    printStack(s);
}

void popWithPrint(stack* s){
    printf("pop");
    pop(s);
    printStack(s);
}

int main(void){
    stack* A = newStack();
    FILE* filePointer = fopen("in.txt", "r");
    char menu;
    int input;
    while(!feof(filePointer)){
        fscanf(filePointer,"%c ", &menu);
        switch (menu){
            case 'I':
            fscanf(filePointer,"%d", &input);
            pushWithPrint(A,input);
            break;
            case 'D':
            popWithPrint(A);
            break;
        }
    }
}