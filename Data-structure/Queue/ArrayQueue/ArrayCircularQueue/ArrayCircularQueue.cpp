#include "ArrayCircularQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayCircularQueue* CreateACQ(int MaxElementCount)
{
	ArrayCircularQueue* pReturn = NULL;
	if (MaxElementCount > 0)
	{
		pReturn = (ArrayCircularQueue*)malloc(sizeof(ArrayCircularQueue));
		if (pReturn != NULL)
		{
			pReturn->MaxElementCount = MaxElementCount;
			pReturn->CurrentElementCount = 0;
			pReturn->Front = 0;
			pReturn->Rear = 0;
			pReturn->pNode = (ArrayCircularQueueNode*)malloc(sizeof(ArrayCircularQueueNode) * MaxElementCount);
			if (pReturn->pNode != NULL)
			{
				memset(pReturn->pNode, 0, sizeof(ArrayCircularQueueNode) * MaxElementCount);
			}
			else
			{
				printf("\nDynamic allocation error : CreateACQ\n");
				free(pReturn);
				pReturn = NULL;
			}
		}
		else
			printf("\nDynamic allocation error : CreateACQ\n");
	}
	else
	{
		printf("\nMaxElementCount < 0 : CreateACQ\n");
	}

	return pReturn;
}

void DeleteACQ(ArrayCircularQueue* Queue)
{
	if (Queue != NULL)
	{
		free(Queue->pNode);
		free(Queue);
	}
	else
		printf("\nQueue is NULL : DeleteACQ\n");
}

void EnQueueACQ(ArrayCircularQueue* Queue, ArrayCircularQueueNode NewNode)
{
	if (Queue != NULL)
	{
		if (Queue->MaxElementCount > Queue->CurrentElementCount)
		{
			Queue->pNode[(Queue->Rear + 1) % Queue->MaxElementCount] = NewNode;
			Queue->Rear = (Queue->Rear + 1) % Queue->MaxElementCount;
			if (Queue->CurrentElementCount == 0)
				Queue->Front = (Queue->Front + 1) % Queue->MaxElementCount;
			Queue->CurrentElementCount++;
		}
		else
			printf("\nQueue overflow : EnQueueACQ\n");
	}
	else
		printf("\nQueue is NULL : EnQueueACQ\n");
}

ArrayCircularQueueNode DeQueueACQ(ArrayCircularQueue* Queue)
{
	ArrayCircularQueueNode ReturnNode = { NULL };
	if (Queue != NULL)
	{
		if (Queue->CurrentElementCount > 0)
		{
			ReturnNode = Queue->pNode[Queue->Front];
			Queue->Front = (Queue->Front + 1) % Queue->MaxElementCount;
			Queue->CurrentElementCount--;
			if (Queue->CurrentElementCount == 0)
				Queue->Rear = Queue->Front;
		}
		else
			printf("\nQueue underflow\n");
	}
	else
		printf("\nQueue is NULL : DeQueueACQ\n");

	return ReturnNode;
}

ArrayCircularQueueNode PeakACQ(ArrayCircularQueue* Queue)
{
	ArrayCircularQueueNode ReturnNode = { NULL };
	if (Queue != NULL)
		ReturnNode = Queue->pNode[Queue->Front];
	else
		printf("\nQueue is NULL : DeQueueACQ\n");

	return ReturnNode;
}

void ViewQueue(ArrayCircularQueue* Queue)
{
	if (Queue != NULL)
	{
		printf("MaxElementCount : %d\n", Queue->MaxElementCount);
		printf("CurrentElementCount : %d\n", Queue->CurrentElementCount);
		printf("Front\n");
		for (int i = 0; i < Queue->CurrentElementCount; i++)
			printf("%c\n",Queue->pNode[(Queue->Front+i)%Queue->MaxElementCount].Data);
		printf("Rear\n\n");
	}
	else
		printf("\nQueue is NULL : ViewQueue\n");
}
