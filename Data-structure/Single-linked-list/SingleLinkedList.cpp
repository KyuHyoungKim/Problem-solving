#include "SingleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

SingleLinkedList* CreateSingleLinkedList()
{
	SingleLinkedList* NewList;

	NewList = (SingleLinkedList*)malloc(sizeof(SingleLinkedList));

	if (NewList != NULL)
	{
		NewList->HeaderNode.data = 0;
		NewList->HeaderNode.pLink = NULL;
		NewList->CurrentElementCount = 0;
	}
	else
	{
		printf("Dynamic allocation error\n");
		return NULL;
	}
	return NewList;
}

void DeleteSingleLinkedList(SingleLinkedList* List)
{
	SingleLinkedListNode* Node = NULL;
	if (List != NULL)
	{
		for (int j = 0; j < List->CurrentElementCount; j++)
		{
			Node= &(List->HeaderNode);
			for (int i = 0; i < List->CurrentElementCount - 1; i++)
			{
				Node->pLink = Node->pLink->pLink;
			}
			memset(Node->pLink, 0, sizeof(SingleLinkedListNode));
			free(Node->pLink);
			List->CurrentElementCount--;
		}
	}
	else
	{
		printf("List NULL\n");
		return;
	}
}

int IsSingleLinkedListEmpty(SingleLinkedList* List)
{
	int ret = false;
	if (List != NULL)
	{
		if (List->CurrentElementCount == 0)
			ret = true;
		return ret;
	}
	else
	{
		printf("List NULL\n");
		return ret;
	}
}

int AddSingleLinkedListElement(SingleLinkedList* List, int Position, int NewElement)
{
	int ret = false;
	SingleLinkedListNode* NewNode=NULL;
	SingleLinkedListNode* preNode=NULL;

	if (Position > 0 && Position<=List->CurrentElementCount+1)
	{
		NewNode = (SingleLinkedListNode*)malloc(sizeof(SingleLinkedListNode));
		if (NewNode != NULL)
		{
			preNode = &(List->HeaderNode);
			for (int i = 1; i < Position; i++)
			{
				preNode= preNode->pLink;
			}
			NewNode->data = NewElement;
			NewNode->pLink = preNode->pLink;
			preNode->pLink = NewNode;
			List->CurrentElementCount++;
			ret = true;
		}
		else
		{
			printf("Dynamic allocation error\n");
			return ret;
		}
	}
	else
	{
		printf("Position index error\n");
		return ret;
	}

	return ret;
}

int RemoveSingleLinkedListElement(SingleLinkedList* List, int Position)
{
	int ret = false;
	SingleLinkedListNode* preNode = NULL;

	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			preNode = &(List->HeaderNode);
			for (int i = 1; i < Position; i++)
			{
				preNode = preNode->pLink;
			}
			preNode->pLink = preNode->pLink->pLink;
			List->CurrentElementCount--;
			ret = true;
		}
		else
		{
			printf("Position index error\n");
			return ret;
		}
	}
	else
	{
		printf("List NULL");
		return ret;
	}
}

int GetSingleLinkedListLength(SingleLinkedList* List)
{
	int ret = false;
	if (List != NULL)
	{
		ret = List->CurrentElementCount;
	}
	else
	{
		printf("List NULL\n");
		return ret;
	}

	return ret;
}

int GetSingleLinkedListElement(SingleLinkedList* List, int Position)
{
	int ret = false;
	SingleLinkedListNode* preNode = NULL;

	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			preNode = &(List->HeaderNode);
			for (int i = 0; i < Position; i++)
			{
				preNode = preNode->pLink;
			}
			ret = preNode->data;
		}
		else
		{
			printf("Position index error");
			return ret;
		}
	}
	else
	{
		printf("List NULL\n");
		return ret;
	}
	return ret;
}
