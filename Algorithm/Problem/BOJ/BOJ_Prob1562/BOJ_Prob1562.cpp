#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
const int MAX = 1 << 10, mod = 1000000000;
int DP[100][10][MAX] = { 0 };

int main() {
	int N, res = 0;
	scanf("%d", &N);

	for (int i = 1; i <= 9; i++)
		DP[0][i][1 << i] = 1;

	for (int i = 1; i < N; i++)
		for (int j = 0; j <= 9; j++)
			for (int k = 0; k < MAX; k++) {
				if (j == 0)
					DP[i][0][k | 1 << 0] = (DP[i][0][k | 1 << 0] + DP[i - 1][1][k]) % mod;
				else if (j == 9)
					DP[i][9][k | 1 << 9] = (DP[i][9][k | 1 << 9] + DP[i - 1][8][k]) % mod;
				else
					DP[i][j][k | 1 << j] = ((DP[i][j][k | 1 << j] + DP[i - 1][j - 1][k]) % mod + DP[i - 1][j + 1][k]) % mod;
			}

	for (int i = 0; i <= 9; i++)
		res = (res + DP[N - 1][i][MAX - 1]) % mod;
	printf("%d", res);
	return 0;
}