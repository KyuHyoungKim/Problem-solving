#include "Graph_undirected_weighted.h"
#include <algorithm>
#include <vector>
#include <queue>
Graph Prim(Graph Gra, int start);
void display(Graph Gra);
int findNode(Graph Gra, int Node);

struct compare {

	bool operator()(GraphEdge a, GraphEdge b)
	{
		return a.weight > b.weight;
	}
};

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
	
	Graph MinSpanning = Prim(TestGra,1);

	display(TestGra);
	display(MinSpanning);

	return 0;
}

Graph Prim(Graph Gra, int start) 
{
	Graph ret;
	int checked = 0;
	vector<GraphEdge> Edge_List = Gra.Edge;
	priority_queue <GraphEdge, vector<GraphEdge>,compare> Edge_List_Priority;
	int CurrentNode = start;
	ret.Node.push_back(start);
	
	for (int cnt = 0; cnt < Gra.Node.size() - 1;)
	{
		for (int i = 0;i < (int)Edge_List.size(); i++)
		{
			if ((Edge_List[i].Head == CurrentNode || Edge_List[i].Tail == CurrentNode) && !(checked & 1 << i))
			{
				Edge_List_Priority.push(Edge_List[i]);
				checked |= 1 << i;
			}
		}
		for (int i = 0; i < Edge_List_Priority.size(); i++)
		{
			GraphEdge Edge_Temp;
			Edge_Temp = Edge_List_Priority.top();
			Edge_List_Priority.pop();
			if (findNode(ret, Edge_Temp.Head) < 0 || findNode(ret, Edge_Temp.Tail) < 0)
			{
				ret.Edge.push_back(Edge_Temp);
				cnt++;
				if (findNode(ret, Edge_Temp.Head) < 0)
					ret.Node.push_back(Edge_Temp.Head);
				else
					ret.Node.push_back(Edge_Temp.Tail);
				CurrentNode = ret.Node.back();
				break;
			}
		}
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

int findNode(Graph Gra, int Node)
{
	int ret = -1;
	for (int i = 0; i < Gra.Node.size(); i++)
	{
		if (Gra.Node[i] == Node)
		{
			ret = i;
			break;
		}
	}
	return ret;
}