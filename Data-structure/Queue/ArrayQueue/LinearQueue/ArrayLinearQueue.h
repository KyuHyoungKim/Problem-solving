#ifndef _ARRAY_LINEAR_QUEUE_
#define _ARRAY_LINEAR_QUEUE_

typedef struct ArrayLinearQueueNodeType
{
	char data;
}ArrayLinearQueueNode;


typedef struct ArrayLinearQueueType
{
	int MaxElementCount;
	int CurrentElementCount;
	ArrayLinearQueueNode* pNode;
	ArrayLinearQueueNode* pFront;
	ArrayLinearQueueNode* pRear;
}ArrayLinearQueue;

ArrayLinearQueue* CreateALQ(int MaxElementCount);
void DeleteALQ(ArrayLinearQueue* Queue);
void EnQueueALQ(ArrayLinearQueue* Queue, ArrayLinearQueueNode NewNode);
ArrayLinearQueueNode DeQueueALQ(ArrayLinearQueue* Queue);
ArrayLinearQueueNode PeakALQ(ArrayLinearQueue* Queue);
void ViewQueueALQ(ArrayLinearQueue* Queue);


#endif

#ifndef _COMMON_ARRAY_LINEAR_QUEUE_
#define _COMMON_ARRAY_LINEAR_QUEUE_

#define TRUE 1
#define FALSE 0

#endif