#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
long long dp[101] = { 0, 1, 1, 1, 2, 2 };
long long sol(int N) {
	if (dp[N]) return dp[N];
	long long ret = sol(N - 5) + sol(N - 1);
	dp[N] = ret;
	return ret;
}
int main() {
	int T, N;
	long long res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		res = sol(N);
		printf("%lld\n", res);
	}
	return 0;
}