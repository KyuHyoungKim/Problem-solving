#ifndef _ARRAY_CRICULAR_QUEUE_
#define _ARRAY_CRICULAR_QUEUE_

typedef struct ArrayCircularQueueNodeType
{
	char Data;
}ArrayCircularQueueNode;

typedef struct ArrayCircularQueueType
{
	int MaxElementCount;
	int CurrentElementCount;
	int Front;
	int Rear;
	ArrayCircularQueueNode* pNode;
}ArrayCircularQueue;

ArrayCircularQueue* CreateACQ(int MaxElementCount);
void DeleteACQ(ArrayCircularQueue* Queue);
void EnQueueACQ(ArrayCircularQueue* Queue, ArrayCircularQueueNode NewNode);
ArrayCircularQueueNode DeQueueACQ(ArrayCircularQueue* Queue);
ArrayCircularQueueNode PeakACQ(ArrayCircularQueue* Queue);
void ViewQueue(ArrayCircularQueue* Queue);





#endif

#ifndef _COMMON_ARRAY_CRICULAR_QUEUE_
#define _COMMON_ARRAY_CRICULAR_QUEUE_

#define TRUE 1
#define FALSE 0

#endif