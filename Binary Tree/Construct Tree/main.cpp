// pre[] = {10, 30, 20, 5, 15},  preLN[] = {'N', 'N', 'L', 'L', 'L'}
#include <stdlib.h>
#include <stdio.h>

#define N 5

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

// Pre-order
void printTree(node *root) {
	if (root == NULL)
		return;
	printf("%d ",root->data);
	printTree(root->left);
	printTree(root->right);
}

node* createTree(node *root, int* pre, char* preLN, int *startPre) {
	if (*startPre > N)	// no more node 
		return NULL; 

	//ceate all subtrees here
	if (preLN[*startPre] == 'L') {
		node* tmp = newNode(pre[*startPre]);
		*startPre = *startPre + 1;
		return tmp;
	}
	else if (preLN[*startPre] == 'N') { // two kids
		root = newNode(pre[*startPre]);
		
		*startPre = *startPre + 1; //next in list
		
		root->left = createTree(root->left,pre, preLN, startPre); 
		root->right = createTree(root->right,pre, preLN, startPre); 
		return root;
	}
	return NULL;
}

void main() {
	int* pre = (int*)malloc(N * sizeof(int));
	char* preLN = (char*)malloc(N * sizeof(char));
	
	pre[0] = 10; pre[1]=30; pre[2] = 20; pre[3] = 5; pre[4] = 15;
	preLN[0] = 'N'; preLN[1]='N'; preLN[2] = 'L'; preLN[3] = 'L'; preLN[4] = 'L';

	node* root = NULL;
	int startLeftPre = 0;
	root = createTree(root,pre,preLN,&startLeftPre);
	

	printTree(root);
	printf("\n");
}