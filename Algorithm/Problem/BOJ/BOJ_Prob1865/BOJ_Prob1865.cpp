#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M, W;
		scanf("%d %d %d", &N, &M, &W);
		vector<vector<int>> gra(N, vector<int>(N, 123456789));

		while (M--)
		{
			int node1, node2, weight;
			scanf("%d %d %d", &node1, &node2, &weight);
			if (gra[node1 - 1][node2 - 1] < weight) continue;
			gra[node1 - 1][node2 - 1] = weight;
			gra[node2 - 1][node1 - 1] = weight;
		}
		while (W--)
		{
			int node1, node2, weight;
			scanf("%d %d %d", &node1, &node2, &weight);
			gra[node1 - 1][node2 - 1] = -weight;
		}

		for (int i = 0; i < N; i++)
			if (gra[i][i] == 123456789)
				gra[i][i] = 0;

		for (int n = 0; n < 2; n++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					for (int k = 0; k < N; k++)
						if (gra[j][k] > gra[j][i] + gra[i][k])
							gra[j][k] = gra[j][i] + gra[i][k];

		bool cycle_check = false;
		for (int i = 0; i < N; i++)
			if (gra[i][i] < 0) {
				printf("YES\n");
				cycle_check = true;
				break;
			}
		if (!cycle_check) printf("NO\n");

	}
	return 0;
}