#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNodeType
{
	int data;
	struct StackNodeType* pLink;
}Node;

typedef struct StackType
{
	int CurrentNodeCount;
	Node* headerNode;
}Stack;

Stack* CreateStack();
void Push(Stack* Stack_input, int Element);
int Pop(Stack* Stack_input);
int Size(Stack* Stack_input);
int IsEmpty(Stack* Stack_input);
int Top(Stack* Stack_input);
void DeleteNode(Node* Node);

int main(void)
{
	int N = 0;
	int temp_int = 0; char temp_str[10] = { NULL };
	Stack* my_stack = CreateStack();

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &temp_str);

		if (!strcmp(temp_str, "push"))
		{
			scanf("%d", &temp_int);
			Push(my_stack, temp_int);
		}
		else if (!strcmp(temp_str, "pop"))
		{
			printf("%d\n", Pop(my_stack));
		}
		else if (!strcmp(temp_str, "size"))
		{
			printf("%d\n", Size(my_stack));
		}
		else if (!strcmp(temp_str, "empty"))
		{
			printf("%d\n", IsEmpty(my_stack));
		}
		else if (!strcmp(temp_str, "top"))
		{
			printf("%d\n", Top(my_stack));
		}
	}

	DeleteNode(my_stack->headerNode);
	free(my_stack);

	return 0;
}

Stack* CreateStack()
{
	Stack* pReturn = NULL;
	pReturn = (Stack*)malloc(sizeof(Stack));
	if (pReturn)
	{
		memset(pReturn, 0, sizeof(Stack));
		pReturn->headerNode = (Node*)malloc(sizeof(Node));
		if (pReturn->headerNode)
			memset(pReturn->headerNode, 0, sizeof(Node));
		else
		{
			free(pReturn);
			pReturn = NULL;
		}
	}

	return pReturn;
}

void DeleteNode(Node* Node)
{
	if (Node->pLink)
		DeleteNode(Node->pLink);
	free(Node);
}

void Push(Stack* Stack_input, int Element)
{
	if (Stack_input)
	{
		Node* NewNode = NULL;
		NewNode = (Node*)malloc(sizeof(Node));
		NewNode->data = Element;
		NewNode->pLink = Stack_input->headerNode->pLink;
		Stack_input->headerNode->pLink = NewNode;

		Stack_input->CurrentNodeCount++;
	}
}

int Pop(Stack* Stack_input)
{
	int ret = 0;
	Node* DeletedNode=Stack_input->headerNode->pLink;
	if (Stack_input->CurrentNodeCount > 0)
	{
		ret = DeletedNode->data;
		Stack_input->headerNode->pLink = DeletedNode->pLink;
		free(DeletedNode);
		Stack_input->CurrentNodeCount--;
	}
	else
		ret = -1;
	return ret;
}

int Size(Stack* Stack_input)
{
	return Stack_input->CurrentNodeCount;
}

int IsEmpty(Stack* Stack_input)
{
	int ret = true;
	if (Stack_input->CurrentNodeCount > 0)
		ret = false;

	return ret;
}

int Top(Stack* Stack_input)
{
	int ret = -1;
	if(Stack_input->CurrentNodeCount>0)
		ret= Stack_input->headerNode->pLink->data;
	return ret;
}