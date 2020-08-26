#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> DP;
int Pascal(int N, int K) {
	if (DP[N][K]) return DP[N][K];

	if (K == 0 || K == N) return DP[N][K] = DP[N][0] = 1;

	return DP[N][K] = DP[N][N - K] = (Pascal(N - 1, K - 1) + Pascal(N - 1, K)) % 10007;
}
int main() {
	int N, K, res;
	scanf("%d %d", &N, &K);
	vector<vector<int>> DP_init(N + 1, vector<int>(N + 1));
	DP.swap(DP_init);

	res = Pascal(N, K);

	printf("%d", res);
	return 0;
}