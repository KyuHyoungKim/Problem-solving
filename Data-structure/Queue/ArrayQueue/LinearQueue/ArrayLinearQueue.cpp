#include "ArrayLinearQueue.h"
#include <stdio.h>
#include <stdlib.h>

ArrayLinearQueue* CreateALQ(int MaxElementCount)
{
	ArrayLinearQueue* pReturn = NULL;
	if (MaxElementCount > 0)
	{
		pReturn = (ArrayLinearQueue*)malloc(sizeof(ArrayLinearQueue));
		if (pReturn != NULL)
		{
			pReturn->MaxElementCount = MaxElementCount;
			pReturn->CurrentElementCount = 0;
			pReturn->pNode = (ArrayLinearQueueNode*)malloc(sizeof(ArrayLinearQueueNode) * MaxElementCount);
			if (pReturn->pNode != NULL)
			{
				pReturn->pFront = pReturn->pNode;
				pReturn->pRear = pReturn->pNode;
			}
			else
			{
				printf("Dynamic allocation error : CreateALQ\n");
				free(pReturn);
				pReturn = NULL;
			}
		}
		else
			printf("Dynamic allocation error ; CreateALQ\n");
	}
	else
		printf("MaxElementCount < 0 : CreateALQ\n");
	return pReturn;
}

void DeleteALQ(ArrayLinearQueue* Queue)
{
	if (Queue != NULL)
	{
		free(Queue->pNode);
		free(Queue);
	}
	else
		printf("Queue is NULL : DeleteALQ\n");
}

void EnQueueALQ(ArrayLinearQueue* Queue, ArrayLinearQueueNode NewNode)
{
	if (Queue != NULL)
	{
		if (Queue->MaxElementCount > Queue->CurrentElementCount)
		{
			if (Queue->CurrentElementCount == 0)
				*(Queue->pRear) = NewNode;
			else
			{
				*(Queue->pRear + 1) = NewNode;
				Queue->pRear++;
			}
			Queue->CurrentElementCount++;
		}
		else
			printf("Queue overflow : EnqueueALQ\n");
	}
	else
		printf("Queue is NULL : EnQueueALQ\n");
}

ArrayLinearQueueNode DeQueueALQ(ArrayLinearQueue* Queue)
{
	ArrayLinearQueueNode ReturnNode = { NULL };

	if (Queue != NULL)
	{
		if (Queue->CurrentElementCount > 0)
		{
			ReturnNode = *(Queue->pFront);
			Queue->pFront++;
			Queue->CurrentElementCount--;
			Queue->MaxElementCount--;
			if (Queue->CurrentElementCount == 0)
				Queue->pRear = Queue->pFront;
		}
		else
			printf("Queue underflow : DeQueueALQ\n");
	}
	else
		printf("Queue is NULL : DeQueueALQ\n");

	return ReturnNode;
}

ArrayLinearQueueNode PeakALQ(ArrayLinearQueue* Queue)
{
	ArrayLinearQueueNode ReturnNode = { NULL };

	if (Queue != NULL)
	{
		if (Queue->CurrentElementCount > 0)
			ReturnNode = *(Queue->pFront);
		else
			printf("Queue underflow : PeakALQ\n");
	}
	else
		printf("Queue is NULL : PeakALQ\n");

	return ReturnNode;
}

void ViewQueueALQ(ArrayLinearQueue* Queue)
{
	if (Queue != NULL)
	{
		printf("MaxElementCount : %d\n", Queue->MaxElementCount);
		printf("CurrentElementCOunt : %d\n", Queue->CurrentElementCount);
		printf("Front\n");
		for (int i = 0; i < Queue->CurrentElementCount; i++)
			printf("%c\n", Queue->pFront[i].data);
		printf("Rear\n\n");
	}
	else
		printf("Queue is NULL : ViewQueueALQ\n");
}