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

void toDDL(node* root, node** head, node** back, bool* needPrune) {
	if (root == NULL) return;

	if ((root->left== NULL) && (root->right == NULL)) {
		*needPrune = true;
		
		if (*head ==NULL) { //1st leav
			*head = root;
			*back = root;
		}
		else {
			if((*head)->right == NULL)
				(*head)->right = root;
			(*back)->right = root;
			root->left= (*back);
			(*back) = root;
		}
		return;
	}
	*needPrune = false;
	toDDL(root->left, head,back, needPrune);
	if(*needPrune)
		root->left = NULL;

	*needPrune = false;
	toDDL(root->right, head,back,needPrune);
	if(*needPrune)
		root->right = NULL;

	*needPrune = false;
	return;
}

void printDLL(node* head, node* back) {
	node* tmp = head;
	while(tmp != back) {
		printf("%d ", tmp->data);
		tmp=tmp->right;
	}
	printf("%d ", tmp->data);
}
void main() {

	node* root = newNode(1);
	node* left_1 = newNode(2);
	node* left_2_4 = newNode(4);
	node* left_2_5 = newNode(5);
	node* left_3_7 = newNode(7);
	node* left_3_8 = newNode(8);

	node* right_1 = newNode(3);
	node* right_2_3 = newNode(6);
	node* right_3_1 = newNode(9);
	node* right_3_2 = newNode(10);
	

	root->left = left_1;
	left_1->left = left_2_4;
	left_1->right = left_2_5;
	left_2_4->left = left_3_7;
	left_2_4->right = left_3_8;

	root->right = right_1;
	right_1->right = right_2_3;
	right_2_3->left = right_3_1;
	right_2_3->right = right_3_2;

	printTree(root);
	printf("\n");
	
	node* head = NULL;
	node* back = NULL;
	bool needPrune = false;
	toDDL(root,&head,&back,&needPrune);
	
	printTree(root);
	printf("\n");
	
	printDLL(head,back);

	getchar();

}

