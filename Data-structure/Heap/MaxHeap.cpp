#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MaxHeapNodeType
{
	int data;
	struct MaxHeapNodeType* pLchild;
	struct MaxHeapNodeType* pRchild;
}MaxHeapNode;

typedef struct MaxHeapType
{
	int MaxNodeCount;
	int CurrentNodeCount;
	MaxHeapNode* Node;
}MaxHeap;

MaxHeap* CreateMH(int MaxNodeCount);
void DeleteMH(MaxHeap* Heap);
void InsertNode(MaxHeap* Heap, int key);
void PreorderTraversal(MaxHeapNode* Node);
int DeleteNode(MaxHeap* Heap);
void ComparetoChild(MaxHeapNode* Node);

int main(void)
{
	MaxHeap* TestHeap = CreateMH(10);
	
	InsertNode(TestHeap, 5);
	InsertNode(TestHeap, 3);
	InsertNode(TestHeap, 7);
	InsertNode(TestHeap, 4);
	InsertNode(TestHeap, 4);
	InsertNode(TestHeap, 6);

	printf("7 4 3 4 6 5\n");
	PreorderTraversal(&TestHeap->Node[1]);

	printf("Max : %d\n", DeleteNode(TestHeap));
	printf("Max : %d\n", DeleteNode(TestHeap));
	printf("Max : %d\n", DeleteNode(TestHeap));
	printf("Max : %d\n", DeleteNode(TestHeap));

	DeleteMH(TestHeap);
	return 0;
}

MaxHeap* CreateMH(int MaxNodeCount)
{
	MaxHeap* pReturn = NULL;
	if (MaxNodeCount > 0)
	{
		pReturn = (MaxHeap*)malloc(sizeof(MaxHeap));
		if (pReturn)
		{
			memset(pReturn, 0, sizeof(MaxHeap));
			pReturn->MaxNodeCount = MaxNodeCount;
			pReturn->Node = (MaxHeapNode*)malloc(sizeof(MaxHeapNode) * (MaxNodeCount+1));
			if (pReturn->Node)
				memset(pReturn->Node, 0, sizeof(MaxHeapNode) * (MaxNodeCount+1));
			else
			{
				printf("Dynamic allocation error : CreateMH\n");
				free(pReturn);
				pReturn = NULL;
			}
		}
		else
			printf("Dynamicallocation error : CreateMH\n");
	}
	else
		printf("MaxNodeCount index error : CreateMH\n");
	return pReturn;
}

void DeleteMH(MaxHeap* Heap)
{
	if (Heap)
	{
		free(Heap->Node);
		free(Heap);
	}
	else
		printf("Heap is NULL : DeleteMH\n");
}

void InsertNode(MaxHeap* Heap, int key)
{
	if (Heap)
	{
		Heap->CurrentNodeCount++;
		int Position = Heap->CurrentNodeCount;
		Heap->Node[Heap->CurrentNodeCount].data = key;
		Heap->Node[Heap->CurrentNodeCount].pLchild = NULL;
		Heap->Node[Heap->CurrentNodeCount].pRchild = NULL;
		if (Heap->CurrentNodeCount > 1)
		{
			if (Heap->CurrentNodeCount % 2 == 0)
				Heap->Node[Heap->CurrentNodeCount / 2].pLchild = &(Heap->Node[Heap->CurrentNodeCount]);
			if (Heap->CurrentNodeCount % 2 == 1)
				Heap->Node[Heap->CurrentNodeCount / 2].pRchild = &(Heap->Node[Heap->CurrentNodeCount]);

			for (; key > Heap->Node[Position / 2].data && Position >= 2;)
			{
				Heap->Node[Position].data = Heap->Node[Position / 2].data;
				Heap->Node[Position / 2].data = key;
				Position /= 2;
			}
		}
	}
	else
		printf("Heap is NULL");
}

int DeleteNode(MaxHeap* Heap)
{
	int ret = 0;
	if (Heap)
	{
		ret = Heap->Node[1].data;

		Heap->Node[1].data = Heap->Node[Heap->CurrentNodeCount].data;
		Heap->Node[Heap->CurrentNodeCount].data = 0;
		if (Heap->CurrentNodeCount % 2 == 0)
			Heap->Node[Heap->CurrentNodeCount / 2].pLchild = NULL;
		if (Heap->CurrentNodeCount % 2 == 1)
			Heap->Node[Heap->CurrentNodeCount / 2].pRchild = NULL;
		Heap->CurrentNodeCount--;

		ComparetoChild(&Heap->Node[1]);
	}
	return ret;
}

void ComparetoChild(MaxHeapNode* Node)
{
	int temp = Node->data;
	if (Node->pLchild && Node->data < Node->pLchild->data)
	{
		Node->data = Node->pLchild->data;
		Node->pLchild->data = temp;
		ComparetoChild(Node->pLchild);
	}
	else if (Node->pRchild && Node->data < Node->pRchild->data)
	{
		Node->data = Node->pRchild->data;
		Node->pRchild->data = temp;
		ComparetoChild(Node->pRchild);
	}

}

void PreorderTraversal(MaxHeapNode* Node)
{
	printf("%d\n", Node->data);
	if (Node->pLchild)
		PreorderTraversal(Node->pLchild);
	if (Node->pRchild)
		PreorderTraversal(Node->pRchild);
}