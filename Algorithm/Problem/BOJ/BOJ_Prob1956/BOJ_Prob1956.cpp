#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int V, E, res = INF;
	scanf("%d %d", &V, &E);
	vector<vector<int>> M(V, vector<int>(V, INF));
	for (int i = 0; i < E; i++) {
		int head, tail, dist;
		scanf("%d %d %d", &head, &tail, &dist);
		head--; tail--;
		M[head][tail] = dist;
	}

	for (int i = 0; i < V; i++) // 중간
		for (int j = 0; j < V; j++) // 끝
			for (int k = 0; k < V; k++) // 시작
				if (M[k][j] > M[k][i] + M[i][j])
					M[k][j] = M[k][i] + M[i][j];

	for (int i = 0; i < V; i++)
		if (res > M[i][i])
			res = M[i][i];
	if (res == INF)
		res = -1;
	printf("%d", res);
	return 0;
}