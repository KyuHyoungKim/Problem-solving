#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0;
	int nums[51];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &nums[i]);

	for (int i = 0; i < M; i++) {
		int cnt;
		if (nums[i] <= N - nums[i] + 1) {
			cnt = nums[i] - 1;
			for (int j = i; j < M; j++) {
				nums[j] -= (cnt + 1);
				if (nums[j] < 1)
					nums[j] += N;
			}
		}
		else {
			cnt = N - nums[i] + 1;
			for (int j = i; j < M; j++) {
				nums[j] += cnt - 1;
				if (nums[j] > N)
					nums[j] -= N;
			}
		}
		res += cnt;
		N--;
	}

	printf("%d", res);
	return 0;
}