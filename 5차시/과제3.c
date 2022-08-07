#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct n {
    element value;
    struct n* next;
}node;

node* newLinkedList() {
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}

node* insertFirst(node* head, element value) {
    node* temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = head;
    return temp;
}

void printNode(node* head) {
    while (head != NULL) {
        printf("%4d", head->value);
        head = head->next;
    }
    printf("\n");
}

void deleteLinkedList(node* head) {
    node* cur = head;
    while (cur != NULL) {
        node* temp = cur;
        cur = cur->next;
        free(temp);
    }
}

void main() {
    FILE* fp = fopen("list.txt", "r");
    node* head = NULL;
    while (!feof(fp)) {
        int input;
        fscanf(fp, "%d", &input);
        if(!(input%2))                        //짝수 이면
            head = insertFirst(head, input);            //연결리스트 a 의 맨 앞에 temp값 추가
    }
    printf("짝수 리스트:\n");
    printNode(head);             //연결리스트 a 출력
    deleteLinkedList(head);
}