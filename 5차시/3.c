//작동되지 않음 ->  프린트 함수 에러
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}NODE;

NODE* insert(NODE* h, int d) {
    NODE* node, * p, * q;
    node = (NODE*)malloc(sizeof(NODE));
    node->data = d;

    p = h;
    q = h;
    while (p != NULL) {
        if (p->next > d)
            break;
        q = p;
        p = p->next;
    }

    if (p == h) {
        node->next = h;
        h = node;
    }
    else {
        node->next = p;
        q->next = node;
    }
    return h;
}

void printNode(NODE* h) {
    NODE* p;
    p = h;
    while (p != NULL) {
        printf("%d    ", p->data);  //에러발생
        p = p->next;
    }
    p = h;
  
    while (p != NULL) {
        h = h->next;
        free(p);
        p = h;
    }
    
    return 0;
}

int main(void)
{
    int a;
    NODE* h=NULL;
    h = (NODE*)malloc(sizeof(NODE));

    FILE* fp;
    if ((fp = fopen("list.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }

    while (fscanf(fp, "%d", &a) != EOF) {
        if (a % 2 == 0) {
            h = insert(h, a);
        }
    }

    fclose(fp);

    printNode(h);
}
