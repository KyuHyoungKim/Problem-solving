#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0;
	int left, right, mid, max = 0;
	long long sum = 0;
	scanf("%d", &N);
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
		sum += nums[i];
		if (nums[i] > max)
			max = nums[i];
	}
	scanf("%d", &M);
	if (sum <= M) {
		printf("%d", max);
		return 0;
	}

	left = 1;
	right = M;
	while (left <= right) {
		sum = 0;
		mid = (right + left) / 2;

		for (int i = 0; i < N; i++) {
			if (mid > nums[i])
				sum += nums[i];
			else
				sum += mid;
		}

		if (sum > M) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			res = mid;
		}
	}

	printf("%d", res);
	return 0;
}