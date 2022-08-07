#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int contents;
typedef enum {LINEAR, CIRCULAR} queueType;
typedef struct {
    contents* queue;
    queueType type;
    int front;
    int rear;
    int size;
}queue;

int isEmpty(queue* this) {
    return (this->front == this->rear) ? 1 : 0;
}

int isFull(queue* this) {
    return this->type == CIRCULAR ? (((this->rear + 1) % this->size == this->front % this->size) ? 1 : 0 ): ((this->rear==this->size) ? 1 : 0);
}

queue* newQueue(int n,char type) {
    queue* temp = (queue*) malloc(sizeof(queue));
    temp->queue = (contents*) calloc(n, sizeof(contents));
    temp->type = type == 'c' ? CIRCULAR:LINEAR;
    temp->front = temp->rear = 0;
    temp->size = n;
    return temp;
}

void printq(queue* this) {
    if (isEmpty(this)) {
        printf("%s queue is empty\n", this->type == CIRCULAR ? "Circular" : "List");
        return;
    }
    printf(this->type == CIRCULAR?"Circular queue: ":"List queue: ");
    for (int i = this->front;i <= this->rear - 1;i++) {
        printf("%d ", this->queue[i % this->size]);
    }
    printf("\n");
}

void addq(queue* this, contents con) {
    if (isFull(this)) {
        printf("%s queue is full\n",this->type == CIRCULAR? "Circular":"List");
        return;
    }
    this->queue[this->type == CIRCULAR? (this->rear++) % this->size :(this->rear++)] = con;
    printq(this);
}

void deleteq(queue* this) {
    if (isEmpty(this)) {
        printf("%s queue is empty\n", this->type == CIRCULAR ? "Circular" : "List");
        return;
    }
    this->front++;
    printq(this);
}

void deleteQueue(queue* this) {
    free(this->queue);
    free(this);
}


void main() {

    char input;
    int value;
    printf("input size: ");
    scanf("%d", &value);
    queue* Cq = newQueue(value,'c'); //Circular queue »ý¼º
    queue* Lq = newQueue(value, 'l'); //List queue »ý¼º
    printf("Queue size: %d\n", value);
    while (1) {
        printf("input: ");
        scanf(" %c", &input);
        switch (input) {
        case 'a':
            scanf("%d", &value);
            addq(Cq, value);
            addq(Lq, value);
            break;
        case 'd':
            deleteq(Cq);
            deleteq(Lq);
            break;
        case 'q':
            printf("quit\n");
            deleteQueue(Cq);
            deleteQueue(Lq);
            return;
        }
    }
}