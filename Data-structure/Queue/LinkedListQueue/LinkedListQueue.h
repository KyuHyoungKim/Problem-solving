#ifndef _LINKED_LIST_QUEUE-
#define _LINKED_LIST_QUEUE_

typedef struct LinkedListQueueNodeType
{
	char Data;
	struct LinkedListQueueNodeType* pLink;
}LinkedListQueueNode;

typedef struct LinkedListQueueType
{
	int CurrentElementCount;
	LinkedListQueueNode* pFront;
	LinkedListQueueNode* pRear;
}LinkedListQueue;

LinkedListQueue* CreateLLQ();
void DeleteLLQ(LinkedListQueue* Queue);
void EnQueueLLQ(LinkedListQueue* Queue, LinkedListQueueNode* NewNode);
LinkedListQueueNode* DeQueueLLQ(LinkedListQueue* Queue);
void viewLLQ(LinkedListQueue* Queue);
LinkedListQueueNode* PeakLLQ(LinkedListQueue* Queue);


#endif