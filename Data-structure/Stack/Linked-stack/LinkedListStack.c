#include"Linked_list_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedStack* CreateLinkedStack()
{
	LinkedStack* pReturn = NULL;

	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));

	if (pReturn != NULL)
		memset(pReturn, 0, sizeof(LinkedStack));
	else
		printf("Dynamic allocation error : CreateLinkedStack\n");

	return pReturn;
}

int LinkedStackPush(LinkedStack* Stack, LinkedStackNode* NewNode)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		NewNode->pNode = Stack->pNode;
		Stack->pNode = NewNode;
		Stack->CurrentNodeCount++;
		ret = TRUE;
	}
	else
		printf("Stack NULL : LinkedStackPop\n");
	return ret;
}

int LinkedStackPop(LinkedStack* Stack)
{
	int ret = FALSE;
	LinkedStackNode* DeleteNode = NULL;
	if (Stack != NULL)
	{
		if (Stack->CurrentNodeCount > 0)
		{
			ret = Stack->pNode->StackData.data;
			DeleteNode = Stack->pNode;
			Stack->pNode = Stack->pNode->pNode;
			Stack->CurrentNodeCount--;
		}
		else
			printf("Stack is empty : LinkedStackPop\n");
	}
	else
		printf("Stack is NULL : LinkedStackPop");
	return ret;
}

int LinkedStackPeak(LinkedStack* Stack)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		if (Stack->CurrentNodeCount > 0)
			ret = Stack->pNode->StackData.data;

		else
			printf("Stack is empty : LinkedStackPeak\n");
	}
	else
		printf("Stack is NULL : LinkedStackPeak\n");

	return ret;
}

int DeleteLinkedStack(LinkedStack* Stack)
{
	int ret = FALSE;
	if (Stack != NULL)
	{
		LinkedStackNode* CurrentNode = Stack->pNode;
		LinkedStackNode* NextNode = NULL;
		free(Stack);
	}
	else
		printf("Stack is NULL");

	return ret;
}

void LinkedStackInfo(LinkedStack* Stack)
{
	if (Stack != NULL)
	{
		LinkedStackNode* CurrentNode = Stack->pNode;
		printf("Number of Node : %d\n", Stack->CurrentNodeCount);
		printf("Top\n");
		for (int i = 0; i < Stack->CurrentNodeCount; i++)
		{
			printf("%d\n", CurrentNode->StackData.data);
			CurrentNode = CurrentNode->pNode;
		}
		printf("\n");
	}
	else
		printf("Stack is NULL : LinkedStackInfo\n");
}
