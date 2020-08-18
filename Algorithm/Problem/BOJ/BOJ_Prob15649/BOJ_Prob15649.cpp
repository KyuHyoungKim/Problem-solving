#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, M;

void sol(int checked, int count, vector<int> nums) {
	if (count == M) {
		for (int i = 0; i < nums.size(); i++)
			printf("%d ", nums[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (checked & 1 << i) continue;
		nums.push_back(i);
		sol(checked | 1 << i,count+1, nums);
		nums.pop_back();
	}
}
int main() {
	scanf("%d %d", &N, &M);
	sol(0, 0, {});
	return 0;
}