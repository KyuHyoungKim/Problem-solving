#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void sol(int N, int M, vector<int>& nums, int now, int cnt, vector<int> ret) {
	if (now == N) return;
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}

	ret.push_back(nums[now]);
	sol(N, M, nums, now, cnt + 1, ret);
	ret.pop_back();
	sol(N, M, nums, now + 1, cnt, ret);
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> nums(N);
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end());
	sol(N, M, nums, 0, 0, {});
	return 0;
}