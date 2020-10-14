#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <stdio.h>

int main() {
	int V, E, res = INF;
	int Map[400][400];
	scanf("%d %d", &V, &E);
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			Map[i][j] = INF;

	for (int i = 0; i < E; i++) {
		int n1, n2, di;
		scanf("%d %d %d", &n1, &n2, &di);
		Map[n1 - 1][n2 - 1] = di;
	}

	for (int i = 0; i < V; i++) // 중간
		for (int j = 0; j < V; j++) // 시작
			for (int k = 0; k < V; k++) // 끝
				if (Map[j][k] > Map[j][i] + Map[i][k])
					Map[j][k] = Map[j][i] + Map[i][k];

	for (int i = 0; i < V; i++)
		if (res > Map[i][i])
			res = Map[i][i];
	if (res == INF)
		res = -1;
	printf("%d", res);
	return 0;
}