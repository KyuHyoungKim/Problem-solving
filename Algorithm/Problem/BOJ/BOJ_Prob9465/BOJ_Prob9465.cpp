#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		vector<vector<int>> stks(2, vector<int>(N));
		vector<vector<int>> res(3, vector<int>(N));

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &stks[i][j]);
		res[0][0] = stks[0][0];
		res[1][0] = stks[1][0];
		res[2][0] = 0;

		for (int i = 1; i < N; i++) {
			res[0][i] = (res[1][i - 1] + stks[0][i] > res[2][i - 1] + stks[0][i]) ? res[1][i - 1] + stks[0][i] : res[2][i - 1] + stks[0][i];
			res[1][i] = (res[0][i - 1] + stks[1][i] > res[2][i - 1] + stks[1][i]) ? res[0][i - 1] + stks[1][i] : res[2][i - 1] + stks[1][i];
			res[2][i] = (res[0][i - 1] > res[1][i - 1]) ? res[0][i - 1] : res[1][i - 1];
		}
		if (res[0][N - 1] > res[1][N - 1]) printf("%d\n", res[0][N - 1]);
		else printf("%d\n", res[1][N - 1]);
	}
	return 0;
}