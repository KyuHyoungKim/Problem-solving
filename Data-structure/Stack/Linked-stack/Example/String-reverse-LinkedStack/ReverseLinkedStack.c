#include "LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedListStack* CreateStack()
{
	LinkedListStack* pReturn = NULL;

	pReturn = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(LinkedListStack));
		pReturn->pLink = (LLNode*)malloc(sizeof(LLNode));
		if (pReturn->pLink != NULL)
		{
			memset(pReturn->pLink, 0, sizeof(LLNode));
		}
		else
		{
			printf("Dynamic allocation error : CreateStack\n");
			free(pReturn);
		}
	}
	else
		printf("Dynamic allocation error : CreateStack\n");

	return pReturn;
}

int PushLLS(LinkedListStack* Stack, char NewData)
{
	int ret = FALSE;
	
	if (Stack != NULL)
	{
		LLNode* NewNode = (LLNode*)malloc(sizeof(LLNode));
		if (NewNode != NULL)
		{
			ret = TRUE;
			NewNode->data = NewData;
			NewNode->pLink = Stack->pLink;
			Stack->pLink = NewNode;
			Stack->CurrentElementCount++;
		}
		else
			printf("Dynamic allocation error : PushLLS\n");
	}
	else
		printf("Stack is NULL : PushLLS\n");

	return ret;
}

char PopLLS(LinkedListStack* Stack)
{
	char ret = NULL;
	LLNode* DeletedNode = NULL;

	if (Stack != NULL)
	{
		if (Stack->CurrentElementCount > 0)
		{
			ret = Stack->pLink->data;
			DeletedNode = Stack->pLink;
			Stack->pLink = Stack->pLink->pLink;
			free(DeletedNode);
			Stack->CurrentElementCount--;
		}
		else
			printf("Stack is empty : PopLLS\n");
	}
	else
		printf("Stack is NULL\n");

	return ret;
}

void ReverseString(char Original_string[], char Reversed_string[])
{
	LinkedListStack* ReverseStack = NULL;

	ReverseStack = CreateStack();

	for (int i = 0; i < strlen(Original_string); i++)
		PushLLS(ReverseStack, Original_string[i]);

	for (int i = 0; i < strlen(Original_string); i++)
		Reversed_string[i] = PopLLS(ReverseStack);

	return;
}
