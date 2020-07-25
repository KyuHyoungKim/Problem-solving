#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<int> nums;
int DP[2001][2000];
int check_palindrome(int st, int en) {
	if (st >= en) return 1;
	if (DP[st][en] >= 0) return DP[st][en];
	int ret = 0;
	if (nums[st] == nums[en] && check_palindrome(st + 1, en - 1) == 1)
		ret = 1;
	DP[st][en] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	memset(DP, -1, sizeof(DP));
	scanf("%d", &N);
	nums.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	scanf("%d", &M);
	while (M--) {
		int st, en;
		scanf("%d %d", &st, &en);
		printf("%d\n", check_palindrome(st - 1, en - 1));
	}
	return 0;
}