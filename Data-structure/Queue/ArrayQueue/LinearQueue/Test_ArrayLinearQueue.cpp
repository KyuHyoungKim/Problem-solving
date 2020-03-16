#include "ArrayLinearQueue.h"
#include <stdio.h>

int main(void)
{
	ArrayLinearQueue* TestQueue = CreateALQ(5);
	
	ArrayLinearQueueNode Node1 = { 'A' };
	ArrayLinearQueueNode Node2 = { 'B' };
	ArrayLinearQueueNode Node3 = { 'C' };
	ArrayLinearQueueNode Node4 = { 'D' };
	ArrayLinearQueueNode Node5 = { 'E' };
	ArrayLinearQueueNode Node6 = { 'F' };
	ArrayLinearQueueNode Node7 = { 'G' };
	ArrayLinearQueueNode Node8 = { 'H' };
	
	EnQueueALQ(TestQueue, Node1);
	ViewQueueALQ(TestQueue);
	DeQueueALQ(TestQueue);
	ViewQueueALQ(TestQueue);
	DeQueueALQ(TestQueue);

	EnQueueALQ(TestQueue, Node2);
	EnQueueALQ(TestQueue, Node3);
	EnQueueALQ(TestQueue, Node4);
	EnQueueALQ(TestQueue, Node5);
	ViewQueueALQ(TestQueue);

	EnQueueALQ(TestQueue, Node6);
	ViewQueueALQ(TestQueue);

	EnQueueALQ(TestQueue, Node7);
	ViewQueueALQ(TestQueue);

	DeleteALQ(TestQueue);

	return 0;
}
