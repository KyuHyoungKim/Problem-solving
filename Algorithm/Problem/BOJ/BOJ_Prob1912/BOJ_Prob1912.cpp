#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, res;
	scanf("%d", &N);
	vector<int>DP(N), nums(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	res = DP[0] = nums[0];
	for (int i = 1; i < N; i++) {
		DP[i] = max(nums[i], DP[i - 1] + nums[i]);
		res = max(res, DP[i]);
	}
	printf("%d", res);
	return 0;
}