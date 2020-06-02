#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N;
int dp[301][3];
int sol(vector<int>stairs, int now, int cnt) {
	int ret = 0, a1 = 0, a2 = 0;
	if (dp[now][cnt]) return dp[now][cnt];
	if (now + 1 <= N && cnt < 2)
		a1 = sol(stairs, now + 1, cnt + 1);
	if (now + 2 <= N)
		a2 = sol(stairs, now + 2, 1);
	ret = (a1 >= a2) ? a1 : a2;
	if (ret == 0 && now != N) return 0;
	ret += stairs[now];
	dp[now][cnt] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d", &N);
	vector<int> stairs(N+1);
	for (int i = 1; i <= N; i++) scanf("%d", &stairs[i]);
	res = sol(stairs, 0, 0);
	printf("%d\n", res);
	return 0;
}