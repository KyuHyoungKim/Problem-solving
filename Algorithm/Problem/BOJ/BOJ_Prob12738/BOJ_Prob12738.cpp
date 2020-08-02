#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> nums(N);
	vector<int> lis;
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	
	lis.push_back(nums[0]);
	for (int i = 1; i < N; i++) {
		if (lis.back() < nums[i])
			lis.push_back(nums[i]);
		else {
			int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
			lis[idx] = nums[i];
		}
	}
	printf("%d", lis.size());
	return 0;
}