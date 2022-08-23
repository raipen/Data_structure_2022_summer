//왜인지 안됨
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Node* treePointer;
typedef struct Node {
	int data;
	treePointer left, right;
}node;

void insert(treePointer* treeNode, int key) {
	treePointer ptr = (*treeNode), temp = (node*)malloc(sizeof(node));
	temp->data = key;
	temp->left = NULL, temp->right = NULL;
	while (ptr) {
		if (key < temp->data) {
			if (ptr->left == NULL) {
				ptr->left = temp;
				return;
			}
			else
				ptr = ptr->left;
		}
		else {
			if (ptr->right == NULL) {
				ptr->right = temp;
				return;
			}
			else
				ptr = ptr->right;
		}
	}
}

char search(treePointer root, int key) {
	if (root == NULL) return 'X';
	if (key == root->data)
		return 'O';
	else if(key < root->data) 
		search(root->left, key);
	else 
		search(root->right, key);
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

void main() {
	FILE* f1 = fopen("in1.txt", "r"), *f2 = fopen("search.txt", "r");
	treePointer root = (node*)malloc(sizeof(node));
	int input;
	fscanf(f1, "%d", &input);
	root->data = input;
	root->left = NULL, root->right = NULL;
	while (!feof(f1)) {
		fscanf(f1, "%d", &input);
		insert(root, input);
	}
	fclose(f1);
	printf("Binary search tree(Inorder):");
	inorder(root);
	while (!feof(f2)) {
		fscanf(f2, "%d", &input);
		printf("%d: %c\n", input, search(root, input));
	}
}
