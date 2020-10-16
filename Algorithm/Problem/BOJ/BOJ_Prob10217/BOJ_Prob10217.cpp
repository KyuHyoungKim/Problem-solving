#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class Edge {
public:
	int node, cost, dist;

	Edge(int v, int c, int d) {
		this->node = v;
		this->cost = c;
		this->dist = d;
	}
};

class comp {
public:
	bool operator()(const Edge& a, const Edge& b) {
		return a.dist > b.dist;
	}
};

priority_queue<Edge, vector<Edge>, comp> pq;
vector<vector<Edge>> graph;
vector<vector<int>> visited;

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, K, res = INF;
		scanf("%d %d %d", &N, &M, &K);
		graph = vector<vector<Edge>>(N + 1);
		visited = vector<vector<int>>(N + 1, vector<int>(M + 1, INF));
		while (!pq.empty())
			pq.pop();
		for (int i = 0; i < K; i++) {
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			graph[u].push_back(Edge(v, c, d));
		}
		pq.push(Edge(1, 0, 0));

		while (!pq.empty()) {
			int node = pq.top().node;
			int cost = pq.top().cost;
			int dist = pq.top().dist;
			pq.pop();
			if (node == N) {
				res = dist;
				break;
			}

			for (int i = 0; i < graph[node].size(); i++) {
				int node_new = graph[node][i].node;
				int cost_new = cost + graph[node][i].cost;
				int dist_new = dist + graph[node][i].dist;
				if (cost_new > M)
					continue;
				if (visited[node_new][cost_new] <= dist_new)
					continue;

				pq.push(Edge(node_new, cost_new, dist_new));
				for (int i = cost_new; i <= M; i++) {
					if (visited[node_new][i] <= dist_new)
						break;
					visited[node_new][i] = dist_new;
				}
			}
		}
		if (res == INF)
			printf("Poor KCM\n");
		else
			printf("%d\n", res);
	}
	return 0;
}