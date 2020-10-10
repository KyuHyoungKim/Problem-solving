#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
using namespace std;

vector<int> page_sum;
vector<vector<int>> DP;

int sol(int start, int end) {
	if (start == end)
		return 0;
	if (DP[start][end])
		return DP[start][end];
	
	int ret = INF, a;
	
	for (int i = start; i < end; i++) {
		a = sol(start, i) + sol(i + 1, end);
		a += page_sum[i] - page_sum[start - 1];
		a += page_sum[end] - page_sum[i];
		if (ret > a)
			ret = a;
	}
	DP[start][end] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		page_sum = vector<int>(N + 1, 0);
		DP = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
		for (int i = 1; i <= N; i++) {
			int page;
			scanf("%d", &page);
			page_sum[i] = page_sum[i - 1] + page;
		}
		printf("%d\n", sol(1, N));
	}
	return 0;
}