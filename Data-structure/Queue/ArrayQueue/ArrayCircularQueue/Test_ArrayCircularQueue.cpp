#include "ArrayCircularQueue.h"
#include <stdio.h>

int main(void)
{
	ArrayCircularQueue* TestQueue = CreateACQ(5);

	ArrayCircularQueueNode Node1 = { 'A' };
	ArrayCircularQueueNode Node2 = { 'B' };
	ArrayCircularQueueNode Node3 = { 'C' };
	ArrayCircularQueueNode Node4 = { 'D' };
	ArrayCircularQueueNode Node5 = { 'E' };
	ArrayCircularQueueNode Node6 = { 'F' };
	ArrayCircularQueueNode Node7 = { 'G' };
	ArrayCircularQueueNode Node8 = { 'H' };
	ArrayCircularQueueNode Node9 = { 'I' };
	ArrayCircularQueueNode Node10 = { 'J' };
	ArrayCircularQueueNode tempNode = { NULL };

	ViewQueue(TestQueue);			//Check the empty Queue 

	DeQueueACQ(TestQueue);			//Check underflow
	ViewQueue(TestQueue);			

	EnQueueACQ(TestQueue, Node1);
	ViewQueue(TestQueue);			//Check EnQueue

	DeQueueACQ(TestQueue);			
	tempNode = DeQueueACQ(TestQueue);//Check DeQueue
	printf("tempNode.Data : %c\n", tempNode.Data);

	DeQueueACQ(TestQueue);			//Check underflow again

	EnQueueACQ(TestQueue, Node2);
	EnQueueACQ(TestQueue, Node3);
	EnQueueACQ(TestQueue, Node4);
	EnQueueACQ(TestQueue, Node5);
	EnQueueACQ(TestQueue, Node6);
	ViewQueue(TestQueue);
	EnQueueACQ(TestQueue, Node7);	//Check overflow

	DeQueueACQ(TestQueue);
	DeQueueACQ(TestQueue);
	DeQueueACQ(TestQueue);

	EnQueueACQ(TestQueue, Node8);
	EnQueueACQ(TestQueue, Node9);
	EnQueueACQ(TestQueue, Node10);	//Check Circularity


	ViewQueue(TestQueue);


	DeleteACQ(TestQueue);

	return 0;
}
