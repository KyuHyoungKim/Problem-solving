#include "Graph_Matrix.h"
#include <iostream>
#include <stack>

using namespace std;

void BFS(Graph* Gra, int start);

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

	BFS(Test_Gra, 0);

	DeleteGraph(Test_Gra);

	return 0;
}

void BFS(Graph* Gra, int start)
{
	stack<int> BFS_Stack;
	int checked = 0, CurrentNode = 0;
	BFS_Stack.push(start);
	checked |= 1 << start;
	do {
		CurrentNode = BFS_Stack.top();
		BFS_Stack.pop();
		printf("%d\n", CurrentNode);
		for (int i = 0; i < Gra->MaxNodeCount; i++)
			if (Gra->EdgeArr[CurrentNode][i] && !(checked & (1 << i)))
			{
				BFS_Stack.push(i);
				checked |= 1 << i;
			}
	} while (!BFS_Stack.empty());
}