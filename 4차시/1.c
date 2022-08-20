// 역순으로 프린트됨
// doubling 구현 실패
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int data;
    int cap;
    struct NODE* next;
}NODE;

NODE* top;
int cnt = 0;

void initialize()
{

}

int IsFull()
{
    if (cnt > 100) {
        printf("stack full: cannot PUSH!");
        return 1;
    }
    return 0;
}

int IsEmpty()
{
    if (top == NULL) {
        printf("stack empty: cannot POP!");
        return 1;
    }   
    return 0;
}

void Push(int data)
{
    cnt++;
    printf("push item: %d\n", data);
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->data = data;
    new->next = top;
    top = new;    
}

void Pop()
{
    cnt--;
    printf("pop\n");
    NODE* ntop = top;
    top = ntop->next;
    free(ntop);
}

void StackPrint()       // 역순 출력 안됨
{
    /*  
    NODE* p, * q, * r;
    p = top;
    q = NULL;
    while (p != NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    */
  
    NODE* temp = top;
    while (temp != NULL) {
        printf("[ %d]", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main()
{
    char p;
    int d;
    NODE* stack = (NODE*)malloc(sizeof(NODE));
    FILE* fp;
    if ((fp = fopen("in.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }
    
    while ((fscanf(fp, "%c ", &p)) != EOF) {
        if (p == 'I') {
            if (IsFull() == 1)
                return 0;
            else {
                fscanf(fp, "%d ", &d);
                Push(d);
            } 
        }
        else if (p == 'D') {
            if (IsEmpty() == 1)
                return 0;
            else
                Pop();
        }
        StackPrint();
    }
    fclose(fp);
}
