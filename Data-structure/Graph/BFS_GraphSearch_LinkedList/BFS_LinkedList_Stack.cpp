#include "Graph_LinkedList.h"
#include <stack>

using namespace std;

void BFS(Graph* Gra, int start);

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

	BFS(Test_Gra, 0);

	DeleteGraph(Test_Gra);

	return 0;
}

void BFS(Graph* Gra, int start)
{
	stack<int> BFS_Stack;
	int checked = 0, CurrentNode = 0, Data_Temp = 0;
	LinkedListNode* Node_Temp = NULL;
	BFS_Stack.push(start);
	checked |= 1 << start;

	do {
		CurrentNode = BFS_Stack.top();
		BFS_Stack.pop();
		printf("%d\n", CurrentNode);
		
		Node_Temp = Gra->EdgeArray[CurrentNode]->pNode;

		for (int i = 0; i < Gra->EdgeArray[CurrentNode]->CurrentNodeCount; i++)
		{
			Data_Temp = Node_Temp->data;
			if (!(checked & (1 << Data_Temp)))
			{
				BFS_Stack.push(Data_Temp);
				checked |= 1 << Data_Temp;
			}
			Node_Temp = Node_Temp->pNode;
		}

	} while (!BFS_Stack.empty());
}