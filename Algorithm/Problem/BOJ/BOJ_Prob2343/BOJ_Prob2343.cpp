#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res;
	int left = 0, right = 0, mid;
	scanf("%d %d", &N, &M);
	vector<int> nums(N + 1);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
		right += nums[i];
		if (left < nums[i])
			left = nums[i];
	}

	while (left <= right) {
		int blueray_cnt = 1;
		int sum = 0;

		mid = (left + right) / 2;

		for (int i = 1; i <= N; i++) {
			sum += nums[i];
			if (sum > mid) {
				sum = nums[i];
				blueray_cnt++;
			}
		}

		if (blueray_cnt > M)
			left = mid + 1;
		else {
			right = mid - 1;
			res = mid;
		}
	}

	printf("%d", res);
	return 0;
}