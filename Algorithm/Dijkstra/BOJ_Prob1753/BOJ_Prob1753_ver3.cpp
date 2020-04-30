#define _CRT_SECURE_NO_WARNINGS
#define INF 987654321

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class comp {
public :
	bool operator() (pair<int, int> a, pair<int, int> b)
	{
		return a.second > b.second;
	}
};

int main()
{
	// Declaration and Input part
	int Num_of_Node = 0, Num_of_Edge = 0, Start_Node;
	priority_queue<pair<int, int>,vector<pair<int,int>>,comp> pq;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &Num_of_Node, &Num_of_Edge, &Start_Node);
	vector<int> Dist(Num_of_Node + 1,INF);
	vector<vector<pair<int, int>>> Edge(Num_of_Node + 1);

	for (int i = 0; i < Num_of_Edge; i++)
	{
		int Tail, Head, Dist;
		scanf("%d %d %d",&Tail, &Head, &Dist);
		Edge[Tail].push_back(make_pair(Head, Dist));
	}
	pq.push(make_pair(Start_Node, 0));
	Dist[Start_Node] = 0;

	// Dijkstra algorithm part
	do {
		int here = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (Dist[here] < cost)
			continue;

		for (int i = 0; i < Edge[here].size(); ++i)
		{
			int next = Edge[here][i].first;
			int next_dist = cost + Edge[here][i].second;
			if (Dist[next] > next_dist)
			{
				pq.push(make_pair(next, next_dist));
				Dist[next] = next_dist;
			}
		}
	} while (!pq.empty());

	// Output part
	for (int i = 1; i < Dist.size(); i++)
	{
		if (Dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", Dist[i]);
	}

	return 0;
}