// 작동 안 됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NODE {
    int stu;
    char score[2];
    NODE* next;
}NODE;

NODE* top[5];

void Push(int num, int stu, char score[])
{
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->stu = stu;
    strcpy(new->score, score);

    if (top[num] == NULL) {
        new->next = NULL;
    }
    else {
        new->next = top[num];
    }
    top[num] = new;
}

void Pop(int num)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp = top[num];
    while (top[num != NULL]) {
        printf("pop from top[%d]: %d, %s",
            num, top[num]->stu, top[num]->score);
        top[num] = top[num]->next;
        free(temp);
    }
}

void main()
{
    int num, stu, i;
    char score[2];
    FILE* fp;
    if ((fp = fopen("score.txt", "r")) == NULL) {
        printf("ERROR");
        return 0;
    }

    while ((fscanf("%d %d %s", &num, &stu, score)) != EOF) {
        printf("push to top[%d]: %d, %s\n", num, stu, score);
        Push(num, stu, score);
    }

    for (i = 0;i <= 4;i++) {
        printf("[과목%d]:\n", i);
        Pop(i);
    }
}
