#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct edge {
	int head = -1;
	int tail = -1;
	double weight = -1;
};
struct comp {
	bool operator()(const edge& a, const edge& b) {
		return a.weight > b.weight;
	}
};
vector<int> root;
int find_root(int idx) {
	if (root[idx] == idx)
		return idx;
	else
		return root[idx] = find_root(root[idx]);
}
void unionize(int idx1, int idx2) {
	idx1 = find_root(idx1);
	idx2 = find_root(idx2);
	if (idx1 > idx2) swap(idx1, idx2);
	root[idx2] = idx1;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, edge_cnt = 0;
	double res = 0;
	scanf("%d %d", &N, &M);
	vector<pair<int, int>> coordinates(N + 1);
	priority_queue<edge, vector<edge>, comp> pq;
	root.resize(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &coordinates[i].first, &coordinates[i].second);
		root[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		unionize(head, tail);
		edge_cnt++;
	}
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++) {
			if (find_root(i) == find_root(j)) continue;
			edge temp;
			int dx = coordinates[i].first - coordinates[j].first;
			int dy = coordinates[i].second - coordinates[j].second;

			temp.head = i;
			temp.tail = j;
			temp.weight = sqrt(pow(dx, 2) + pow(dy, 2));
			pq.push(temp);
		}

	while (!pq.empty()) {
		int head = pq.top().head;
		int tail = pq.top().tail;
		double weight = pq.top().weight;
		pq.pop();
		if (find_root(head) == find_root(tail)) continue;
		edge_cnt++;
		res += weight;
		unionize(head, tail);
		if (edge_cnt == N - 1)
			break;
	}
	printf("%.2lf", res);
	return 0;
}