#include "Graph_LinkedList.h"
#include <iostream>
#include <queue>

using namespace std;

void DFS(Graph* Gra, int start);

int main()
{
	Graph* Test_Gra;
	Test_Gra = CreateGraph(6);
	for (int i = 0; i < 6; i++)
		AddGraphNode(Test_Gra, i);

	AddGraphEdge(Test_Gra, 0, 1);
	AddGraphEdge(Test_Gra, 0, 2);
	AddGraphEdge(Test_Gra, 1, 2);
	AddGraphEdge(Test_Gra, 2, 3);
	AddGraphEdge(Test_Gra, 3, 4);
	AddGraphEdge(Test_Gra, 3, 5);
	AddGraphEdge(Test_Gra, 4, 5);

	DisplayGraph(Test_Gra);

	DFS(Test_Gra, 0);

	DeleteGraph(Test_Gra);

	return 0;
}

void DFS(Graph* Gra, int start)
{
	queue<int> DFS_Queue;
	LinkedListNode* Node_Temp;
	int CurrentNode = 0, checked = 0;
	int Data_Temp = 0;
	DFS_Queue.push(start);
	checked |= 1 << start;

	do {
		CurrentNode = DFS_Queue.front();
		DFS_Queue.pop();
		printf("%d\n", CurrentNode);
		Node_Temp = Gra->EdgeArray[CurrentNode]->pNode;
		for (int i = 0; i < Gra->EdgeArray[CurrentNode]->CurrentNodeCount; i++)
		{
			Data_Temp = Node_Temp->data;
			if (!(checked & 1 << Data_Temp))
			{
				DFS_Queue.push(Data_Temp);
				checked |= 1 << Data_Temp;
			}
			Node_Temp = Node_Temp->pNode;
		}
	} while (!DFS_Queue.empty());

}