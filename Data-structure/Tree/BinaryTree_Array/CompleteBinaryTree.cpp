#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNodeType
{
	int data;
	struct BinaryTreeNodeType* pLchild;
	struct BinaryTreeNodeType* pRchild;
}BinaryTreeNode;

typedef struct BinaryTreeType
{
	int MaxNodeCount;
	int CurrentNodeCount;
	BinaryTreeNode* Node;
}BinaryTree;

BinaryTree* CreateCBT(int MaxNumofNode);
void DeleteCBT(BinaryTree* Tree);
void InsertNode(BinaryTree* Tree, int key);
void DeleteNode(BinaryTree* Tree);
void PreorderTraversal(BinaryTreeNode* Node);
void InorderTraversal(BinaryTreeNode* Node);
void PostorderTraversal(BinaryTreeNode* Node);

int main(void)
{
	BinaryTree* TestTree = CreateCBT(10);

	for (int i = 1; i <= 11; i++)
		InsertNode(TestTree, i);					// Test insert

	printf("Preorder Traversal :\n");
	PreorderTraversal(&TestTree->Node[1]);			// Test preorder
	printf("Inorder Traversal :\n");
	InorderTraversal(&TestTree->Node[1]);			// Test inorder
	printf("Postorder Traversal :\n");
	PostorderTraversal(&TestTree->Node[1]);			// Test postorder

	DeleteNode(TestTree);
	DeleteNode(TestTree);							// Test DeleteNode

	printf("Preorder Traversal :\n");
	PreorderTraversal(&TestTree->Node[1]);			

	DeleteCBT(TestTree);
	return 0;
}

BinaryTree* CreateCBT(int MaxNumofNode)
{
	BinaryTree* pReturn = NULL;
	if (MaxNumofNode > 0)
	{
		pReturn = (BinaryTree*)malloc(sizeof(BinaryTree));
		if (pReturn)
		{
			memset(pReturn, 0, sizeof(BinaryTree));
			pReturn->Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode) * (MaxNumofNode + 1));
			if (pReturn->Node)
			{
				memset(pReturn->Node, 0, sizeof(BinaryTreeNode) * (MaxNumofNode + 1));
				pReturn->MaxNodeCount = MaxNumofNode;
			}
			else
			{
				printf("Dynamic allocation error 2 : CreateCBT\n");
				free(pReturn);
				pReturn = NULL;
			}
		}
		else
			printf("Dynamic allocation error : CreateBT\n");
	}
	else
		printf("MaxNum index error : CreateCBT\n");

	return pReturn;
}

void DeleteCBT(BinaryTree* Tree)
{
	free(Tree->Node);
	free(Tree);
}

void InsertNode(BinaryTree* Tree, int key)
{
	if (Tree)
	{
		if (Tree->MaxNodeCount > Tree->CurrentNodeCount)
		{
			int Position = Tree->CurrentNodeCount + 1;
			Tree->Node[Position].data = key;
			if (Position % 2 == 0)
				Tree->Node[Position / 2].pLchild = &(Tree->Node[Position]);
			else
				Tree->Node[Position / 2].pRchild = &(Tree->Node[Position]);

			Tree->CurrentNodeCount++;
		}
		else
			printf("Tree is full : InsertNode\n");
	}
	else
		printf("Tree is NULL : InsertNode\n");
}

void DeleteNode(BinaryTree* Tree)
{
	if (Tree)
	{
		if (Tree->CurrentNodeCount > 0)
		{
			Tree->Node[Tree->CurrentNodeCount].data = 0;
			if (Tree->CurrentNodeCount % 2 == 0)
				Tree->Node[Tree->CurrentNodeCount / 2].pLchild = NULL;
			else
				Tree->Node[Tree->CurrentNodeCount / 2].pRchild = NULL;
			Tree->CurrentNodeCount--;
		}
		else
			printf("Tree is empty : DeleteNode\n");
	}
	else
		printf("Tree is NULL : DeleteNode\n");
}

void PreorderTraversal(BinaryTreeNode* Node)
{
	printf("%d\n", Node->data);
	if (Node->pLchild)
		PreorderTraversal(Node->pLchild);
	if (Node->pRchild)
		PreorderTraversal(Node->pRchild);
}

void InorderTraversal(BinaryTreeNode* Node)
{
	if (Node->pLchild)
		InorderTraversal(Node->pLchild);
	printf("%d\n", Node->data);
	if (Node->pRchild)
		InorderTraversal(Node->pRchild);
}

void PostorderTraversal(BinaryTreeNode* Node)
{
	if (Node->pLchild)
		PostorderTraversal(Node->pLchild);
	if (Node->pRchild)
		PostorderTraversal(Node->pRchild);
	printf("%d\n", Node->data);
}