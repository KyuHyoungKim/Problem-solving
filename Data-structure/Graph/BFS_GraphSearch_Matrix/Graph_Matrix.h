#pragma once

typedef struct GraphType {
	int MaxNodeCount;
	int CurrentNodeCount;
	int* NodeArr;
	int** EdgeArr;
}Graph;

Graph* CreateGraph(int MaxNodeCount);

void DeleteGraph(Graph* Gra);

int IsFullGraph(Graph* Gra);

void AddNode(Graph* Gra, int Index);

void DeleteNode(Graph* Gra, int Index);

void AddEdge(Graph* Gra, int Head, int Tail);

void DeleteEdge(Graph* Gra, int Head, int Tail);

void DisplayGraph(Graph* Gra);
