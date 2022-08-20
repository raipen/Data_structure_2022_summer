// 작동 안 됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int coef, expon;
    struct NODE* next;
}NODE;

NODE* InsertHead(NODE* head, int a, int b)
{
    NODE* temp = head;
    NODE* new = (NODE*)malloc(sizeof(NODE));
    new->coef = a;
    new->expon = b;
    new->next = NULL;
    if (temp == NULL) {
        temp = new;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
    return head;
}

NODE* padd(NODE* head1, NODE* head2)
{
    NODE* head3 = (NODE*)malloc(sizeof(NODE));
    NODE* temp = head3;
    while (head1 != NULL || head2 != NULL) {
        NODE* new = (NODE*)malloc(sizeof(NODE));
        new->next = NULL;
        if (head1->expon > head2->expon) {
            new->coef = head1->coef;
            new->expon = head1->expon;
            head1 = head1->next;
        }
        else if (head1->expon < head2->expon) {
            new->coef = head2->coef;
            new->expon = head2->expon;
            head2 = head2->next;
        }
        else {
            new->coef = head1->coef + head2->coef;
            new->expon = head1->expon + head2->expon;
            head1 = head1->next;
            head2 = head2->next;
        }

        if (temp == NULL)
            temp = new;
        else {
            temp->next = new;
        }
    }
    return head3;
}

void printList(NODE* head)
{
    NODE* temp = head;
    if (temp == NULL) {
        printf("empty list");
        return 0;
    }
    while (temp != NULL) {
        printf("[%d,%d] ", temp->coef, temp->expon);
        temp = temp->next;
    }
    printf("\n");
}

void erase(NODE* head)
{
    NODE* temp = head;
    while (head != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
}

void main()
{
    int a, b;
    NODE* head1 = (NODE*)malloc(sizeof(NODE));
    NODE* head2 = (NODE*)malloc(sizeof(NODE));
    NODE* head3;
    FILE* fp1, * fp2;
    if ((fp1 = fopen("poly1.txt", "r")) == NULL) {
        printf("ERROR1");
        return 0;
    }
    while ((fscanf(fp1, "%d %d", &a, &b)) != EOF) {
        head1 = InsertHead(head1, a, b);
    }
    fclose(fp1);
    if ((fp2 = fopen("poly1.txt", "r")) == NULL) {
        printf("ERROR1");
        return 0;
    }
    while ((fscanf(fp2, "%d %d", &a, &b)) != EOF) {
        head2 = InsertHead(head2, a, b);
    }
    fclose(fp2);

    head3 = padd(head1, head2);
    printf("%10s", "poly A:");
    printList(head1);
    printf("%10s", "poly B:");
    printList(head2);
    printf("%10s", "poly(A+B):");  
    printList(head3);

    erase(&head1);
    erase(&head2);
    erase(&head3);

    printf("\n삭제>>\n");
    printf("%10s", "poly A:");
    printList(head1);
    printf("%10s", "poly B:");
    printList(head2);
    printf("%10s", "poly(A+B):");
    printList(head3);
}
