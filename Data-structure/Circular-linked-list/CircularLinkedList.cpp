#include "CircularLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

CLList* CreateCLList()
{
	CLList* pReturn = NULL;

	pReturn = (CLList*)malloc(sizeof(CLList));
	if (pReturn == NULL)
	{
		printf("Dynamic allocation error\n");
		return NULL;
	}
	else
	{
		pReturn->CurrentElementCount = 0;
		pReturn->HeaderNode.data = 0;
		pReturn->HeaderNode.pLink = NULL;
	}
	return pReturn;
}

int AddCLListElement(CLList* List, int Position, int NewElement)
{
	int ret = false;
	CLListNode* NewNode = NULL;
	CLListNode* preNode = &(List->HeaderNode);
	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount + 1)
		{
			NewNode = (CLListNode*)malloc(sizeof(CLListNode));
			if (NewNode != NULL)
			{
				NewNode->data = NewElement;
				if (Position == 1)
				{
					if (isCLListEmpty(List) == true)
					{
						List->HeaderNode.pLink = NewNode;
						NewNode->pLink = NewNode;
					}
					else
					{
						for (int i = 0; i < List->CurrentElementCount-1; i++)
							preNode = preNode->pLink;
						NewNode->pLink = List->HeaderNode.pLink;
						List->HeaderNode.pLink = NewNode;
						preNode->pLink = NewNode;
					}
				}
				else
				{
					for (int i = 0; i < Position - 1; i++)
						preNode = preNode->pLink;
					NewNode->pLink = preNode->pLink;
					preNode->pLink = NewNode;
				}

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
	}
	else
	{
		printf("List : NULL\n");
		return ret;
	}
	return ret;
}

int RemoveCLListElement(CLList* List, int Position)
{
	int ret = false;
	CLListNode* preNode = &(List->HeaderNode);
	CLListNode* deleteNode = NULL;
	if (List != NULL)
	{
		if (Position > 0 && Position <= List->CurrentElementCount)
		{
			if (Position == 1)
			{
				if (List->CurrentElementCount == 1)
					free(List->HeaderNode.pLink);
				else
				{
					for (int i = 0; i < List->CurrentElementCount-1; i++)
						preNode = preNode->pLink;
					deleteNode = List->HeaderNode.pLink;
					preNode->pLink->pLink = deleteNode->pLink;
					List->HeaderNode.pLink = deleteNode->pLink;
					free(deleteNode);
				}
			}
			else
			{
				for (int i = 0; i < Position - 1; i++)
					preNode = preNode->pLink;
				deleteNode = preNode->pLink;
				preNode->pLink =deleteNode->pLink;
				free(deleteNode);
			}
			List->CurrentElementCount--;
			ret = true;
		}
		else
		{
			printf("Position index error\n");
		}
	}
	else
	{
		printf("List : NULL\n");
	}
	return ret;
}

int isCLListEmpty(CLList* List)
{
	int ret = false;
	if (List != NULL)
	{
		if (List->CurrentElementCount == 0)
			ret = true;
	}
	else
	{
		printf("List : NULL\n");
		return ret;
	}
	return ret;
}

void DeleteCLList(CLList* List)
{
	CLListNode* CurrentNode=List->HeaderNode.pLink;
	CLListNode* NextNode=NULL;
	if (List != NULL)
	{
		for (int i = 0; i < List->CurrentElementCount; i++)
		{
			NextNode = CurrentNode->pLink;
			free(CurrentNode);
			CurrentNode = NextNode;
		}
		free(List);
	}
	else
	{
		printf("List : NULL\n");
		return;
	}
}

int getCLListLenght(CLList* List)
{
	int ret = false;
	if (List != NULL)
	{
		ret = List->CurrentElementCount;
		return ret;
	}
	else
	{
		printf("List : NULL\n");
		return ret;
	}
}

int getCLListElement(CLList* List, int Position)
{
	int ret = 0;
	CLListNode* preNode = &(List->HeaderNode);
	if (List != NULL)
	{
		for (int i = 0; i < Position; i++)
			preNode = preNode->pLink;
		ret = preNode->data;
	}
	else
	{
		printf("List : NULL\n");
		return ret;
	}
	return ret;
}

void ViewAllCLListElements(CLList* List)
{
	CLListNode* preNode = &(List->HeaderNode);
	if (List != NULL)
	{
		for (int i = 0; i < List->CurrentElementCount; i++)
		{
			preNode = preNode->pLink;
			printf("%d\t", preNode->data);
		}
		printf("\n\n");
	}
	else
		printf("List : NULL\n");
	return;
}
