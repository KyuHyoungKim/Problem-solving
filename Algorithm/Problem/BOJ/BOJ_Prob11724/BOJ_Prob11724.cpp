#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r",stdin);
	int N, M, head, tail, res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph(N);
	vector<int> checked(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &head, &tail);
		graph[head - 1].push_back(tail - 1);
		graph[tail - 1].push_back(head - 1);
	}
	for (int i = 0; i < N; i++) {
		if (checked[i]) continue;
		checked[i]++;
		res++;
		if (graph[i].empty()) continue;
		queue<int> q;
		for (int j = 0; j < graph[i].size(); j++) q.push(graph[i][j]);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			if (checked[now]) continue;
			checked[now]++;
			for (int j = 0; j < graph[now].size(); j++) q.push(graph[now][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}