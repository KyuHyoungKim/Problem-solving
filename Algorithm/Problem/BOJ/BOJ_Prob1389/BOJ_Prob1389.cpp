#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, node1, node2, min = 123456789, res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> dist(N + 1, vector<int>(N + 1, 123456789));
	vector<int> KB_Num(N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &node1, &node2);
		dist[node1][node2] = 1;
		dist[node2][node1] = 1;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++)
			{
				if (dist[j][k] > dist[j][i] + dist[i][k])
					dist[j][k] = dist[j][i] + dist[i][k];
			}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
			KB_Num[i - 1] += dist[i][j];
		if (min > KB_Num[i - 1]) {
			min = KB_Num[i - 1];
			res = i;
		}
	}
	printf("%d\n", res);
	return 0;
}