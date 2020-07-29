#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
int DP[1500001];
int main() {
	freopen("input.txt", "r", stdin);
	int T, N, M;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		long long res = 0;
		long long case1 = 16, case2 = 625;
		for (int cnt = 4; case1 <= M; cnt += 2, case1 *= 4)
			if ((int)case1 == M) {
				res = 3 * ((long long)1 << (cnt - 1));
				if (res > (long long)M * M - 1) res = 0;
				break;
			}
		if (!res)
			for (int cnt = 4; case2 <= M; case2 *= 25, cnt += 2)
				if ((int)case2 == M) {
					res = 4 * case2;
					if (res > (long long)M * M - 1) res = 0;
					break;
				}
				else if ((int)case2 * 2 == M) {
					res = 6 * (long long)cnt;
					if (res > (long long)M * M - 1) res = 0;
					break;
				}
		if (!res)
			for (int M_temp = M, cnt = 0; M_temp > 0; M_temp /= 10) {
				if (M_temp % 10) break;
				if (M_temp == 1) res = 15 * (long long)pow(10, cnt - 1);
			}
		if (!res) {
			memset(DP, 0, sizeof(DP));
			DP[1] = 1;
			DP[2] = 1;
			for (int i = 3; i < 1500001; i++) {
				DP[i] = (DP[i - 2] + DP[i - 1]) % M;
				if (DP[i] == 1 && DP[i - 1] == 0) {
					res = (long long)i - 1;
					break;
				}
			}
		}
		printf("%d %d\n", N, res);
	}
	return 0;
}