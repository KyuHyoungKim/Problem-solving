#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
//BFS로 접근, 시간 초과
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
	scanf("%d %d", &N, &M);
	vector<string> map(N);
	vector<pair<int, int>> walls;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++)
			if (map[i][j] == '1')
				walls.push_back(make_pair(i, j));
	}
	for (int i = 0; i < walls.size(); i++) {
		int cnt = 0;
		queue<pair<int, int>> q;
		vector<vector<bool>> checked(N, vector<bool>(M));
		q.push(walls[i]);
		checked[walls[i].first][walls[i].second] = true;
		while (!q.empty()) {
			int Y = q.front().first;
			int X = q.front().second;
			cnt++;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int Y_Next = Y + dy[i];
				int X_Next = X + dx[i];
				if (Y_Next < 0 || Y_Next >= N || X_Next < 0 || X_Next >= M || checked[Y_Next][X_Next]) continue;
				if (map[Y_Next][X_Next] == '0') {
					q.push(make_pair(Y_Next, X_Next));
					checked[Y_Next][X_Next] = true;
				}
			}
		}
		cnt %= 10;
		map[walls[i].first][walls[i].second] = cnt + '0';
	}
	for (int i = 0; i < N; i++)
		cout << map[i] << '\n';
	return 0;
}