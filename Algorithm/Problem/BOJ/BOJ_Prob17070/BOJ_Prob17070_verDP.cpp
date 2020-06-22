#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<vector<int>> space(N, vector<int>(N));
	vector<vector<vector<int>>> DP(3, vector<vector<int>>(N, vector<int>(N)));
	// 0 : horizontal 
	// 1 : digonal
	// 2 : vertical
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &space[i][j]);

	for (int i = 1; i < DP[0][0].size(); i++) {
		if (space[0][i]) break;
		DP[0][0][i] = 1;
	}

	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
		{
			if (space[i][j]) continue;
			DP[0][i][j] = DP[0][i][j - 1] + DP[1][i][j - 1];
			if (!space[i - 1][j] && !space[i][j - 1])
				DP[1][i][j] = DP[0][i - 1][j - 1] + DP[1][i - 1][j - 1] + DP[2][i - 1][j - 1];
			DP[2][i][j] = DP[2][i - 1][j] + DP[1][i - 1][j];
		}
	printf("%d\n", DP[0][N - 1][N - 1] + DP[1][N - 1][N - 1] + DP[2][N - 1][N - 1]);
	return 0;
}