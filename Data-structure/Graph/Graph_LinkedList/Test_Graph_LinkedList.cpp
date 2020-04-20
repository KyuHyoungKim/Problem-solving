#include "Graph_LinkedList.h"
#include <stdio.h>

int main()
{
	Graph* Test_Gra = NULL;

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

	DistplayGraph(Test_Gra);
	DeleteGraph(Test_Gra);
	return 0;
}