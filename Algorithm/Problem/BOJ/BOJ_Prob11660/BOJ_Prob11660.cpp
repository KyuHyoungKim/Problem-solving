#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> nums(N, vector<int>(N));
	vector<vector<int>> sum(N, vector<int>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &nums[i][j]);
	}
	sum[0][0] = nums[0][0];
	for (int i = 1; i < N; i++)
	{
		sum[0][i] = sum[0][i - 1] + nums[0][i];
		sum[i][0] = sum[i - 1][0] + nums[i][0];
	}
	for (int i = 1; i < N; i++)
		for (int j = 1; j < N; j++)
			sum[i][j] = nums[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];

	while (M--) {
		int y1, x1, y2, x2, res = 0;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		res = sum[y2 - 1][x2 - 1];
		if (y1 > 1) res -= sum[y1 - 2][x2 - 1];
		if (x1 > 1) res -= sum[y2 - 1][x1 - 2];
		if (y1 > 1 && x1 > 1) res += sum[y1 - 2][x1 - 2];
		printf("%d\n", res);
	}
	return 0;
}