#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000
using namespace std;

int check = 1;

int Find_MinIndex(vector<int> ret);
bool comp(const vector<int> a, const vector<int> b)
{
	return a[0] < b[0];
}

int main()
{
	int V = 0, E = 0, K = 0;
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &V, &E, &K);
	vector<vector<int>> Edge(E, vector<int>(3)); // Tail, Head, Weight
	vector<int> ret(V+2,INF);
	for (int i = 0; i < E; ++i)
		scanf("%d %d %d", &Edge[i][0], &Edge[i][1], &Edge[i][2]);
	sort(Edge.begin(), Edge.end(), comp);
	
	ret[K] = 0;
	check |= 1 << K;
	for (int i = 0; i < E; i++)
		if (Edge[i][0] == K)
			ret[Edge[i][1]] = Edge[i][2];

	do {
		K = Find_MinIndex(ret);
		check |= 1 << K;
		for (int i = 0; i < E; i++)
			if (Edge[i][0] == K && !(check & 1 << Edge[i][1]))
			{
				if(ret[Edge[i][1]] > ret[K] + Edge[i][2])
					ret[Edge[i][1]] = ret[K] + Edge[i][2];
			}
	} while (check != (1 << V) - 1);

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

	for(int i = 0 ; i <ret.size(); i++)
		if (!(check & 1 << i) && ret[i] < Min_Value)
		{
			Min_Value = ret[i];
			Min_Index = i;
		}

	return Min_Index;
}