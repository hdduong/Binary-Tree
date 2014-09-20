#include <stdlib.h>
#include <stdio.h>

//binary tree node
struct node {
	int data;
	node* left;
	node* right;

};



struct queue {
	int front; 
	int back;
	node **queueArr;
};



struct stack {
	int top;
	node **stackArr;
};



node* newNode(int data) {
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = data;
	tmp->left = tmp->right = NULL;
	return tmp;
}


int sizeTree(node* root) {
	if (root == NULL) return 0;
	else return (1 + sizeTree(root->left) + sizeTree(root->right));
}

///////// Queue Operations

queue* createQueue(int nElements) {
	queue* tmpQ = (queue*)malloc(sizeof(queue));
	tmpQ->front = tmpQ->back = -1; //-1 means no Elements

	tmpQ->queueArr = (node**) malloc(sizeof(node*)*nElements);
	for (int i = 0; i < nElements;i++) {
		tmpQ->queueArr[i] = NULL;
	}
	return tmpQ;
}

bool isEmptyQueue(queue* aQueue) {
	return ((aQueue->front == aQueue->back + 1) || (aQueue->back == -1));
}

queue* enQueue(queue* aQueue, node* aNode) {
	
	if( isEmptyQueue(aQueue)) { // empty
		aQueue->front  = 0;
		aQueue->back  = 0;
		aQueue->queueArr[aQueue->back] = aNode;
		return aQueue;
	}

	// not empty
	aQueue->back++;
	aQueue->queueArr[aQueue->back] = aNode;

	return aQueue;
}

void printQueue(queue* aQueue) {
	for (int i = aQueue->front; i <= aQueue->back; i++) {
		printf("%d ",aQueue->queueArr[i]->data);
	}
	printf("\n");
}


node* deQueue(queue* aQueue) {
	if (!isEmptyQueue(aQueue)) {
		node* tmp = aQueue->queueArr[aQueue->front];
		aQueue->queueArr[aQueue->front] = NULL;
		aQueue->front++;
		return tmp;
	}

	return NULL;
}


///////// Stack Operations
stack* createStack(int nElements) {
	stack* tmpS = (stack*) malloc(sizeof(stack));
	tmpS->top = -1;
	tmpS->stackArr = (node**) malloc(sizeof(node*)*nElements);
	for (int i = 0; i < nElements;i++) {
		tmpS->stackArr[i] = NULL;
	}
	return tmpS;
}


bool isEmptyStack(stack* head) {
	return (head->top == -1);
}

void push(stack *head, node* aNode) {
	if( isEmptyStack(head)) {
		(head)->top++;
		(head)->stackArr[head->top] = aNode;
		return;
	}

	head->top++;
	(head)->stackArr[head->top] = aNode;

}

node* topStack(stack *head) {
	if (!isEmptyStack(head)) {
		node* tmp = head->stackArr[head->top];
		return tmp;
	}
	return NULL;
}

void popStack(stack* head) {
	if (!isEmptyStack(head)) {
		head->stackArr[head->top] = NULL;
		//free(head->stackArr[head->top]);
		head->top --;
	}
	return ;
}

void printStack(stack* head) {
	for (int i = head->top; i >= 0;i--) {
		printf("%d ",head->stackArr[i]->data);
	}
}

void printTree(node* root) {
	if (root == NULL) return;
	printTree(root->left);
	printf("%d ",root->data);
	printTree(root->right);
}

void reverseOrderTravel(node* root, stack* aStack, queue* aQueue) {
	if (root == NULL) return;
	
	enQueue(aQueue, root);
	while(!isEmptyQueue(aQueue)) {
		node* tmp = deQueue(aQueue);
		
		if(tmp->right != NULL)
			aQueue = enQueue(aQueue, tmp->right);
		
		if(tmp->left != NULL)
			aQueue = enQueue(aQueue, tmp->left);

		push(aStack,tmp);
	}

	printStack(aStack);
}


void main() {

	node* root = newNode(1);
	node* left_1 = newNode(2);
	node* right_1 = newNode(3);
	node* right_2_left = newNode(6);
	node* right_3_left = newNode(7);
	node* left_2_left = newNode(4);
	node* left_2_right = newNode(5);

	root->left = left_1;
	root->right = right_1;
	right_1->left =right_2_left;
	right_2_left->left = right_3_left;
	root->left->left = left_2_left;
	root->left->right = left_2_right;

	printTree(root);
	printf("\n");

	int nElements = sizeTree(root);
	queue* aQueue = createQueue(nElements);
	stack* aStack = createStack(nElements);
	
	reverseOrderTravel(root,aStack,aQueue);
	
	/*
	aQueue = enQueue(aQueue,root);
	printQueue(aQueue);
	node* tmp = deQueue(aQueue);
	printf("%d ", tmp->data);
	*/

	/*
	push(aStack,root);
	node* tmp = topStack(aStack);
	push(aStack, root);
	printf("%d ", tmp->data);
	*/

	printf("\n");
}