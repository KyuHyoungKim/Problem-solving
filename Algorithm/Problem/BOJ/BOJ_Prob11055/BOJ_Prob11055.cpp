#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<vector<int>> Increasing_subsequences(N);
	vector<int> sums(N);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);

	Increasing_subsequences[0].push_back(nums[0]);
	sums[0] = nums[0];
	res = sums[0];
	for (int i = 1; i < N; i++) {
		int a = 0;
		vector<int> ret;
		for (int j = 0; j < i; j++) {
			if (Increasing_subsequences[j].back() < nums[i] && sums[j] > a) {
				a = sums[j];
				ret = Increasing_subsequences[j];
			}
		}
		Increasing_subsequences[i].push_back(nums[i]);
		sums[i] = a + nums[i];
		if (sums[i] > res) res = sums[i];
	}
	printf("%d", res);

	return 0;
}