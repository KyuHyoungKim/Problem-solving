#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	int N, K;
	long long start, end, mid, res = 123456789123456789;
	scanf("%d %d", &N, &K);
	start = 1;
	end = (long long)N * N;

	while (start <= end) {
		long long cnt = 0;
		mid = (start + end) / 2;
		for (int i = 1; i <= N; i++)
			cnt += (mid / i < N) ? mid / i : N;

		if (cnt >= K) {
			end = mid - 1;
			if (res > mid)
				res = mid;
		}
		else
			start = mid + 1;
	}

	printf("%d", res);
	return 0;
}