#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
pair<int, int> BFS(vector<vector<pair<int, int>>>& graph, int N, int start) {
	vector<int> dist(N, 10123456789);
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	while (!q.empty()) {
		int now_pos = q.front().first;
		int now_dist = q.front().second;
		q.pop();
		if (now_dist > dist[now_pos]) continue;
		dist[now_pos] = now_dist;
		for (int i = 0; i < graph[now_pos].size(); i++) {
			int next_pos = graph[now_pos][i].first;
			int next_dist = now_dist + graph[now_pos][i].second;
			if (dist[graph[now_pos][i].first] > next_dist)
				q.push(make_pair(next_pos, next_dist));
		}
	}
	pair<int, int> max = { 0, 0 };
	for (int i = 0; i < N; i++)
		if (max.second < dist[i]) {
			max.first = i;
			max.second = dist[i];
		}
	return max;
}

int main() {
	freopen("input.txt", "r", stdin);
	int V;
	scanf("%d", &V);
	vector<vector<pair<int, int>>> graph(V);
	for (int i = 0; i < V; i++)
	{
		int head, tail, weight;
		scanf("%d", &head);
		while (1) {
			scanf("%d", &tail);
			if (tail < 0) break;
			scanf("%d", &weight);
			graph[head - 1].push_back(make_pair(tail - 1, weight));
		}
	}
	pair<int, int> max = BFS(graph, V, 0);
	max = BFS(graph, V, max.first);
	printf("%d", max.second);
	return 0;
}