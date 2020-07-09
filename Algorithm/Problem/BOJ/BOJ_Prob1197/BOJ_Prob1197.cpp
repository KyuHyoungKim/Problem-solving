#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int V, E, res = 0;
	scanf("%d %d", &V, &E);
	vector<vector<pair<int,int>>> graph(V);
	vector<bool> checked(V);
	priority_queue<pair<int, int>, vector<pair<int, int>>,comp> pq;
	for (int i = 0; i < E; i++) {
		int node1, node2, weight;
		scanf("%d %d %d", &node1, &node2, &weight);
		graph[node1 - 1].push_back(make_pair(node2 - 1, weight));
		graph[node2 - 1].push_back(make_pair(node1 - 1, weight));
	}
	for(int i = 0 ; i < V; i++) {
		for (int j = 0; j < graph[0].size(); j++) {
			pq.push(graph[i][j]);
			checked[i] = true;
		}
		if (!pq.empty()) break;
	}
	while (!pq.empty()) {
		int curr = pq.top().first;
		int wei = pq.top().second;
		pq.pop();
		if (checked[curr]) continue;
		res += wei;
		checked[curr] = true;
		for (int i = 0; i < graph[curr].size(); i++) 
			if (!checked[graph[curr][i].first]) 
				pq.push(graph[curr][i]);
	}
	printf("%d\n", res);
	return 0;
}