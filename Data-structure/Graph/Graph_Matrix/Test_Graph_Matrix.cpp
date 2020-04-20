#include "Graph_Matrix.h"
#include <stdio.h>

int main(void)
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

	DeleteGraph(Test_Gra);
	
	return 0;
}