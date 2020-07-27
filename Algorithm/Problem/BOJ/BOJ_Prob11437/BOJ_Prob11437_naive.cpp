#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d", &N);
	vector<vector<int>> graph(N);
	vector<int> parents(N, -1);
	vector<int> heights(N, -1);
	for (int i = 0; i < N - 1; i++) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		graph[head - 1].push_back(tail - 1);
		graph[tail - 1].push_back(head - 1);
	}

	queue<pair<int,int>> q;
	q.push(make_pair(0, 0));
	parents[0] = 0;
	heights[0] = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int height = q.front().second;
		heights[now] = height;
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int Next = graph[now][i];
			if (heights[Next] < 0) {
				parents[Next] = now;
				q.push(make_pair(Next, height + 1));
			}
		}
	}

	scanf("%d", &M);
	while (M--) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		node1--;
		node2--;

		if (heights[node1] < heights[node2]) swap(node1, node2);
		while (heights[node1] != heights[node2])
			node1 = parents[node1];

		while (node1 != node2) {
			node1 = parents[node1];
			node2 = parents[node2];
		}

		printf("%d\n", node1 + 1);
	}

	return 0;
}