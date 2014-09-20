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

int toSumProperty(node *root) {
	if (root == NULL) return 0;
	if ((root->left == NULL) && (root->right == NULL))
		return root->data;

	int leftChildSum = (root->left == NULL) ? 0 : toSumProperty(root->left);
	int rightChileSum = (root->right == NULL) ? 0 : toSumProperty(root->right);

	int childSum = leftChildSum + rightChileSum;

	if (root->data == childSum) {
		return root->data;
	} else if (root->data < childSum) {
		root->data += (childSum - root->data);
	} else if (root->data > childSum) {
		if (root->left != NULL) {
			root->left->data += root->data - childSum;
			toSumProperty(root->left);
		}
		else if (root->right != NULL) {
			root->right->data += root->data - childSum;
			toSumProperty(root->right);
		}
	}
	return root->data;
}

void main() {

	node* root = newNode(50);
	node* left_1 = newNode(7);
	node* left_2_1 = newNode(3);
	node* left_2_2 = newNode(5);
	node* right_1 = newNode(2);
	node* right_2_3 = newNode(1);
	node* right_2_4 = newNode(30);

	root->left = left_1;
	left_1->left = left_2_1;
	left_1->right = left_2_2;
	root->right = right_1;
	right_1->left = right_2_3;
	right_1->right = right_2_4;

	printTree(root);
	printf("\n");
	
	toSumProperty(root);

	printTree(root);
	printf("\n");
	
	getchar();
}
