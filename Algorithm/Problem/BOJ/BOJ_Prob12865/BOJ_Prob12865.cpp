#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, res = 0;
vector<vector<int>> dp(300000, vector<int>(100001, -1));	// weight, value
int sol(int pos, int cap, vector<pair<int, int>>& stuffs) {
	if (pos >= N) return 0;
	if (dp[pos][cap] >= 0) return dp[pos][cap];
	int a1 = -1, a2 = -1;
	a1 = sol(pos + 1, cap, stuffs);
	if (stuffs[pos].first <= cap)
		a2 = sol(pos + 1, cap - stuffs[pos].first, stuffs) + stuffs[pos].second;
	int ret = (a1 > a2) ? a1 : a2;
	dp[pos][cap] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &K);
	vector<pair<int, int>> stuffs(N);	// first : weight, second : value
	for (int i = 0; i < N; i++)
		scanf("%d %d", &stuffs[i].first, &stuffs[i].second);
	res = sol(0, K, stuffs);
	printf("%d\n", res);
	return 0;
}