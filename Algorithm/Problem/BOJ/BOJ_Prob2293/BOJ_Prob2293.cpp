#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, K;	
	scanf("%d %d", &N, &K);
	vector<int> DP(K + 1, 0);
	for (int i = 0; i < N; i++) {
		int coin;
		scanf("%d", &coin);
		DP[coin]++;
		for (int j = 1; j <= K; j++)
			if (j - coin > 0)
				DP[j] += DP[j - coin];
	}
	printf("%d", DP[K]);
	return 0;
}