#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
vector<int> Dijkstra(vector<vector<pair<int, int>>>& graph, int N, int st) {
	vector<int> dist(N, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push(make_pair(st, 0));
	while (!pq.empty()) {
		int curr_pos = pq.top().first;
		int curr_dist = pq.top().second;
		pq.pop();
		if (dist[curr_pos] < curr_dist) continue;
		dist[curr_pos] = curr_dist;
		for (int i = 0; i < graph[curr_pos].size(); i++) {
			int new_pos = graph[curr_pos][i].first;
			int new_dist = graph[curr_pos][i].second + curr_dist;
			if (dist[new_pos] > new_dist)
				pq.push(make_pair(new_pos, new_dist));
		}
	}
	return dist;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, X, res = 0;
	scanf("%d %d %d", &N, &M, &X);
	vector<vector<pair<int, int>>> graph(N);
	for (int i = 0; i < M; i++) {
		int st, en, we;
		scanf("%d %d %d", &st, &en, &we);
		graph[st - 1].push_back(make_pair(en - 1, we));
	}
	vector<int> dist_comback = Dijkstra(graph, N, X - 1);
	for (int i = 0; i < N; i++) {
		vector<int> dist = Dijkstra(graph, N, i);
		if (res < dist[X - 1] + dist_comback[i])
			res = dist[X - 1] + dist_comback[i];
	}
	printf("%d", res);
	return 0;
}