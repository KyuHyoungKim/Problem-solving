#pragma once

typedef struct LinkedListNodeType {
	int data;
	LinkedListNodeType* pNode;
}LinkedListNode;

typedef struct LinkedListType {
	int CurrentNodeCount;
	LinkedListNode* pNode;
}LinkedList;

typedef struct GraphType {
	int MaxNodeCount;
	int CurrentNodeCount;
	int* NodeArray;
	LinkedList** EdgeArray;
}Graph;

Graph* CreateGraph(int MaxNodeCount);

void DeleteGraph(Graph* Gra);

void AddGraphNode(Graph* Gra, int Index);

void DeleteGraphNode(Graph* Gra, int Index);

void AddElementLL(LinkedList* LL, int Data);

void AddGraphEdge(Graph* Gra, int Head, int Tail);

void DeleteGraphEdge(Graph* Gra, int Head, int Tail);

void DistplayGraph(Graph* Gra);
