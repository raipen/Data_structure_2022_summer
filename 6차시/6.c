// 작동 O (언젠가 함수구현 해볼 예정)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
}tree;

void inorder(tree* ptr)
{
    if (ptr != NULL) {
        inorder(ptr->left);
        printf("%d ", ptr->value);
        inorder(ptr->right);
    }
}

void preorder(tree* ptr)
{
    if (ptr) {
        printf("%d ", ptr->value);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(tree* ptr)
{
    if (ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->value);
    }
}

void main()
{
    tree* root = (tree*)malloc(sizeof(tree));
    root->value = 0;
    root->left = (tree*)malloc(sizeof(tree));
    root->left->value = 1;
    root->left->left = (tree*)malloc(sizeof(tree));
    root->left->left->value = 3;
    root->left->right = NULL;
    root->left->left->left = NULL;
    root->left->left->right = (tree*)malloc(sizeof(tree));
    root->left->left->right->value = 6;
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;
    root->right = (tree*)malloc(sizeof(tree));
    root->right->value = 2;
    root->right->left = (tree*)malloc(sizeof(tree));
    root->right->left->value = 4;
    root->right->right = (tree*)malloc(sizeof(tree));
    root->right->right->value = 5;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    root->right->left->left = (tree*)malloc(sizeof(tree));
    root->right->left->left->value = 7;
    root->right->left->left->left = NULL;
    root->right->left->left->right = NULL;
    root->right->left->right = (tree*)malloc(sizeof(tree));
    root->right->left->right->value = 8;
    root->right->left->right->left = NULL;
    root->right->left->right->right = (tree*)malloc(sizeof(tree));
    root->right->left->right->right->value = 9;
    root->right->left->right->right->left = NULL;
    root->right->left->right->right->right = NULL;

    printf("inorder:");
    inorder(root);
    printf("\npreorder:");
    preorder(root);
    printf("\npostorder:");
    postorder(root);
}
