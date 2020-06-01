#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, head, tail, res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph(N);
	vector<int> check(N,0);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &head, &tail);
		graph[head - 1].push_back(tail - 1);
		graph[tail - 1].push_back(head - 1);
	}
	queue<int> q;
	for (int i = 0; i < graph[0].size(); i++)
		q.push(graph[0][i]);
	check[0] = 1;
	while (!q.empty()) {
		int next = q.front();
		q.pop();
		if (!check[next]) {
			for (int i = 0; i < graph[next].size(); i++)
				q.push(graph[next][i]);
			check[next] = 1;
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}