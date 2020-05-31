#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int num[3] = { 1,2,3 };
int find_case(int N, int now) {
	int res = 0;
	if (now > N) return 0;
	if (now == N) return 1;
	for (int i = 0; i < 3; i++) {
		res += find_case(N, now + num[i]);
	}
	return res;
}

int main() {
	int T, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%d\n", find_case(N, 0));
	}
	return 0;
}