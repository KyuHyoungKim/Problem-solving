#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<vector<int>> DP(N);
	vector<int> res;
	for (int i = 0; i < N; i++) 
		scanf("%d", &nums[i]);

	DP[0].push_back(nums[0]);
	res = DP[0];
	for (int i = 1; i < N; i++) {
		vector<int> ret;
		for (int j = 0; j < i; j++) {
			if (DP[j].size() > ret.size() && DP[j].back() < nums[i])
				ret = DP[j];
		}
		ret.push_back(nums[i]);
		DP[i] = ret;
		if (ret.size() > res.size()) res = ret;
	}
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d ", res[i]);
	return 0;
}