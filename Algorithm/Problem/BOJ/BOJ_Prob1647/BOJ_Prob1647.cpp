#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0, max = 0, cnt = 0;
	scanf("%d %d", &N, &M);
	vector<vector<pair<int, int>>> graph(N);
	vector<bool> checked(N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	for (int i = 0; i < M; i++) {
		int node1, node2, weight;
		scanf("%d %d %d", &node1, &node2, &weight);
		graph[node1 - 1].push_back(make_pair(node2 - 1, weight));
		graph[node2 - 1].push_back(make_pair(node1 - 1, weight));
	}
	pq.push(make_pair(0, 0));
	while (!pq.empty()) {
		int now_pos = pq.top().first;
		int now_cost = pq.top().second;
		pq.pop();
		if (checked[now_pos]) continue;
		checked[now_pos] = true;
		res += now_cost;
		if (now_cost > max) max = now_cost;
		if (cnt == N - 1) break;
		for (int i = 0; i < graph[now_pos].size(); i++) 
			if (!checked[graph[now_pos][i].first])
				pq.push(graph[now_pos][i]);
	}
	printf("%d", res - max);
	return 0;
}