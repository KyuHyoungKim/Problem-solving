#define _CRT_SECURE_NO_WARNINGS
#define INF 10000000

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> check;

int Find_MinIndex(vector<int> ret);
bool comp(const vector<int> a, const vector<int> b)
{
	return a[0] < b[0];
}

int main()
{
	int NodeCount = 0, EdgeCount = 0, CurrentNode = 0, Count = 1;	
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &NodeCount, &EdgeCount, &CurrentNode);
	vector<vector<int>> Edge(EdgeCount, vector<int>(3)); // Tail, Head, Weight
	vector<int> ret(NodeCount+2,INF);
	vector<int> Edge_TailNode_Index(NodeCount + 2, -1);
	Edge_TailNode_Index[1] = 0;
	Edge_TailNode_Index[NodeCount + 1] = Edge.size();
	for (int i = 0; i < EdgeCount; ++i)
		scanf("%d %d %d", &Edge[i][0], &Edge[i][1], &Edge[i][2]);
	sort(Edge.begin(), Edge.end(), comp);
	
	check.resize(NodeCount + 1);
	ret[CurrentNode] = 0;
	check[CurrentNode] = true;
	for (int i = 0; i < EdgeCount; i++)
		if (Edge[i][0] == CurrentNode)
			ret[Edge[i][1]] = Edge[i][2];

	int EdgeIndexTemp = 1;
	for (int i = 0; i < Edge.size(); ++i)
	{
		if (Edge[i][0]>EdgeIndexTemp)
		{
			if (Edge[i][0] - EdgeIndexTemp > 1)
				EdgeIndexTemp += Edge[i][0] - EdgeIndexTemp - 1;
			Edge_TailNode_Index[EdgeIndexTemp + 1] = i;
			++EdgeIndexTemp;
		}
	}

	do {
		CurrentNode = Find_MinIndex(ret);
		check[CurrentNode] = true;
		++Count;
		for (int i = Edge_TailNode_Index[CurrentNode];i >= 0 && i < Edge_TailNode_Index[CurrentNode+1]; i++)
			if (Edge[i][0] == CurrentNode && !(check[Edge[i][1]]))
			{
				if(ret[Edge[i][1]] > ret[CurrentNode] + Edge[i][2])
					ret[Edge[i][1]] = ret[CurrentNode] + Edge[i][2];
			}
	} while (Count != NodeCount);

	for (int i = 1; i < ret.size() - 1; i++)
	{
		if (ret[i] != INF)
			printf("%d\n", ret[i]);
		else
			printf("INF\n");
	}

	return 0;
}

int Find_MinIndex(vector<int> ret)
{
	int Min_Index = 0, Min_Value = INF;

	for(int i = 1 ; i <ret.size()-1; i++)
		if (!check[i] && ret[i] < Min_Value)
		{
			Min_Value = ret[i];
			Min_Index = i;
		}

	return Min_Index;
}