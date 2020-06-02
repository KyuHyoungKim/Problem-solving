#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>
int dp[50001];
int sol(int N) {
	if (dp[N]) return dp[N];
	if (N <= 0) return 0;
	int ret = 5, temp;
	for (int i = (int)sqrt(N); i > 0; --i) {
		temp = sol(N - i * i) + 1;
		if (temp < ret) ret = temp;
	}
	dp[N] = ret;
	return ret;
}
int main() {
	int N, res;
	scanf("%d", &N);
	res = sol(N);
	printf("%d\n", res);
	return 0;
}