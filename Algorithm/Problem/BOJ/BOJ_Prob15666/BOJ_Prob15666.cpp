#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(vector<int>& a, vector<int>&b) {
	return a < b;
}
void sol(vector<int>& nums, vector<vector<int>>* res, vector<int> ret,int now, int N, int M) {
	if (ret.size() == M) {
		res->push_back(ret);
		return;
	}
	if (now == N) return;

	sol(nums, res, ret, now + 1, N, M);
	ret.push_back(nums[now]);
	sol(nums, res, ret, now, N, M);
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> nums(N);
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end());
	sol(nums, &res, {}, 0, N, M);
	sort(res.begin(), res.end(),comp);
	for (int i = 0; i < res.size() - 1; i++) {
		if (res[i] != res[i + 1]) {
			for (int j = 0; j < M; j++)
				printf("%d ", res[i][j]);
			printf("\n");
		}
	}
	for (int i = 0; i < res[res.size() - 1].size(); i++)
		printf("%d ", res[res.size() - 1][i]);
	return 0;
}