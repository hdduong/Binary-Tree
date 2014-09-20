#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	node* left;
	node* right;
};

struct queueNode {
	node* treeNode;
	queueNode* next;
};

node* newNode(int data) {
	node* aNode = (node*)malloc(sizeof(node));
	aNode->data = data;
	aNode->left = aNode->right = NULL;
	return aNode;
}


queueNode* newQueueNode(node* node) {
	queueNode* aNode = (queueNode*)malloc(sizeof(queueNode));
	aNode->treeNode = node;
	aNode->next = NULL;

	return aNode;
}


void printTree(node *root) {
	if (root == NULL)
		return;
	printTree(root->left);
	printf("%d ",root->data);
	printTree(root->right);
}

void addToQueue(queueNode **head, node *nodeAdd) {
	if (*head == NULL) {
		*head = newQueueNode(nodeAdd);
		(*head)->next = NULL;
		return;
	}
	queueNode* lastNode = *head;
	while(lastNode->next != NULL)
		lastNode = lastNode->next;
	lastNode->next = newQueueNode(nodeAdd);
}

queueNode* popNode(queueNode **head) {
	queueNode* popNode = *head;
	*head = (*head)->next;

	return popNode;
}

void printLevelTree(node* root, queueNode *head) {
	addToQueue(&head,root);
	while(head != NULL) {
		queueNode* levelNode = popNode(&head);
		printf("%d ", levelNode->treeNode->data);

		if(levelNode->treeNode->left != NULL) {
			addToQueue(&head,levelNode->treeNode->left);
		}
		
		if(levelNode->treeNode->right != NULL) {
			addToQueue(&head,levelNode->treeNode->right);
		}

		free(levelNode);
	}
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
	printf("\n");

	queueNode *head = NULL; 
	printLevelTree(root, head);
	if(head != NULL) {
		head = NULL;
		free(head);
	}

}