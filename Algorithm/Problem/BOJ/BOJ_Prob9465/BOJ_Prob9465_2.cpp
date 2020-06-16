#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		vector<vector<int>> stks(2, vector<int>(N + 1));
		vector<vector<int>> res(2, vector<int>(N + 1));
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &stks[i][j]);
		res[0][1] = stks[0][1];
		res[1][1] = stks[1][1];
		for (int i = 2; i <= N; i++) {
			res[0][i] = max(res[1][i - 1], res[1][i - 2]) + stks[0][i];
			res[1][i] = max(res[0][i - 1], res[0][i - 2]) + stks[1][i];
		}
		printf("%d\n", max(res[0][N], res[1][N]));
	}
	return 0;
}