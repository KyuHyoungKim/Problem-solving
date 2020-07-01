#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

pair<int,int> BFS(vector<vector<pair<int, int>>>& graph, int N, int start) {
	pair<int, int> max = { 0, 0 };
	vector<int> dist(N, 123456789);
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	while (!q.empty()) {
		int now_pos = q.front().first;
		int now_dist = q.front().second;
		q.pop();
		if (now_dist > dist[now_pos]) continue;
		dist[now_pos] = now_dist;
		if (now_dist > max.second) {
			max.first = now_pos;
			max.second = now_dist;
		}
		for (int i = 0; i < graph[now_pos].size(); i++) {
			int next_pos = graph[now_pos][i].first;
			int next_dist = now_dist + graph[now_pos][i].second;
			if (dist[graph[now_pos][i].first] > next_dist)
				q.push(make_pair(next_pos, next_dist));
		}
	}
	return max;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<vector<pair<int, int>>> graph(N);
	for (int i = 0; i < N; i++)
	{
		int node1, node2, weight;
		scanf("%d %d %d", &node1, &node2, &weight);
		graph[node1 - 1].push_back(make_pair(node2 - 1, weight));
		graph[node2 - 1].push_back(make_pair(node1 - 1, weight));
	}
	pair<int, int> max;
	max = BFS(graph, N, 0);
	max = BFS(graph, N, max.first);
	printf("%d", max.second);
	return 0;
}