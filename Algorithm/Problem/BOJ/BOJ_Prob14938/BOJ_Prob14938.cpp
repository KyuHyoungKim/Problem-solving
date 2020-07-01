#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, R, res = 0;
	scanf("%d %d %d", &N, &M, &R);
	vector<vector<int>> graph(N, vector<int>(N,123456789));
	vector<int> items(N);
	vector<int> farming(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &items[i]);
		graph[i][i] = 0;
	}
	while (R--) {
		int node1, node2, dist;
		scanf("%d %d %d", &node1, &node2, &dist);
		graph[node1 - 1][node2 - 1] = dist;
		graph[node2 - 1][node1 - 1] = dist;
	}

	for (int mid = 0; mid < N; mid++)
		for (int st = 0; st < N; st++)
			for (int en = 0; en < N; en++)
				if (graph[st][en] > graph[st][mid] + graph[mid][en])
					graph[st][en] = graph[st][mid] + graph[mid][en];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) 
			if (graph[i][j] <= M)
				farming[i] += items[j];

		if (res < farming[i]) res = farming[i];
		}

	printf("%d", res);
	return 0;
}