#include"DoublyLinkedList.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

DLList* CreateDLList()
{
	DLList* pReturn = NULL;

	pReturn = (DLList*)malloc(sizeof(DLList));
	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(DLList));
	else
		printf("Dynamic allocation error : CreateDLList\n");
	return pReturn;
}

int AddDLLElement(DLList* List, int Position, int NewElement)
{
	int ret = false;

	if (Position > 0 && Position <= List->CurrentElementCount+1)
	{
		if (List->CurrentElementCount == 0)
		{
			List->HeaderNode = (DLListNode*)malloc(sizeof(DLListNode));
			if (List->HeaderNode != NULL)
			{
				List->HeaderNode->data = NewElement;
				List->HeaderNode->pHead = List->HeaderNode;
				List->HeaderNode->pTail = List->HeaderNode;
				List->CurrentElementCount++;
			}
			else
				printf("Dynamic allocation error : AddDLLElement\n");
		}
		else
		{
			DLListNode* pNewNode = NULL;
			DLListNode* pPositionNode = List->HeaderNode;

			pNewNode = (DLListNode*)malloc(sizeof(DLListNode));

			if (pNewNode != NULL)
			{
				pNewNode->data = NewElement;

				for (int i = 1; i < Position; i++)
					pPositionNode = pPositionNode->pHead;

				pNewNode->pHead = pPositionNode->pHead;
				pNewNode->pHead->pTail = pNewNode;
				pNewNode->pTail = pPositionNode;
				pPositionNode->pHead = pNewNode;
				ret = true;
				List->CurrentElementCount++;
			}
			else
				printf("Dynamic allocation error : AddDLLElement\n");
		}
	}
	else
		printf("Position index error : AddDLLElement\n");
	return ret;
}

void DeleteDLList(DLList* List)
{
	if (List != NULL)
	{
		DLListNode* CurrentNode = List->HeaderNode;
		DLListNode* NextNode = NULL;
		for (int i = 0; i < List->CurrentElementCount; i++)
		{
			NextNode = CurrentNode->pTail;
			free(CurrentNode);
			CurrentNode = NextNode;
		}
		free(List);
	}
	else
		printf("List : NULL\n");
}

int RemoveDLLElement(DLList* List, int Position)
{
	int ret = false;
	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			DLListNode* DeletedNode = List->HeaderNode;
			if (Position == 1)
			{
				DeletedNode = DeletedNode->pTail;
				List->HeaderNode->data = DeletedNode->data;
				List->HeaderNode->pTail = DeletedNode->pTail;
				DeletedNode->pTail->pHead = List->HeaderNode;
			}
			else
			{
				for (int i = 1; i < Position; i++)
					DeletedNode = DeletedNode->pTail;
				DeletedNode->pHead->pTail = DeletedNode->pTail;
				DeletedNode->pTail->pHead = DeletedNode->pHead;
			}
			free(DeletedNode);
			List->CurrentElementCount--;
		}
		else
			printf("Position index error : RemoveDLLElement\n");
	}
	else
		printf("List is NULL : RemoveDLLElement\n");
	
	return ret;
}

int getDLLLength(DLList* List)
{
	int ret = 0;
	if (List != NULL)
		ret = List->CurrentElementCount;
	else
		printf("List is NULL : getDLLLength\n");

	return ret;
}

int getDLLElement(DLList* List, int Position)
{
	int ret = false;
	DLListNode* targetNode = List->HeaderNode;
	if (List != NULL)	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			for (int i = 1; i < Position; i++)
				targetNode = targetNode->pTail;
			ret = targetNode->data;
		}
		else
			printf("Position index error : getDLLElement\n");
	}
	else
		printf("List is NULL : getDLLElement\n");
	return ret;
}

void DisplayDLListElements(DLList* List)
{
	DLListNode* tempNode = List->HeaderNode;
	if (List != NULL)
	{
		for (int i = 0; i < List->CurrentElementCount; i++)
		{
			printf("%d\t", tempNode->data);
			tempNode = tempNode->pTail;
		}
	}
	else
		printf("List is NULL : DisplayDLListElements\n");
}
