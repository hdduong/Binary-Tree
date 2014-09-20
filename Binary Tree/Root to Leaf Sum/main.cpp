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


bool isEqualGivenSum(node* root, int number, int prevSum) {
	if (root == NULL) {
		if (number == 0) return true;
		else return false;
	}

	bool isEqualLeft = false;
	bool isEqualRight = false;
	int leftSum = 0;
	int rightSum = 0;

	if ((root->left == NULL) && (root->right == NULL)) { //leaf node
		if (prevSum + root->data == number)
			return true;
		else
			return false;
	}
	if (root->left != NULL) {
		leftSum = root->data + prevSum;
		isEqualLeft = isEqualGivenSum(root->left,number,leftSum);
	}
	if (root->right!= NULL) {
		rightSum = root->data + prevSum;
		isEqualRight = isEqualGivenSum(root->right,number,rightSum);
	}
	return (isEqualLeft || isEqualRight);
}

void main() {

	node* root = newNode(10);
	node* left_1 = newNode(8);
	node* left_2_1 = newNode(3);
	node* left_2_2 = newNode(5);
	node* right_1 = newNode(2);
	node* right_2_3 = newNode(2);
	

	root->left = left_1;
	left_1->left = left_2_1;
	left_1->right = left_2_2;
	root->right = right_1;
	right_1->left = right_2_3;
	

	printTree(root);
	printf("\n");
	
	int givenNumber = 12; 
	bool resultEqual = isEqualGivenSum(root,givenNumber,0);
	printf("%s \n",(resultEqual)?"Yes":"No");

	getchar();
}

