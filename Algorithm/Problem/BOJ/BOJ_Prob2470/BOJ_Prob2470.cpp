#define INF 2000000001
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, L, R, mid;
	int res[2] = {0};
	int ans = INF;
	scanf("%d", &N);
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end());
	for (int i = 0; i < N && ans > 0; i++) {
		L = 0, R = N - 1;
		while (L <= R) {
			mid = (L + R) / 2;
			int sum = nums[i] + nums[mid];
			if (sum > 0)
				R = mid - 1;
			else if(sum < 0)
				L = mid + 1;
			else {
				res[0] = nums[i];
				res[1] = nums[mid];
				ans = 0;
				break;
			}
			if (mid == i) continue;
			if (abs(sum) < ans) {
				res[0] = nums[i];
				res[1] = nums[mid];
				ans = abs(sum);
			}
		}
	}

	if (res[0] > res[1]) 
		swap(res[0], res[1]);

	printf("%d %d\n", res[0], res[1]);
	return 0;
}