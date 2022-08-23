#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* treePointer;
typedef struct Node {
	int data;
	treePointer left, right;
}node;

void create(treePointer *p, int input) {
	*p = (node*)malloc(sizeof(node));
	(*p)->left = NULL, (*p)->right = NULL;
	(*p)->data = input;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		printf("%d ", ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ", ptr->data);
	}
}

void main() {
	treePointer root = (node*)malloc(sizeof(node));
	root->data = 0;
	create(&(root->left), 1);
	create(&(root->right), 2);
	create(&(root->left->left), 3);
	create(&(root->left->left->right), 6);
	create(&(root->right->left), 4);
	create(&(root->right->right), 5);
	create(&(root->right->left->left), 7);
	create(&(root->right->left->right), 8);
	create(&(root->right->left->right->right), 9);
	printf("inorder:");
	inorder(root);printf("\n");
	printf("preorder:");
	preorder(root); printf("\n");
	printf("postorder:");
	postorder(root);
}
