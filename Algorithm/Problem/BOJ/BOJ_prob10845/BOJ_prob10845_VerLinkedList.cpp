#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE_Type {
	NODE_Type* Nodep;
	int data;
}NODE;

typedef struct QUEUE_Type {
	NODE_Type* Front;
	NODE_Type* Back;
	int size;
}QUEUE;

void push(QUEUE* Queue, int n) {
	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	memset(NewNode, 0, sizeof(NODE));
	NewNode->Nodep = NULL;
	NewNode->data = n;
	if (Queue->size == 0)
	{
		Queue->Front = NewNode;
		Queue->Back = NewNode;
	}
	else
	{
		Queue->Back->Nodep = NewNode;
		Queue->Back = NewNode;
	}
	Queue->size++;
	return;
}

int pop(QUEUE* Queue) {
	if (Queue->size == 0)
		return -1;
	NODE* DeletedNode = Queue->Front;
	int ret = DeletedNode->data;
	Queue->Front = Queue->Front->Nodep;
	free(DeletedNode);
	Queue->size--;
	if (Queue->size == 0)
		Queue->Back = NULL;
	return ret;
}

int size(QUEUE* Queue) {
	int ret = Queue->size;
	return ret;
}

int empty(QUEUE* Queue) {
	int ret = 0;
	if (Queue->size == 0)
		ret = 1;
	return ret;
}

int front(QUEUE* Queue) {
	if (Queue->size == 0)
		return -1;
	int ret = Queue->Front->data;
	return ret;
}

int back(QUEUE* Queue) {
	if (Queue->size == 0)
		return -1;
	int ret = Queue->Back->data;
	return ret;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int N = 0, num = 0;
	char order[7];
	QUEUE* Queue = (QUEUE*)malloc(sizeof(QUEUE));
	memset(Queue, 0, sizeof(QUEUE));
	scanf("%d", &N);
	while (N--) {
		scanf("%s", order);
		if (!strcmp(order, "push"))
		{
			scanf("%d", &num);
			push(Queue, num);
		}
		else if (!strcmp(order,"pop"))
			printf("%d\n", pop(Queue));
		else if (!strcmp(order, "size"))
			printf("%d\n", size(Queue));
		else if (!strcmp(order, "empty"))
			printf("%d\n", empty(Queue));
		else if (!strcmp(order, "front"))
			printf("%d\n",front(Queue));
		else if (!strcmp(order, "back"))
			printf("%d\n", back(Queue));
	}
	free(Queue);
	return 0;
}