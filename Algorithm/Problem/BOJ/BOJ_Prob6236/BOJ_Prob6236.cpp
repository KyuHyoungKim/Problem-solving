#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0;
	int left = 0, right = 0;
	scanf("%d %d", &N, &M);
	vector<int> nums(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
		right += nums[i];
		if (left < nums[i])
			left = nums[i];
	}
	while (left <= right) {
		int mid = (left + right) / 2;
		int money = mid;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (money >= nums[i])
				money -= nums[i];
			else {
				money = mid - nums[i];
				cnt++;
			}
		}

		if (cnt <= M) {
			right = mid - 1;
			res = mid;
		}
		else 
			left = mid + 1;
	}

	printf("%d", res);
	return 0;
}