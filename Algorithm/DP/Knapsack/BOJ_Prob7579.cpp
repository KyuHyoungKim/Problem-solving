#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, M;
vector<pair<int, int>> apps;
vector<vector<int>> DP(100, vector<int>(10001, -1));
int knapsack(int index, int cost) {
	if (index >= N) return 0;
	if (DP[index][cost] >= 0) return DP[index][cost];
	int ret = -1;
	if (apps[index].second <= cost)
		ret = knapsack(index + 1, cost - apps[index].second) + apps[index].first;
	int a = knapsack(index + 1, cost);
	if (ret < a) ret = a;
	DP[index][cost] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	int res = 0;
	apps.resize(N);
	for (int i = 0; i < N; i++) scanf("%d", &apps[i].first);
	for (int i = 0; i < N; i++) scanf("%d", &apps[i].second);
	for (int i = 0; i <= 10000; i++) {
		int a = knapsack(0, i);
		if (a >= M) {
			res = i;
			break;
		}
	}
	printf("%d", res);
	return 0;
}