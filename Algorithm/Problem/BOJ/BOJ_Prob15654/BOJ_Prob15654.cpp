#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;

void sol(vector<int> nums, int pos, int cnt, vector<int> arr, int check) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	if (pos == N) return;
	for (int i = 0; i < N; i++) {
		if (!(check & 1 << i)) {
			arr.push_back(nums[i]);
			sol(nums, pos + 1, cnt + 1, arr, check | 1 << i);
			arr.pop_back();
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	vector<int> nums(N);
	vector<int> arr;
	for (int i = 0; i < N; i++) scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end());
	sol(nums, 0, 0, arr, 0);
	return 0;
}