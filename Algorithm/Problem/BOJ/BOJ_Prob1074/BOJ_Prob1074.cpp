#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
	int N = 0, r = 0, c = 0, res = 0;
	scanf("%d %d %d", &N, &r, &c);
	while (N > 0) {
		--N;
		if (r >= 1 << N) {
			res += (1 << N) * (1 << N) * 2;
			r -= (1 << N);
		}
		if (c >= 1 << N) {
			res += (1 << N) * (1 << N);
			c -= (1 << N);
		}
	}
	printf("%d\n", res);
	return 0;
}