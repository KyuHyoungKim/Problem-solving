#include <iostream>
#include <queue>
#include "Graph_Matrix.h"

using namespace std;

void DFS(Graph* Gra, int start);

int main()
{
	Graph* Test_Gra;
	Test_Gra = CreateGraph(6);
	for (int i = 0; i < 6; i++)
		AddNode(Test_Gra, i);

	AddEdge(Test_Gra, 0, 1);
	AddEdge(Test_Gra, 0, 2);
	AddEdge(Test_Gra, 1, 2);
	AddEdge(Test_Gra, 2, 3);
	AddEdge(Test_Gra, 3, 4);
	AddEdge(Test_Gra, 3, 5);
	AddEdge(Test_Gra, 4, 5);

	DisplayGraph(Test_Gra);

	DFS(Test_Gra, 0);

	DeleteGraph(Test_Gra);

	return 0;
}

void DFS(Graph* Gra, int start)
{
	queue<int> DFS_Queue;
	int checked = 0;
	int Current_Node = 0;
	DFS_Queue.push(start);
	checked = checked | (1 << start);
	do {
		Current_Node = DFS_Queue.front();
		printf("%d\n", Current_Node);
		DFS_Queue.pop();
		for (int i = 0; i < Gra->MaxNodeCount; i++)
			if (Gra->EdgeArr[Current_Node][i] && !(checked & (1 << i) ))
			{
				DFS_Queue.push(i);
				checked = checked | (1 << i);
			}

	} while (!DFS_Queue.empty());

}