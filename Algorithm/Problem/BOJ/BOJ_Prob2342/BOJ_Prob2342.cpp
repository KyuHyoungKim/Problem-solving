#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int cost[5][5] = {
	{0,2,2,2,2},
	{2,1,3,4,3},
	{2,3,1,3,4},
	{2,4,3,1,3},
	{2,3,4,3,1},
};

void init(int& N, vector<int>& nums, vector<vector<vector<int>>>& DP);

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 1234567891;
	vector<int> nums;
	vector<vector<vector<int>>> DP;
	init(N, nums, DP);

	DP[0][0][nums[0]] = 2;
	DP[0][nums[0]][0] = 2;

	for (int i = 1; i < N; i++) {
		int num = nums[i];
		for (int a = 0; a < 5; a++)
			for (int b = 0; b < 5; b++) {
				if (DP[i - 1][a][b] == INF)
					continue;
				DP[i][a][num] = min(DP[i][a][num], DP[i - 1][a][b] + cost[b][num]);
				DP[i][num][b] = min(DP[i][num][b], DP[i - 1][a][b] + cost[a][num]);
			}
	}

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			res = min(res, DP[N - 1][i][j]);

	printf("%d", res);
	return 0;
}

void init(int& N, vector<int>& nums, vector<vector<vector<int>>>& DP) {
	int num = 1;
	while (num) {
		scanf("%d", &num);
		nums.push_back(num);
	}
	nums.pop_back();
	N = nums.size();
	vector<vector<vector<int>>> DP_init(N, vector<vector<int>>(5, vector<int>(5, INF)));
	DP.swap(DP_init);
}
