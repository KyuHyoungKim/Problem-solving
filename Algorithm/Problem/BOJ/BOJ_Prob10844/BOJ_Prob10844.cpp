#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int N, res = 0;
	scanf("%d", &N);
	vector<vector<int>> DP(N + 1, vector<int>(10));
	for (int i = 1; i <= 9; i++)
		DP[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		DP[i][0] = DP[i - 1][1];
		DP[i][9] = DP[i - 1][8];
		for (int j = 1; j <= 8; j++)
			DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
	}
	for (int i = 0; i <= 9; i++)
		res = (res + DP[N][i]) % 1000000000;
	printf("%d", res);
	return 0;
}