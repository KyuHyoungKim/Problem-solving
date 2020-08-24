#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, res;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<vector<int>> DP(3, vector<int>(N));
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	DP[1][0] = nums[0];

	for (int i = 1; i < N; i++) {
		DP[0][i] = max({ DP[0][i - 1], DP[1][i - 1], DP[2][i - 1] });
		DP[1][i] = DP[0][i - 1] + nums[i];
		DP[2][i] = DP[1][i - 1] + nums[i];
	}
	res = max({ DP[0][N - 1], DP[1][N - 1], DP[2][N - 1] });
	printf("%d", res);
	return 0;
}