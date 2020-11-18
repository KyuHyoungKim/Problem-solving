#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//위부터 시계방향
const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dx[8] = { 0, 1, 1, 1, 0, -1 , -1, -1 };
int N, M;
vector<string> strs;
vector<vector<vector<int>>> DP;

int solution(int y, int x, int idx, string& target) {
	if (idx >= target.size())
		return 1;
	if (DP[y][x][idx])
		return DP[y][x][idx];
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		int Y = (y + dy[i] + N) % N, X = (x + dx[i] + M) % M;
		if (strs[Y][X] == target[idx])
			ret += solution(Y, X, idx + 1, target);
	}
	DP[y][x][idx] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);

	int K;
	cin >> N >> M >> K;
	strs.resize(N);
	for (int i = 0; i < N; i++)
		cin >> strs[i];

	while (K--) {
		string target;
		int ans = 0;
		cin >> target;
		DP = vector<vector<vector<int>>>(N, vector<vector<int>>(M, vector<int>(target.size())));

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				if (strs[i][j] == target[0])
					ans += solution(i, j, 1, target);

		printf("%d\n", ans);
	}
	return 0;
}