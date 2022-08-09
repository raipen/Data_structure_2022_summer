#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data;
	struct NODE* left;
	struct NODE* right;
}node;

void inorder(node* ptr)
{
	if (ptr != NULL) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(node* ptr)
{
	if (ptr != NULL) {
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(node* ptr)
{
	if (ptr != NULL) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}

void main()
{

	//root
	node* root = (node*)malloc(sizeof(node));
	root->data = 0;
	//left
	root->left = (node*)malloc(sizeof(node));
	root->left->data = 1;
	root->right = (node*)malloc(sizeof(node));
	root->right->data = 2;
	root->left->left = (node*)malloc(sizeof(node));
	root->left->left->data = 3;
	root->left->right = (node*)malloc(sizeof(node));
	root->left->right = NULL;
	root->left->left->left = (node*)malloc(sizeof(node));
	root->left->left->left = NULL;
	root->left->left->right = (node*)malloc(sizeof(node));
	root->left->left->right->data = 6;
	root->left->left->right->left = (node*)malloc(sizeof(node));
	root->left->left->right->left = NULL;
	root->left->left->right->right = (node*)malloc(sizeof(node));
	root->left->left->right->right = NULL;
	root->right->left = (node*)malloc(sizeof(node));
	root->right->left->data = 4;
	root->right->right = (node*)malloc(sizeof(node));
	root->right->right->data = 5;
	root->right->left->left = (node*)malloc(sizeof(node));
	root->right->left->left->data = 7;
	root->right->left->right = (node*)malloc(sizeof(node));
	root->right->left->right->data = 8;
	root->right->right->left = (node*)malloc(sizeof(node));
	root->right->right->left = NULL;
	root->right->right->right = (node*)malloc(sizeof(node));
	root->right->right->right = NULL;
	root->right->left->left->left = (node*)malloc(sizeof(node));
	root->right->left->left->left = NULL;
	root->right->left->left->right = (node*)malloc(sizeof(node));
	root->right->left->left->right = NULL;
	root->right->left->right->left = (node*)malloc(sizeof(node));
	root->right->left->right->left = NULL;
	root->right->left->right->right = (node*)malloc(sizeof(node));
	root->right->left->right->right->data = 9;
	root->right->left->right->right->left = (node*)malloc(sizeof(node));
	root->right->left->right->right->left = NULL;
	root->right->left->right->right->right = (node*)malloc(sizeof(node));
	root->right->left->right->right->right =NULL;

	printf("inorder: ");
	inorder(root);
	printf("\n");

	printf("preorder: ");
	preorder(root);
	printf("\n");

	printf("postorder: ");
	postorder(root);
}
