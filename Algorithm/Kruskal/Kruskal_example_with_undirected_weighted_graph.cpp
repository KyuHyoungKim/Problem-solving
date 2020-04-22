#include "Graph_undirected_weighted.h"
#include <algorithm>
#include <vector>

bool compare(const GraphEdge& a, const GraphEdge& b)
{
	return a.weight < b.weight;
}

Graph Kruskal(Graph Gra);
void display(Graph Gra);

int main()
{
	Graph TestGra;
	GraphEdge Edge_temp;
	
	for (int i = 0; i < 6; i++)
		TestGra.Node.push_back(i);
	Edge_temp = { 0, 1, 4 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 0, 2, 3 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 1, 2, 2 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 2, 3, 1 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 3, 4, 1 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 3, 5, 5 };
	TestGra.Edge.push_back(Edge_temp);
	Edge_temp = { 4, 5, 6 };
	TestGra.Edge.push_back(Edge_temp);

	Graph MinSpanning = Kruskal(TestGra);

	display(TestGra);
	display(MinSpanning);

	return 0;
}

Graph Kruskal(Graph Gra)
{
	Graph ret;
	ret.Node = Gra.Node;
	int checked = 0;
	vector<GraphEdge> Sorted_Edge;
	Sorted_Edge = Gra.Edge;
	sort(Sorted_Edge.begin(), Sorted_Edge.end(), compare);

	for (int cnt = 0, i = 0; i < Gra.Edge.size(); i++)
	{
		if (!(checked & (1 << Sorted_Edge[i].Head)) || !(checked & (1 << Sorted_Edge[i].Tail)))
		{
			ret.Edge.push_back(Sorted_Edge[i]);
			checked |= (1 << Sorted_Edge[i].Head);
			checked |= (1 << Sorted_Edge[i].Tail);
			cnt++;
		}
		if (cnt == Gra.Node.size() - 1)
			break;
	}

	return ret;
}

void display(Graph Gra)
{
	printf("Node :");
	for (int i = 0; i < Gra.Node.size(); i++)
		printf("%d ", Gra.Node[i]);
	printf("\nEdge :\n");
	for (int i = 0; i < Gra.Edge.size(); i++)
		printf("%d -> %d\t%d\n", Gra.Edge[i].Head, Gra.Edge[i].Tail, Gra.Edge[i].weight);
}