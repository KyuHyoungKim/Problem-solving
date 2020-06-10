#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <cstdio>

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	int graph[100][100] = { 0 };
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &graph[i][j]);
			if (graph[i][j] == 0) graph[i][j] = INF;
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (graph[i][j] == INF)
				graph[i][j] = 0;
			else graph[i][j] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", graph[i][j]);
		printf("\n");
	}
	return 0;
}