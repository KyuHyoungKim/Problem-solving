#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, T;
vector<pair<int, int>> study;
vector<vector<int>> DP;

int knapsack(int idx, int time) {
	if (idx >= N) return 0;
	if (DP[idx][time]) return DP[idx][time];
	int a1 = 0, a2 = 0, ret = 0;
	if (time >= study[idx].first)
		a1 = knapsack(idx + 1, time - study[idx].first) + study[idx].second;
	a2 = knapsack(idx + 1, time);
	ret = (a1 > a2) ? a1 : a2;
	DP[idx][time] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &T);
	study.resize(N);
	vector<vector<int>> DP_swap(N, vector<int>(T + 1));
	DP.swap(DP_swap);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &study[i].first, &study[i].second);
	printf("%d", knapsack(0, T));
	return 0;
}