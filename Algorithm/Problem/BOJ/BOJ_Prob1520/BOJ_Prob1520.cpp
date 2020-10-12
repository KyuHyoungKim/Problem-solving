#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
const int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0 ,1 ,-1 };
int N, M;
vector<vector<int>> height;
vector<vector<int>> DP;

int DFS(int Y, int X) {
	if (DP[Y][X] >= 0)
		return DP[Y][X];
	else {
		DP[Y][X] = 0;
		for (int i = 0; i < 4; i++) {
			int Y_next = Y + dy[i];
			int X_next = X + dx[i];
			if (Y_next < 0 || Y_next >= N) continue;
			if (X_next < 0 || X_next >= M) continue;
			if (height[Y_next][X_next] >= height[Y][X]) continue;

			DP[Y][X] += DFS(Y_next, X_next);
		}
	}
	return DP[Y][X];
}
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	height = vector<vector<int>>(N, vector<int>(M));
	DP = vector<vector<int>>(N, vector<int>(M, -1));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &height[i][j]);
	DP[N - 1][M - 1] = 1;

	printf("%d", DFS(0, 0));
	return 0;
}