#include <stdlib.h>
#include <stdio.h>

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
	printf("%d ",root->data);
	printTree(root->left);
	printTree(root->right);
}

int getTreeSize(node *root) {
	if (root == NULL)
		return 0;
	return (1 + getTreeSize(root->left) + getTreeSize(root->right));
}


// level: level of key
void printPath(int key, int* arrPath, int level) {
	printf("at: %d: ",key);
	for (int i = level-1; i >= 0; i--) {
		printf("%d ", arrPath[i]);
	}
	printf("\n");
}

void printTreeAncestor(node* root, int *arrPath, int level) {
	if (root == NULL)
		return;

	arrPath[level] = root->data;
	printPath(root->data, arrPath,level);

	printTreeAncestor(root->left, arrPath, level+1);
	printTreeAncestor(root->right,arrPath,level+1);
}



void main() {

	node* root = newNode(1);
	node* left_1 = newNode(2);
	node* left_2_left = newNode(4);
	node* left_2_right = newNode(5);
	node* left_3_left = newNode(8);
	node* left_3_right = newNode(9);

	node* right_1 = newNode(3);
	node* right_2_3 = newNode(6);
	node* right_2_4 = newNode(7);
	node* right_3_1 = newNode(10);
	

	root->left = left_1;
	left_1->left = left_2_left;
	left_1->right = left_2_right;
	left_2_left->left = left_3_left;
	left_2_right->right = left_3_right;
	root->right = right_1;
	right_1->left = right_2_3;
	right_1->right = right_2_4;
	right_2_4->right = right_3_1;

	printTree(root);
	printf("\n");
	
	int treeSize = getTreeSize(root);
	printf("%d\n", treeSize);
	
	int* arrPath = (int*)malloc(sizeof(treeSize));
	printTreeAncestor(root,arrPath,0);
	
	getchar();

}



