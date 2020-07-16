#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class house {
public:
	int cost[3] = { 0 }, DP[3] = { 0 };
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 123456789;
	scanf("%d", &N);
	vector<house> houses(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &houses[i].cost[0], &houses[i].cost[1], &houses[i].cost[2]);
	for (int n = 0; n < 3; n++) {
		for (int i = 0; i < 3; i++)
			houses[0].DP[i] = 123456789;
		houses[0].DP[n] = houses[0].cost[n]; 
		
		for (int i = 1; i < N; i++) {
			houses[i].DP[0] = min(houses[i - 1].DP[1], houses[i - 1].DP[2]) + houses[i].cost[0];
			houses[i].DP[1] = min(houses[i - 1].DP[0], houses[i - 1].DP[2]) + houses[i].cost[1];
			houses[i].DP[2] = min(houses[i - 1].DP[0], houses[i - 1].DP[1]) + houses[i].cost[2];
		}

		for (int i = 0; i < 3; i++) {
			if (i == n) continue;
			if (res > houses[N - 1].DP[i]) 
				res = houses[N - 1].DP[i];
		}
	}
	
	printf("%d", res);
	return 0;
}