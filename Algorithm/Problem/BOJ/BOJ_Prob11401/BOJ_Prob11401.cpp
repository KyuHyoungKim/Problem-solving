#define _CRT_SECURE_NO_WARNINGS
#define mod 1000000007
#include <cstdio>
using namespace std;

int main() {
	long long N_fac = 1, M_K_fac = 1, pow_of_MKfac = 1;
	int N, M, K, res;
	scanf("%d %d", &N, &M);
	K = N - M;

	if (K > M) {
		int temp = K;
		K = M;
		M = temp;
	}

	for (int i = 2; i <= N; i++) {
		N_fac = (N_fac * i) % mod;
		if (i <= M)
			M_K_fac = (M_K_fac * i) % mod;
		if (i <= K)
			M_K_fac = (M_K_fac * i) % mod;
	}

	for (int i = 1, cnt = 0; i <= mod - 2; i *= 2, cnt++) {
		if ((mod - 2) & 1 << cnt)
			pow_of_MKfac = (pow_of_MKfac * M_K_fac) % mod;

		M_K_fac = (M_K_fac * M_K_fac) % mod;
	}

	res = (N_fac * pow_of_MKfac) % mod;
	printf("%d", res);

	return 0;
}