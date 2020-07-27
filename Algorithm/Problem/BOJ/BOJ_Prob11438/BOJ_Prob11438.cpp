#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, MaxIndex;
	scanf("%d", &N);
	MaxIndex = (int)ceil(log2(N));
	vector<vector<int>> graph(N + 1);
	vector<vector<int>> parents(N + 1, vector<int>(MaxIndex));
	vector<int> heights(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		graph[head].push_back(tail);
		graph[tail].push_back(head);
	}

	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	while (!q.empty()) {
		int now = q.front().first;
		int height = q.front().second;
		heights[now] = height;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int Next = graph[now][i];
			if (!heights[Next]) {
				parents[Next][0] = now;
				for (int j = 1; j < MaxIndex; j++) {
					int temp = parents[Next][j - 1];
					parents[Next][j] = parents[temp][j - 1];
				}
				q.push(make_pair(Next, height + 1));
			}
		}
	}

	scanf("%d", &M);
	while (M--) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);

		if (heights[node1] < heights[node2]) swap(node1, node2);

		for (int i = MaxIndex - 1; i >= 0; i--)
			if (heights[node2] <= heights[parents[node1][i]])
				node1 = parents[node1][i];

		for (int i = MaxIndex - 1; i >= 0; i--)
			if (parents[node1][i] != parents[node2][i]) {
				node1 = parents[node1][i];
				node2 = parents[node2][i];
			}
		if (node1 == node2) printf("%d\n", node1);
		else printf("%d\n", parents[node1][0]);
	}

	return 0;
}