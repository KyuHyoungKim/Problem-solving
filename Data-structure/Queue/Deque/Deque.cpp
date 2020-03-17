#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Deque* CreateDeque()
{
	Deque* pReturn = NULL;
	pReturn = (Deque*)malloc(sizeof(Deque));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(Deque));
	else
		printf("Dynamic allocation error : CreateDeque\n");

	return pReturn;
}

void DeleteDeque(Deque* Deque)
{
	if (Deque != NULL)
		free(Deque);
	else
		printf("Deque is NULL : DeleteDeque\n");
}

void InsertFrontDeque(Deque* Deque, DequeNode* NewNode)
{
	if (Deque != NULL)
	{
		if (Deque->CurrentElementCount == 0)
		{
			Deque->pFront = NewNode;
			Deque->pRear = NewNode;
			NewNode->pLLink = NULL;
			NewNode->pRLink = NULL;
		}
		else
		{
			NewNode->pLLink = NULL;
			NewNode->pRLink = Deque->pFront;

			Deque->pFront->pLLink = NewNode;
			Deque->pFront = NewNode;
		}
		Deque->CurrentElementCount++;
	}
	else
		printf("Deque is NULL : EnDequeDeque\n");
}

void InsertRearDeque(Deque* Deque, DequeNode* NewNode)
{
	if (Deque != NULL)
	{
		if (Deque->CurrentElementCount == 0)
		{
			Deque->pFront = NewNode;
			Deque->pRear = NewNode;
			NewNode->pLLink = NULL;
			NewNode->pRLink = NULL;
		}
		else
		{
			NewNode->pRLink = NULL;
			NewNode->pLLink = Deque->pRear;

			Deque->pRear->pRLink = NewNode;
			Deque->pRear = NewNode;
		}
		Deque->CurrentElementCount++;
	}
	else
		printf("Deque is NULL : EnDequeDeque\n");
}

DequeNode ExtractFrontDeque(Deque* Deque)
{
	DequeNode ReturnNode = { 'NULL' };

	if (Deque != NULL)
	{
		if (Deque->CurrentElementCount <= 0)
			printf("Deque underflow : ExtractFrontDeque\n");
		else
		{
			ReturnNode = *(Deque->pFront);
			if (Deque->CurrentElementCount == 1)
			{
				Deque->pFront = NULL;
				Deque->pRear = NULL;
			}
			else
			{
				Deque->pFront = Deque->pFront->pRLink;
				Deque->pFront->pLLink = NULL;
			}
			Deque->CurrentElementCount--;
		}
	}
	else
		printf("Deque is NULL : ExtractFrontDeque\n");

	return ReturnNode;
}

DequeNode ExtractRearDeque(Deque* Deque)
{
	DequeNode ReturnNode = { 'NULL' };

	if (Deque != NULL)
	{
		if (Deque->CurrentElementCount <= 0)
			printf("Deque underflow : ExtractRearDeque\n");
		else
		{
			ReturnNode = *(Deque->pRear);
			if (Deque->CurrentElementCount == 1)
			{
				Deque->pFront = NULL;
				Deque->pRear = NULL;
			}
			else
			{
				Deque->pRear = Deque->pRear->pLLink;
				Deque->pRear->pRLink = NULL;
			}
			Deque->CurrentElementCount--;
		}
	}
	else
		printf("Deque is NULL : ExtractRearDeque\n");

	return ReturnNode;
}

void ViewDeque(Deque* Deque_input)
{
	DequeNode* ptr = Deque_input->pFront;
	printf("Number of current elements : %d\n", Deque_input->CurrentElementCount);
	printf("Front\n");
	for (int i = 0; i < Deque_input->CurrentElementCount; i++)
	{
		printf("%c\n", ptr->data);
		ptr = ptr->pRLink;
	}
	printf("Rear\n");
}