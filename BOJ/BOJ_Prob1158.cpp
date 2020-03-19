#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct CircularLinkedListNodeType
{
	int data;
	struct CircularLinkedListNodeType* pLink;
}CLLNode;
typedef struct CircularLinkedListType
{
	int Num_of_Element;
	CLLNode* HeaderNode;
}CLL;

CLL* CreateList();
void AddCLLElement(CLL* List, int Position, int NewElement);
void DeleteCLL(CLL* List);
int* Josephus_permutation(CLL* List, int K);

int main(void)
{
	int input_N = 0, input_K = 0;
	int* Result = NULL;
	CLL* List = CreateList();

	scanf("%d %d", &input_N, &input_K);

	for (int i = 1; i <= input_N; i++)
		AddCLLElement(List, i, i);

	Result = Josephus_permutation(List,input_K);

	printf("<");
	for (int i = 0; i < input_N-1; i++)
		printf("%d, ", Result[i]);
	printf("%d>\n", Result[input_N - 1]);
	DeleteCLL(List);

	return 0;
}

CLL* CreateList()
{
	CLL* pReturn = NULL;
	pReturn = (CLL*)malloc(sizeof(CLL));

	if (pReturn != NULL)
	{
		memset(pReturn, 0, sizeof(CLL));
		pReturn->HeaderNode = (CLLNode*)malloc(sizeof(CLLNode));
		if (pReturn->HeaderNode != NULL)
			memset(pReturn->HeaderNode, 0, sizeof(CLLNode));
		else
		{
			free(pReturn);
			printf("Dynamic allocation error 2 : CreateList\n");
		}
	}
	else
		printf("Dynamic allocation error : CreateList\n");

	return pReturn;
}
void AddCLLElement(CLL* List, int Position, int NewElement)
{
	CLLNode* NewNode = NULL;
	CLLNode* PreviousNode = List->HeaderNode;
	if (List != NULL)
	{
		if (Position > 0 && Position <= List->Num_of_Element+1)
		{
			NewNode = (CLLNode*)malloc(sizeof(CLLNode));
			if (NewNode == NULL)
				printf("Dynamic allocation error : AddCLLElemet");
			else
			{
				if (Position == 1)
				{
					if (List->Num_of_Element == 0)
					{
						PreviousNode->pLink = NewNode;
						NewNode->pLink = PreviousNode->pLink;
					}
					else
					{
						for (int i = 0; i < List->Num_of_Element; i++)
							PreviousNode = PreviousNode->pLink;
						NewNode->pLink = List->HeaderNode->pLink;
						PreviousNode->pLink = NewNode;
						List->HeaderNode->pLink = NewNode;
					}
				}
				else
				{
					for (int i = 0; i < Position-1; i++)
						PreviousNode = PreviousNode->pLink;
					NewNode->pLink = PreviousNode->pLink;
					PreviousNode->pLink = NewNode;
				}
				NewNode->data = NewElement;
				List->Num_of_Element++;
			}
		}
		else
			printf("Position index error : AddCLLElement\n");
	}
	else
		printf("List is NULL : AddCLLElement\n");
}
int* Josephus_permutation(CLL* List, int K)
{
	int* ret = NULL;
	CLLNode* previousNode = List->HeaderNode;
	CLLNode* DeletedNode = NULL;
	if (List != NULL)
	{
		ret = (int*)malloc(sizeof(int) * List->Num_of_Element);
		if (ret != NULL)
		{
			memset(ret, 0, sizeof(int) * List->Num_of_Element);
			int i = 0;
			while (List->Num_of_Element > 0)
			{
				for (int i = 0; i < K - 1; i++)
					previousNode = previousNode->pLink;
				ret[i] = previousNode->pLink->data;
				DeletedNode = previousNode->pLink;
				previousNode->pLink = DeletedNode->pLink;
				free(DeletedNode);
				List->Num_of_Element--;
				i++;
			}
		}
		else
			printf("Dynamic allocation error : Josephus_permutation");
	}
	else
		printf("List is NULL : Josephus_permutation\n");
	return ret;
}
void DeleteCLL(CLL* List)
{
	if (List != NULL)
	{
		free(List->HeaderNode);
		free(List);
	}
	else
		printf("List is NULL : DeleteCLL\n");
}