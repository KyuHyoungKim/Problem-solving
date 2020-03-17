#include "LinkedListQueue.h"
#include <stdio.h>

int main(void)
{
	LinkedListQueue* TestQueue = NULL;

	LinkedListQueueNode Node1 = { 'A' };
	LinkedListQueueNode Node2 = { 'B' };
	LinkedListQueueNode Node3 = { 'C' };
	LinkedListQueueNode Node4 = { 'D' };
	LinkedListQueueNode Node5 = { 'E' };

	TestQueue = CreateLLQ();

	EnQueueLLQ(TestQueue, &Node1);	// Check EnQueueLLQ
	EnQueueLLQ(TestQueue, &Node2);
	viewLLQ(TestQueue);

	DeQueueLLQ(TestQueue);			// Check DeQueueLLQ
	DeQueueLLQ(TestQueue);
	DeQueueLLQ(TestQueue);
	viewLLQ(TestQueue);

	EnQueueLLQ(TestQueue, &Node3);	
	EnQueueLLQ(TestQueue, &Node4);
	EnQueueLLQ(TestQueue, &Node5);
	viewLLQ(TestQueue);

	printf("Peak : %c", PeakLLQ(TestQueue)->Data);

	DeleteLLQ(TestQueue);

	return 0;
}