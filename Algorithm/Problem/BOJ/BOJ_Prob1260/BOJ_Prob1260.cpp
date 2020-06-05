#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, start;
	int node1, node2;
	scanf("%d %d %d", &N, &M, &start);
	N++;
	vector<vector<int>> graph(N);
	vector<int> DFS, BFS, checked(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	for (int i = 0; i < N; i++) sort(graph[i].begin(), graph[i].end(),greater<int>());
	//DFS
	stack<int> dfs;
	for (int i = 0; i < graph[start].size(); i++) dfs.push(graph[start][i]);
	checked[start]++;
	DFS.push_back(start);
	while (!dfs.empty()) {
		int now = dfs.top();
		dfs.pop();
		if (checked[now]) continue;
		checked[now]++;
		DFS.push_back(now);
		for (int i = 0; i < graph[now].size(); i++) dfs.push(graph[now][i]);
	}

	//BFS
	for (int i = 0; i < N; i++) sort(graph[i].begin(), graph[i].end());
	queue<int> bfs;
	checked.clear();
	checked.assign(N, 0);
	checked[start]++;
	BFS.push_back(start);
	for (int i = 0; i < graph[start].size(); i++) bfs.push(graph[start][i]);
	while (!bfs.empty()) {
		int now = bfs.front();
		bfs.pop();
		if (checked[now]) continue;
		checked[now]++;
		BFS.push_back(now);
		for (int i = 0; i < graph[now].size(); i++) bfs.push(graph[now][i]);
	}
	for (int i = 0; i < DFS.size(); i++) printf("%d ", DFS[i]);
	printf("\n");
	for (int i = 0; i < BFS.size(); i++) printf("%d ", BFS[i]);
	return 0;
}