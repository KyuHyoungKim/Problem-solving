#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, E;
	scanf("%d %d", &N, &E);
	vector<int> via(2);
	vector<vector<pair<int, int>>> gra(N + 1);
	vector<vector<int>> min_dist(2, vector<int>(N + 1, -1));
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	while (E--) {
		int node1, node2, cost;
		scanf("%d %d %d", &node1, &node2, &cost);
		gra[node1].push_back(make_pair(node2, cost));
		gra[node2].push_back(make_pair(node1, cost));
	}
	scanf("%d %d", &via[0], &via[1]);
	for (int i = 0; i < 2; i++) {
		pq.push(make_pair(via[i], 0));
		while (!pq.empty()) {
			int now = pq.top().first;
			int cost = pq.top().second;
			pq.pop();

			if (min_dist[i][now] >= 0 && min_dist[i][now] < cost) continue;
			min_dist[i][now] = cost;
			for (int j = 0; j < gra[now].size(); j++) {
				int Next = gra[now][j].first;
				int cost_Next = cost + gra[now][j].second;
				if (min_dist[i][Next] < 0 || min_dist[i][Next] >= 0 && min_dist[i][now] > cost)
					pq.push(make_pair(Next, cost_Next));
			}
		}
	}

	if (min_dist[0][1] < 0 || min_dist[0][via[1]] < 0 || min_dist[1][N] < 0) {
		printf("-1\n");
		return 0;
	}
	int a1 = min_dist[0][1] + min_dist[0][via[1]] + min_dist[1][N];
	int a2 = min_dist[1][1] + min_dist[1][via[0]] + min_dist[0][N];
	int res = (a1 < a2) ? a1 : a2;
	printf("%d\n", res);
	return 0;
}