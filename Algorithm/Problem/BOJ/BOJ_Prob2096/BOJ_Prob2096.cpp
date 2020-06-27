#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> scores(3);
	vector<vector<int>> res_max(2, vector<int>(3));
	vector<vector<int>> res_min(2, vector<int>(3));
	for (int j = 0; j < 3; j++) scanf("%d", &scores[j]);
	res_max[0] = res_min[0] = scores;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) scanf("%d", &scores[j]);
		res_max[1][0] = max(res_max[0][0], res_max[0][1]) + scores[0];
		res_max[1][1] = max({ res_max[0][0], res_max[0][1], res_max[0][2] }) + scores[1];
		res_max[1][2] = max(res_max[0][1], res_max[0][2]) + scores[2];
		res_max[0] = res_max[1];

		res_min[1][0] = min(res_min[0][0], res_min[0][1]) + scores[0];
		res_min[1][1] = min({ res_min[0][0], res_min[0][1], res_min[0][2] }) + scores[1];
		res_min[1][2] = min(res_min[0][1], res_min[0][2]) + scores[2];
		res_min[0] = res_min[1];
	}
	printf("%d\n", max({ res_max[0][0], res_max[0][1], res_max[0][2] }));
	printf("%d\n", min({ res_min[0][0], res_min[0][1], res_min[0][2] }));
	return 0;
}