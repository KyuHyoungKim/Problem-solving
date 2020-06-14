#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(vector<int>& a, vector<int>& b) {
	return a < b;
}
void sol(vector<int>& nums, vector<vector<int>>* res, vector<int> ret, int N, int M, int now, int check) {
	if (ret.size() == M) {
		res->push_back(ret);
		return;
	}
	if (now == N) return;

	for (int i = 0; i < N; i++)
	{
		if (!(check & 1 << i)) {
			ret.push_back(nums[i]);
			sol(nums, res, ret, N, M, now, check | 1 << i);
			ret.pop_back();
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> nums(N);
	vector<vector<int>> res;
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	sol(nums, &res, {}, N, M, 0, 0);
	sort(res.begin(), res.end(), comp);
	for (int i = 0; i < res.size() - 1; i++) {
		if (res[i] != res[i + 1]) {
			for (int j = 0; j < res[i].size(); j++)
				printf("%d ", res[i][j]);
			printf("\n");
		}
	}
	for (int i = 0; i < res[res.size() - 1].size(); i++)
		printf("%d ", res[res.size() - 1][i]);
	return 0;
}