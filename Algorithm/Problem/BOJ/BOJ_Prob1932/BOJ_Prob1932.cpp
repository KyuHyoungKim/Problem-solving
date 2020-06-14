#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, temp;
	scanf("%d", &N);
	vector<vector<int>> points(N), dp(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++) {
			scanf("%d", &temp);
			points[i].push_back(temp);
		}
		dp[i].resize(points[i].size());
	}

	dp[N - 1] = points[N - 1];

	for (int i = N-2; i >=0; i--) 
		for (int j = 0; j < i + 1; j++) 
			dp[i][j] = (dp[i + 1][j] > dp[i + 1][j + 1]) ? dp[i + 1][j] + points[i][j] : dp[i + 1][j + 1] + points[i][j];
	
	printf("%d", dp[0][0]);
	
	return 0;
}