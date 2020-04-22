#include "Graph_LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Graph* CreateGraph(int MaxNodeCount)
{
	Graph* pReturn = NULL;
	pReturn = (Graph*)malloc(sizeof(Graph));

	if (pReturn)
	{
		memset(pReturn, 0, sizeof(Graph));
		pReturn->MaxNodeCount = MaxNodeCount;
		pReturn->CurrentNodeCount = 0;
		pReturn->NodeArray = (int*)malloc(sizeof(int) * MaxNodeCount);
		if (!pReturn)
		{
			free(pReturn);
			printf("Dynamic allocation error\n");
			return NULL;
		}
		memset(pReturn->NodeArray, 0, sizeof(int) * MaxNodeCount);
		pReturn->EdgeArray = (LinkedList**)malloc(sizeof(LinkedList) * MaxNodeCount);
		if (!pReturn -> EdgeArray)
		{
			free(pReturn->NodeArray);
			free(pReturn);
			printf("Dynamic allocation error\n");
			return NULL;
		}

		for (int i = 0; i < MaxNodeCount; i++)
		{
			pReturn->EdgeArray[i] = (LinkedList*)malloc(sizeof(LinkedList));
			if (!pReturn->EdgeArray[i])
			{
				free(pReturn->EdgeArray);
				free(pReturn->NodeArray);
				free(pReturn);
				printf("Dynamic allocation error\n");
				return NULL;
			}
			memset(pReturn->EdgeArray[i], 0, sizeof(LinkedList));
		}
	}

	return pReturn;
}

void DeleteGraph(Graph* Gra)
{
	free(Gra->NodeArray);
	for (int i = 0; i < Gra->MaxNodeCount; i++)
		free(Gra->EdgeArray[i]);
	free(Gra->EdgeArray);
	free(Gra);
}

void AddGraphNode(Graph* Gra, int Index)
{
	if (Gra->NodeArray[Index])
		printf("Already used\n");
	else
	{
		Gra->NodeArray[Index] = true;
		Gra->CurrentNodeCount++;
	}
}

void DeleteGraphNode(Graph* Gra, int Index)
{
	if (!Gra->NodeArray[Index])
		printf("Already unused\n");
	else
	{
		Gra->NodeArray[Index] = false;
		
		for (int i = 0; i < Gra->EdgeArray[Index]->CurrentNodeCount; i++)
			DeleteGraphEdge(Gra, Index, Gra->EdgeArray[Index]->pNode->data);
	}
}

void AddElementLL(LinkedList* LL, int Data)
{
	LinkedListNode* NewNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
	if (!NewNode)
	{
		printf("Dynamic allocation error\n");
		return;
	}

	NewNode->data = Data;
	NewNode->pNode = NULL;

	if (LL->CurrentNodeCount == 0)
		LL->pNode = NewNode;
	else
	{
		LinkedListNode* PreviousNode = LL->pNode;
		for (int i = 0; i < LL->CurrentNodeCount - 1; i++)
			PreviousNode = PreviousNode->pNode;
		PreviousNode->pNode = NewNode;
	}
	LL->CurrentNodeCount++;
}

void AddGraphEdge(Graph* Gra, int Head, int Tail)
{
	if (!Gra->NodeArray[Head] || !Gra->NodeArray[Tail])
	{
		if (!Gra->NodeArray[Head])
			printf("Head is unused\n");
		if (!Gra->NodeArray[Tail])
			printf("Tail is unused\n");
		return;
	}
	AddElementLL(Gra->EdgeArray[Head], Tail);
	AddElementLL(Gra->EdgeArray[Tail], Head);
}

void DeleteGraphEdge(Graph* Gra, int Head, int Tail)
{
	if (!Gra->EdgeArray[Head]->pNode || !Gra->EdgeArray[Tail]->pNode)
	{
		printf("Here is No Edge\n");
		return;
	}

	LinkedListNode* DeletedNode_Head = Gra->EdgeArray[Head]->pNode;
	LinkedListNode* tempNode_Head = DeletedNode_Head->pNode;
	LinkedListNode* tempNode_Tail = Gra->EdgeArray[Tail]->pNode;
	LinkedListNode* DeletedNode_Tail = tempNode_Tail->pNode;
	for (int j = 0; j < Gra->EdgeArray[Head]->CurrentNodeCount; j++)
	{
		if (DeletedNode_Tail->data == Head)
		{
			tempNode_Tail->pNode = DeletedNode_Tail->pNode;
			free(DeletedNode_Tail);
			Gra->EdgeArray[Tail]->CurrentNodeCount--;
			break;
		}
		tempNode_Tail = DeletedNode_Tail;
		DeletedNode_Tail = DeletedNode_Tail->pNode;
	}
	free(DeletedNode_Head);
	DeletedNode_Head = tempNode_Head;
	tempNode_Head = DeletedNode_Head->pNode;
	Gra->EdgeArray[Head]->CurrentNodeCount--;
}

void DisplayGraph(Graph* Gra)
{
	if (Gra)
	{
		printf("Node : \n");
		for (int i = 0; i < Gra->MaxNodeCount; i++)
			printf("%d ", Gra->NodeArray[i]);
		printf("\nEdge :\n");

		for (int i = 0; i < Gra->MaxNodeCount; i++)
		{
			LinkedListNode* tempNode = Gra->EdgeArray[i]->pNode;
			printf("#%d : ", i);
			for (int j = 0; j < Gra->EdgeArray[i]->CurrentNodeCount; j++)
			{
				printf("%d ", tempNode->data);
				tempNode = tempNode->pNode;
			}
			printf("\n");
		}
	}
}