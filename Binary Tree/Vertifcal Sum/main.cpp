#include <stdio.h>
#include <stdlib.h>

/* under geeksforgeeks solution, hashMap keep track of each element in sum */
struct node {
	int data;
	node* left;
	node* right;
};

struct nodeList {
	int data;
	nodeList *next;
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

void printList(nodeList *head) {
	if (head == NULL) return;
	
	nodeList *tmp = head;
	while (tmp != NULL)
	{
		printf("%d ", tmp->data);
		tmp= tmp->next;
	}
}

nodeList* pushInHead(nodeList *head, int data) {
	nodeList *newNode = (nodeList*) malloc(sizeof(nodeList));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL)
		return newNode;

	newNode->next = head;
	head = newNode;
}

bool isDataInList(nodeList *head, int data) {
	if (head == NULL)
		return false;

	nodeList *tmp = head;
	while (tmp != NULL) {
		if (tmp->data == data)
			return true;
		tmp = tmp->next;
	}
	return false;
}


void getAllHDHelper(node *root,int currentHD, int printHD, int *sum) {
	if (root == NULL) return;

	if (printHD == currentHD)
		*sum += root->data;
	getAllHDHelper(root->left, currentHD - 1, printHD, sum);
	getAllHDHelper(root->right, currentHD + 1, printHD, sum);
}

void getAllHD(node *root, nodeList **head, int printHD) {
	
	if (root == NULL) return;

	if (!isDataInList(*head,printHD))
		*head = pushInHead(*head, printHD);

	getAllHD(root->left,head,printHD-1);
	getAllHD(root->right,head,printHD+1);

}



//get all HD
void printVerticalHelper(node *root, nodeList* head) {
	if ((head == NULL) || (root == NULL))
		return;

	while (head  != NULL) {
		int sum = 0;
		int currentHD = 0;
		getAllHDHelper(root,currentHD,head->data,&sum);
		printf("Horizontal Distance %d: %d\n", head->data,sum);
		head = head->next;
	}
}

// rootHD: horizontal distance of root
// printHD: requierement of distance to printout
void printVertialSum(node* root, int rootHD, int printHD, int *sum) {
	if (root == NULL)
		return;
	


	// from here root != NULL
	if (rootHD == printHD) {
		*sum += rootHD;
	}

	printVertialSum(root->left, rootHD-1, printHD, sum);
	printVertialSum(root->right,rootHD+1, printHD, sum);
}



void main() {

	node* root = newNode(1);
	node* left_1 = newNode(2);
	node* left_2_1 = newNode(4);
	node* left_2_2 = newNode(5);
	node* right_1 = newNode(3);
	node* right_2_3 = newNode(6);
	node* right_2_4 = newNode(7);
	

	root->left = left_1;
	left_1->left = left_2_1;
	left_1->right = left_2_2;
	root->right = right_1;
	right_1->left = right_2_3;
	right_1->right = right_2_4;
	printTree(root);
	printf("\n");
	
	nodeList *head = NULL;
	getAllHD(root,&head,0);
	printList(head);
	printf("\n");
	
	printVerticalHelper(root,head);
	
	
	
	getchar();
}

