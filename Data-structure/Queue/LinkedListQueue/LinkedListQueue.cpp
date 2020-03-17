#include "LinkedListQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedListQueue* CreateLLQ()
{
	LinkedListQueue* pReturn = NULL;
	pReturn = (LinkedListQueue*)malloc(sizeof(LinkedListQueue));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(LinkedListQueue));
	else
		printf("Dynamic allocation error : CreateLLQ\n");
	return pReturn;
}

void DeleteLLQ(LinkedListQueue* Queue)
{
	if (Queue != NULL)
		free(Queue);
	else
		printf("Queue is NULL : DeleteLLQ\n");
}

void EnQueueLLQ(LinkedListQueue* Queue, LinkedListQueueNode* NewNode)
{
	if (Queue != NULL)
	{
		if (Queue->CurrentElementCount == 0)
		{
			Queue->pFront = NewNode;
			Queue->pRear = NewNode;
		}
		else
		{
			Queue->pRear->pLink = NewNode;
			Queue->pRear = NewNode;
		}
		Queue->CurrentElementCount++;
		NewNode->pLink = NULL;
	}
	else
		printf("Queue is NULL : EnQueueLLQ\n");
}

LinkedListQueueNode* DeQueueLLQ(LinkedListQueue* Queue)
{
	LinkedListQueueNode* pReturn = NULL;
	if (Queue != NULL)
	{
		if (Queue->CurrentElementCount > 0)
		{
			pReturn = Queue->pFront;
			if (Queue->CurrentElementCount == 1)
			{
				Queue->pFront = NULL;
				Queue->pRear = NULL;
			}
			else
			{
				Queue->pFront = Queue->pFront->pLink;
			}
			Queue->CurrentElementCount--;
		}
		else
			printf("Queue underflow : DeQueueLLQ\n");
	}
	else
		printf("Queue is NULL : DeQueueLLQ\n");

	return pReturn;
}

void viewLLQ(LinkedListQueue* Queue)
{
	LinkedListQueueNode* ptr = Queue->pFront;
	if (Queue != NULL)
	{
		printf("The number of Current Element : %d\n", Queue->CurrentElementCount);
		printf("Front\n");
		for (int i = 0; i < Queue->CurrentElementCount; i++)
		{
			printf("%c\n", ptr->Data);
			ptr = ptr->pLink;
		}
		printf("Rear\n");
	}
	else
		printf("Queue is NULL\n");
}

LinkedListQueueNode* PeakLLQ(LinkedListQueue* Queue)
{
	if (Queue != NULL)
		return Queue->pFront;
	else
		printf("Queue is NULL\n");
	return NULL;
}