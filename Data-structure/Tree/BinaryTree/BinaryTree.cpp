#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinTreeNodeType
{
	int Data;
	struct BinTreeNodeType* pLeft;
	struct BinTreeNodeType* pRight;
}BinTreeNode;

void InsertBT(BinTreeNode** Tree, int Val);
BinTreeNode* SearchBT(BinTreeNode* Tree, int Val);
void DeleteBT(BinTreeNode* Tree);
void DeleteNodeBT(BinTreeNode* Tree, int val);
void PrintBT(BinTreeNode* Tree);

int main(void)
{
	BinTreeNode* Tree = NULL;
	BinTreeNode* DeletedNode = NULL;

	InsertBT(&Tree, 5);
	InsertBT(&Tree, 3);
	InsertBT(&Tree, 9);
	InsertBT(&Tree, 1);
	InsertBT(&Tree, 4);
	InsertBT(&Tree, 6);
	InsertBT(&Tree, 10);
	InsertBT(&Tree, 2);
	InsertBT(&Tree, 7);
	InsertBT(&Tree, 8);
	
	printf("Print Binary Tree\n");
	PrintBT(Tree);

	DeleteNodeBT(Tree, 9);

	printf("Print Binary Tree\n");
	PrintBT(Tree);

	DeleteBT(Tree);
	return 0;
}

void InsertBT(BinTreeNode** Tree, int Val)
{
	if (!(*Tree))
	{
		*Tree = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		if (*Tree)
		{
			(*Tree)->Data = Val;
			(*Tree)->pLeft = NULL;
			(*Tree)->pRight = NULL;
		}
		else
			printf("Dynamic allocation error : AddNodeBT\n");
	}
	else
	{
		if ((*Tree)->Data > Val)
		{
			InsertBT(&(*Tree)->pLeft, Val);
		}
		else
		{
			InsertBT(&(*Tree)->pRight, Val);
		}
	}
}

BinTreeNode* SearchBT(BinTreeNode* Tree, int Val)
{
	BinTreeNode* pReturn = Tree;
	if (Tree)
	{
		if (Tree->Data == Val);
		else if (Tree->Data > Val)
		{
			pReturn = Tree->pLeft;
			pReturn = SearchBT(pReturn, Val);
		}
		else
		{
			pReturn = Tree->pRight;
			pReturn = SearchBT(pReturn, Val);
		}
	}
	else
		printf("Tree is NULL : SearchBT\n");

	return pReturn;
}

void DeleteBT(BinTreeNode* Tree)
{
	if (Tree)
	{
		DeleteBT(Tree->pLeft);
		DeleteBT(Tree->pRight);
		free(Tree);
	}
}

void DeleteNodeBT(BinTreeNode* Tree, int val)
{
	if (Tree)
	{
		if (Tree->Data == val)
			DeleteBT(Tree);
		else
		{
			if (Tree->Data > val)
			{
				if (Tree->pLeft->Data == val)
				{
					free(Tree->pLeft);
					Tree->pLeft = NULL;
				}
				else if (Tree->pLeft->Data > val)
					DeleteNodeBT(Tree->pLeft, val);
				else
					DeleteNodeBT(Tree->pRight, val);
			}
			else
			{
				if (Tree->pRight->Data == val)
				{
					free(Tree->pRight);
					Tree->pRight = NULL;
				}
				else if (Tree->pLeft->Data > val)
					DeleteNodeBT(Tree->pLeft, val);
				else
					DeleteNodeBT(Tree->pRight, val);
			}
		}
	}
}

void PrintBT(BinTreeNode* Tree)
{
	BinTreeNode* temp = Tree;
	if (Tree)
	{
		printf("%d\n", temp->Data);
		PrintBT(temp->pLeft);
		PrintBT(temp->pRight);
	}
}