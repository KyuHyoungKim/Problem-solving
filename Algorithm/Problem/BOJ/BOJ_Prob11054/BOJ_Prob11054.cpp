#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<vector<int>> DP(2);
int N;
int Solution(vector<int>& series, int pos, int condition) {
	if (DP[condition][pos]) return DP[condition][pos];
	if (pos == N - 1) return 1;

	int a1, a2, ret = 0;
	for (int i = pos + 1; i < N; i++) {
		if (series[i] > series[pos] && condition) {
			a1 = Solution(series, i, 1);
			if (a1 > ret) ret = a1;
		}
		else if (series[i] < series[pos]) {
			a2 = Solution(series, i, 0);
			if (a2 > ret) ret = a2;
		}
	}
	ret++;
	if (DP[condition][pos] < ret) DP[condition][pos] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d", &N);
	vector<int> series(N);
	DP[0].resize(N);
	DP[1].resize(N);
	for (int i = 0; i < N; i++) scanf("%d", &series[i]);
	for (int i = 0; i < N; i++)
	{
		int a = Solution(series, i, 1);
		if (res < a) res = a;
	}
	printf("%d", res);
	return 0;
}
