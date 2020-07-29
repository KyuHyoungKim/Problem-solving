#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> find_prime_nums(int n) {
	vector<int> nums(n + 1);
	vector<int> ret;
	for (int i = 2; i <= n; i++)
		nums[i] = i;

	for (int i = 2; i <= n; i++) {
		if (!nums[i]) continue;
		ret.push_back(i);
		for (int j = 2; i * j <= n; j++) {
			nums[i * j] = 0;

		}
	}
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int T, max_num = 0;
	scanf("%d", &T);
	vector<int> nums;
	for (int i = 0; i < T; i++) {
		int temp;
		scanf("%d", &temp);
		nums.push_back(temp);
		max_num = max(max_num, temp);
	}
	vector<int> prime_nums = find_prime_nums(max_num);
	for (int i = 0; i < T; i++) {
		int res[2] = { 0 };
		int left = 0;
		int right = lower_bound(prime_nums.begin(), prime_nums.end(), nums[i]) - prime_nums.begin() - 1;
		while (left <= right) {
			int sum = prime_nums[left] + prime_nums[right];
			if (sum > nums[i]) right--;
			else if (sum < nums[i]) left++;
			else {
				res[0] = prime_nums[left];
				res[1] = prime_nums[right];
				left++;
				right--;
			}
		}
		printf("%d %d\n", res[0], res[1]);
	}
	return 0;
}