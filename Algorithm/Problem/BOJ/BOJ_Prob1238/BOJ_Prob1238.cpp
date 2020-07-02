#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, X, res = 0;
	scanf("%d %d %d", &N, &M, &X);
	vector<vector<int>> graph(N, vector<int>(N,123456789));
	for (int i = 0; i < N; i++) graph[i][i] = 0;
	for (int i = 0; i < M; i++) {
		int st, en, we;
		scanf("%d %d %d", &st, &en, &we);
		graph[st - 1][en - 1] = we;
	}
	for (int mid = 0; mid < N; mid++)
		for (int st = 0; st < N; st++)
			for (int en = 0; en < N; en++)
				if (graph[st][en] > graph[st][mid] + graph[mid][en])
					graph[st][en] = graph[st][mid] + graph[mid][en];

	for (int i = 0; i < N; i++) {
		int dist = graph[i][X - 1] + graph[X - 1][i];
		if (dist > res) res = dist;
	}
	
	printf("%d", res);
	return 0;
}