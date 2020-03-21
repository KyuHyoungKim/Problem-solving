#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinTreeNodeType
{
	int Data;
	struct BinTreeNodeType* pLeft;
	struct BinTreeNodeType* pRight;
}BinTreeNode;

void InsertBST(BinTreeNode** Tree, int Val);
BinTreeNode* SearchBST(BinTreeNode* Tree, int Val);
void DeleteBST(BinTreeNode* Tree);
void DeleteNodeBST(BinTreeNode* Tree, int val);
void PreorderTraversalBST(BinTreeNode* Tree);
void PostorderTraversalBST(BinTreeNode* Tree);
void InorderTraversalBST(BinTreeNode* Tree);

int main(void)
{
	BinTreeNode* Tree = NULL;
	BinTreeNode* DeletedNode = NULL;

	InsertBST(&Tree, 5);
	InsertBST(&Tree, 3);
	InsertBST(&Tree, 9);
	InsertBST(&Tree, 1);
	InsertBST(&Tree, 4);
	InsertBST(&Tree, 6);
	InsertBST(&Tree, 10);
	InsertBST(&Tree, 2);
	InsertBST(&Tree, 7);
	InsertBST(&Tree, 8);

	printf("Preorder Traversal\n");
	PreorderTraversalBST(Tree);
	printf("Postorder Traversal\n");
	PostorderTraversalBST(Tree);
	printf("Inorder Traversal\n");
	InorderTraversalBST(Tree);

	DeleteNodeBST(Tree, 9);

	printf("Print Binary Tree\n");
	PreorderTraversalBST(Tree);

	DeleteBST(Tree);
	return 0;
}

void InsertBST(BinTreeNode** Tree, int Val)
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
			printf("Dynamic allocation error : AddNodeBST\n");
	}
	else
	{
		if ((*Tree)->Data > Val)
		{
			InsertBST(&(*Tree)->pLeft, Val);
		}
		else
		{
			InsertBST(&(*Tree)->pRight, Val);
		}
	}
}

BinTreeNode* SearchBST(BinTreeNode* Tree, int Val)
{
	BinTreeNode* pReturn = Tree;
	if (Tree)
	{
		if (Tree->Data == Val);
		else if (Tree->Data > Val)
		{
			pReturn = Tree->pLeft;
			pReturn = SearchBST(pReturn, Val);
		}
		else
		{
			pReturn = Tree->pRight;
			pReturn = SearchBST(pReturn, Val);
		}
	}
	else
		printf("Tree is NULL : SearchBST\n");

	return pReturn;
}

void DeleteBST(BinTreeNode* Tree)
{
	if (Tree)
	{
		DeleteBST(Tree->pLeft);
		DeleteBST(Tree->pRight);
		free(Tree);
	}
}

void DeleteNodeBST(BinTreeNode* Tree, int val)
{
	if (Tree)
	{
		if (Tree->Data == val)
			DeleteBST(Tree);
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
					DeleteNodeBST(Tree->pLeft, val);
				else
					DeleteNodeBST(Tree->pRight, val);
			}
			else
			{
				if (Tree->pRight->Data == val)
				{
					free(Tree->pRight);
					Tree->pRight = NULL;
				}
				else if (Tree->pLeft->Data > val)
					DeleteNodeBST(Tree->pLeft, val);
				else
					DeleteNodeBST(Tree->pRight, val);
			}
		}
	}
}

void PreorderTraversalBST(BinTreeNode* Tree)
{
	BinTreeNode* temp = Tree;
	if (Tree)
	{
		printf("%d\n", temp->Data);
		PreorderTraversalBST(temp->pLeft);
		PreorderTraversalBST(temp->pRight);
	}
}

void PostorderTraversalBST(BinTreeNode* Tree)
{
	if (Tree)
	{
		PostorderTraversalBST(Tree->pLeft);
		PostorderTraversalBST(Tree->pRight);
		printf("%d\n", Tree->Data);
	}
}

void InorderTraversalBST(BinTreeNode* Tree)
{
	if (Tree)
	{
		InorderTraversalBST(Tree->pLeft);
		printf("%d\n", Tree->Data);
		InorderTraversalBST(Tree->pRight);
	}
}