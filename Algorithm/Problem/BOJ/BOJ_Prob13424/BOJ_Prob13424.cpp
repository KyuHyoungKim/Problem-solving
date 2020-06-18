#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, M, K;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		vector<vector<int>> gra(N,vector<int>(N, 123456789));
		for (int i = 0; i < M; i++)
		{
			int head, tail, cost;
			scanf("%d %d %d", &head, &tail, &cost);
			gra[head - 1][tail - 1] = cost;
			gra[tail - 1][head - 1] = cost;
		}
		for (int i = 0; i < N; i++)
			gra[i][i] = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
					if (gra[j][k] > gra[j][i] + gra[i][k])
						gra[j][k] = gra[j][i] + gra[i][k];
		
		scanf("%d", &K);
		vector<int> people(K);
		for (int i = 0; i < K; i++)
			scanf("%d", &people[i]);

		int dist = 123456789, res = -1;
		for (int i = 0; i < N; i++)
		{
			int a = 0;
			for (int j = 0; j < K; j++)
				a += gra[people[j] - 1][i];
			if (dist > a) {
				dist = a;
				res = i;
			}
		}

		printf("%d\n", res + 1);
	}
	return 0;
}