#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	const int mod[2] = { 5,2 };
	int N, M, K;
	int res[2] = { 0,0 };
	scanf("%d %d", &N, &M);
	K = N - M;
	for (int n = 0; n < 2; n++) {
		for (long long i = mod[n]; i <= N; i *= mod[n]) {
			res[n] += N / i;
			if (i <= M)
				res[n] -= M / i;
			if (i <= K)
				res[n] -= K / i;
		}
	}
	if (res[0] > res[1])
		res[0] = res[1];
	printf("%d", res[0]);
	return 0;
}