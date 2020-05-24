#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
	int n, i = 3, dp[1001] = { 0,1,2 };
	scanf("%d", &n);
	for (; i <= n; i++)dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	printf("%d\n", dp[n]);
	return 0;
}