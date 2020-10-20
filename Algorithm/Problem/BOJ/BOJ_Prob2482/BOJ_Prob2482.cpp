#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

const int mod = 1000000003;
int main() {
	int N, K; scanf("%d %d", &N, &K);
	vector<vector<int>> DP(N + 1, vector<int>(K + 1));
	
	for (int i = 0; i <= N; i++) {
		DP[i][0] = 1;
		DP[i][1] = i;
	}
	for (int i = 2; i <= N; i++)
		for (int j = 2; j <= K; j++)
			DP[i][j] = (DP[i - 2][j - 1] + DP[i - 1][j]) % mod;

	printf("%d", (DP[N - 1][K] + DP[N - 3][K - 1]) % mod);
	return 0;
}