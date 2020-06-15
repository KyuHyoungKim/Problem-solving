#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, head, tail,cost;
	scanf("%d %d", &N, &M);
	vector<vector<int>> gr(N, vector<int>(N,100000000));
	while (M--) {
		scanf("%d %d %d", &head, &tail, &cost);
		if (!gr[head - 1][tail - 1] || gr[head - 1][tail - 1] > cost)
			gr[head - 1][tail - 1] = cost;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				if (gr[j][k] > gr[j][i] + gr[i][k] && k!=j)
					gr[j][k] = gr[j][i] + gr[i][k];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (gr[i][j] < 100000000)
				printf("%d ", gr[i][j]);
			else
				printf("0 ");
		printf("\n");
	}

	return 0;
}