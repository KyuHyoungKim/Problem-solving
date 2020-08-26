#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int gca(int a, int b) {
	return b ? gca(b, a % b) : a;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, max_factor;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<int> res;
	for (int i = 0; i < N; i++) 
		scanf("%d", &nums[i]);

	sort(nums.begin(), nums.end());
	max_factor = nums[1] - nums[0];
	for (int i = 2; i < N; i++) 
		max_factor = gca(nums[i] - nums[i - 1], max_factor);
	for (int i = 1; i * i <= max_factor; i++) {
		if (max_factor % i) continue;
		res.push_back(i);
		res.push_back(max_factor / i);
	}
	sort(res.begin(), res.end());

	for (int i = 1; i < res.size(); i++) {
		if (res[i] == res[i - 1]) continue;

		printf("%d ", res[i]);
	}

	return 0;
}