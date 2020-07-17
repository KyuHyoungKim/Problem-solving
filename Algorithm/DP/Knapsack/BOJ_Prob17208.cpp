#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int N, M, K;
vector<pair<int, int>> stocks;
vector<vector<vector<int>>> DP;

int knapsack(int index, int burger, int fry) {
	if (index >= N) return 0;
	if (DP[index][burger][fry]) return DP[index][burger][fry];
	int a1 = 0, a2 = 0, ret = 0;
	if (burger >= stocks[index].first && fry >= stocks[index].second)
		a1 = knapsack(index + 1, burger - stocks[index].first, fry - stocks[index].second) + 1;
	a2 = knapsack(index + 1, burger, fry);
	ret = (a1 > a2) ? a1 : a2;
	DP[index][burger][fry] = ret;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &K);
	stocks.resize(N);
	vector<vector<vector<int>>> DP_resizer(N, vector<vector<int>>(M + 1, vector<int>(K + 1)));
	DP.swap(DP_resizer);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &stocks[i].first, &stocks[i].second);
	printf("%d", knapsack(0, M, K));
	return 0;
}