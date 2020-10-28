#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int N, R, Q;
vector<vector<int>> graph;
vector<vector<int>> tree;
vector<int> DP;

int solution(int node);
void get_graph();
void get_tree();

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &R, &Q);
	get_graph();
	get_tree();

	DP.resize(N + 1);
	DP[R] = N;

	while (Q--) {
		int node;
		scanf("%d", &node);
		printf("%d\n", solution(node));
	}

	return 0;
}

int solution(int node) {
	if (DP[node])
		return DP[node];

	int ret = 1;
	for (int i = 0; i < tree[node].size(); i++)
		ret += solution(tree[node][i]);

	DP[node] = ret;
	return ret;
}

inline void get_graph() {
	graph.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
}

inline void get_tree() {
	vector<bool> check(N + 1);
	queue<int> q;
	tree.resize(N + 1);
	q.push(R);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (check[node]) continue;
		check[node] = true;

		for (int i = 0; i < graph[node].size(); i++) {
			int tail = graph[node][i];
			if (check[tail])
				continue;
			tree[node].push_back(tail);
			q.push(tail);
		}
	}
}