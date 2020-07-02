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
	vector<int> dist(N,INF);
	priority_queue<pair<int, int>,vector<pair<int,int>>, comp> pq;
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
int BFS(vector<vector<pair<int, int>>>& graph, int st, int en, int N) {
	queue<pair<int, int>> q;
	vector<int> dist(N,INF);
	q.push(make_pair(st, 0));
	while (!q.empty()) {
		int pos = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (dist[pos] < cost) continue;
		dist[pos] = cost;
		for (int i = 0; i < graph[pos].size(); i++) {
			int new_pos = graph[pos][i].first;
			int new_cost = graph[pos][i].second + cost;
			if (dist[new_pos] > new_cost) 
				q.push(make_pair(new_pos, new_cost));
		}
	}
	return dist[en];
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
		int dist = BFS(graph, i, X - 1, N);
		if (res < dist + dist_comback[i]) 
			res = dist + dist_comback[i];
	}
	printf("%d", res);
	return 0;
}