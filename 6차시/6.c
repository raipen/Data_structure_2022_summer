#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
   struct TreeNode* left;
   int data;
   struct TreeNode* right;
}TreeNode;

void inorder(TreeNode* ptr) {
   if (ptr != NULL) {
      inorder(ptr->left);
      printf("%d ", ptr->data);
      inorder(ptr->right);
   }
}

void postorder(TreeNode* ptr) {
   if (ptr != NULL) {
      postorder(ptr->left);
      postorder(ptr->right);
      printf("%d ", ptr->data);
      
   }
}
void preorder(TreeNode* ptr) {
   if (ptr != NULL) {
      printf("%d ", ptr->data);
      preorder(ptr->left);
      preorder(ptr->right);
      

   }
}

void main() {
   TreeNode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10;

   n1 = (TreeNode*)malloc(sizeof(TreeNode));
   n2 = (TreeNode*)malloc(sizeof(TreeNode));
   n3 = (TreeNode*)malloc(sizeof(TreeNode));
   n4 = (TreeNode*)malloc(sizeof(TreeNode));
   n5 = (TreeNode*)malloc(sizeof(TreeNode));
   n6 = (TreeNode*)malloc(sizeof(TreeNode));
   n7 = (TreeNode*)malloc(sizeof(TreeNode));
   n8 = (TreeNode*)malloc(sizeof(TreeNode));
   n9 = (TreeNode*)malloc(sizeof(TreeNode));
   n10 = (TreeNode*)malloc(sizeof(TreeNode));
   
   //0기준 왼쪽 노드들
   n1->data = 0;
   n1->left = n2;
   n1->right = n5;

   n2->data = 1;
   n2->left = n3;
   n2->right = NULL;
   n3->data = 3;

   n3->left = NULL;
   n3->right = n4 ;
   n4->data = 6;
   n4->left = NULL;
   n4->right = NULL;

   //0기준 오른쪽 노드들
   n5->data = 2;
   n5->left = n6;
   n5->right = n7;

   n6->data = 4;
   n6->left = n8;
   n6->right = n9;
   
   n7->data = 5;
   n7->left = NULL;
   n7->right = NULL;

   n8->data = 7;
   n8->left = NULL;
   n8->right = NULL;

   n9->data = 8;
   n9->left = NULL;
   n9->right = n10;

   n10->data = 9;
   n10->left = NULL;
   n10->right = NULL;

   printf("inorder:");
   inorder(n1);
   printf("\n");
   printf("preorder:");
   preorder(n1);
   printf("\n");
   printf("postorder:");
   postorder(n1);


   free(n1);
   free(n2);
   free(n3);
   free(n4);
   free(n5);
   free(n6);
   free(n7);
   free(n8);
   free(n9);
   free(n10);

}
