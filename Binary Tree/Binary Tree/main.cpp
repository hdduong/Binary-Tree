#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	node* left;
	node* right;
};


node* newNode(int data) {
	node* aNode = (node*)malloc(sizeof(node));
	aNode->data = data;
	aNode->left = aNode->right = NULL;
	return aNode;
}


void printTree(node *root) {
	if (root == NULL)
		return;
	printTree(root->left);
	printf("%d ",root->data);
	printTree(root->right);
}


node* mirrorTree(node* root) {
	if (root == NULL) return NULL;
	node* rootRight = mirrorTree(root->right);
	node* rootLeft = mirrorTree(root->left);

	root->left = rootRight;
	root->right = rootLeft;
	return  root;
}

void main() {

	node* root = newNode(1);
	node* left_1 = newNode(3);
	node* right_1 = newNode(2);
	node* right_2_3 = newNode(5);
	node* right_2_4 = newNode(4);

	root->left = left_1;
	root->right = right_1;
	right_1->left = right_2_3;
	right_1->right = right_2_4;

	printTree(root);
	root  = mirrorTree(root);
	printf("\n");
	printTree(root);
	
	getchar();
}