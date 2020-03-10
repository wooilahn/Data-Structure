#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/* structure of Node */
typedef struct Node {
	int data;
	Node* next;
}Node;


/* structure of Queue */
typedef struct Queue {
	Node* front;
	Node* end;
	int count;
}Queue;

/* function to make new node */
Node* CreateNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	return node;
}

/* function to initialize queue */
void InitQueue(Queue** queue) {
	(*queue) = (Queue*)malloc(sizeof(Queue));
	(*queue)->front = (*queue)->end = NULL;
	(*queue)->count = 0;
}

/* function to insert data into queue */
void EnQueue(Queue** queue, Node* node) {
	printf("\tEnQueue the Data: %d\n", node->data);

	if ((*queue)->count == 0)
		(*queue)->front = (*queue)->end = node;
	else {
		(*queue)->end->next = node;
		(*queue)->end = node;
	}

	(*queue)->count++;
}

/* function to delete data into queue */
void DeQueue(Queue** queue) {
	printf("\tDeQueue the Data: %d\n", (*queue)->front->data);

	if ((*queue)->count == 0) {
		printf("Queue is Empty! Program end!\n");
		exit(1);
	}
	else {
		Node* node = (*queue)->front;
		(*queue)->front = (*queue)->front->next;
		(*queue)->count--;

		free(node);
		return;
	}
}

int getFrontValue(Queue** queue) {
	if ((*queue)->count == 0) {
		printf("Queue is Empty! Program end!\n");
		exit(1);
	}
	else 
		return (*queue)->front->data;
}

/* function to return count of queue*/
int getNodeCount(Queue** queue) {
	return (*queue)->count;
}

/* function to make new node */
void DestoryQueue(Queue **queue) {
	int cnt = (*queue)->count;

	for (int i = 0; i < cnt; i++) 
		DeQueue(queue);

	(*queue)->front = (*queue)->end = NULL;
	(*queue)->count = 0;
	free(*queue);

	return;
}

/* function to print all nodes of queue */
void PrintAllNodes(Queue** queue) {
	int cnt = getNodeCount(queue);

	Node* node = (*queue)->front;

	printf("\tPrint all nodes of Queue\n	");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", node->data);
		node = node->next;
	}

	printf("\n");
	return;
}

int main() {
	Queue* queue = NULL;
	InitQueue(&queue);

	EnQueue(&queue, CreateNode(1));
	EnQueue(&queue, CreateNode(2));
	EnQueue(&queue, CreateNode(3));
	EnQueue(&queue, CreateNode(4));
	PrintAllNodes(&queue);

	DeQueue(&queue);
	DeQueue(&queue);
	PrintAllNodes(&queue);

	EnQueue(&queue, CreateNode(5));
	EnQueue(&queue, CreateNode(6));
	EnQueue(&queue, CreateNode(7));
	EnQueue(&queue, CreateNode(8));
	PrintAllNodes(&queue);

	return 0;
}
