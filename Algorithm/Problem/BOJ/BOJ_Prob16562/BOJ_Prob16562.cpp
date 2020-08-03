#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K, res = 0;
	scanf("%d %d %d", &N, &M, &K);
	vector<vector<int>> graph(N);
	vector<int> costs(N);
	vector<bool> checked(N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &costs[i]);
	for (int i = 0; i < M; i++) {
		int node1, node2;
		scanf("%d %d", &node1, &node2);
		graph[node1 - 1].push_back(node2 - 1);
		graph[node2 - 1].push_back(node1 - 1);
	}

	for (int i = 0; i < N; i++) {
		if (checked[i]) continue;
		int min_cost = 100000000;
		queue<int> q;
		checked[i] = true;
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (costs[now] < min_cost) min_cost = costs[now];
			for (int j = 0; j < graph[now].size(); j++) {
				int Next = graph[now][j];
				if (!checked[Next]) {
					q.push(Next);
					checked[Next] = true;
				}
			}
		}
		res += min_cost;
	}
	if (res > K) printf("Oh no\n");
	else printf("%d\n", res);
	return 0;
}