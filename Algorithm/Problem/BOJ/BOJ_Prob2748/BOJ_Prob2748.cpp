#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

long long DP[91] = { 0, 1, 1 };
long long fibonacci(int n) {
	if (DP[n]) return DP[n];
	if (n == 0) return 0;
	long long ret = fibonacci(n - 1) + fibonacci(n - 2);
	DP[n] = ret;
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%lld", fibonacci(n));
	return 0;
}