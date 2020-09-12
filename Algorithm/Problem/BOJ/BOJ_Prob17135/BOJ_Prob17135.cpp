#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int dy[3] = { 0,-1,0 }, dx[3] = { -1,0,1 };
int N, M, D;
vector<vector<int>> m;

pair<int, int> DFS(int x_pos) {
	pair<int, int> ret;
	queue<pair<int, int>> q;
	vector<vector<bool>> checked(N, vector<bool>(M, false));

	q.push(make_pair(N - 1, x_pos));
	checked[N - 1][x_pos] = true;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (m[y][x]) {
			ret.first = y;
			ret.second = x;
			break;
		}
		for (int i = 0; i < 3; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (Y < 0 || Y >= N || X < 0 || X >= M || checked[Y][X])
				continue;

			q.push(make_pair(Y, X));
			checked[Y][X] = true;
		}

	}
	return ret;
}
int move() {
	int ret = 0;
	for (int j = 0; j < M; j++)
		if (m[N - 1][j]) {
			ret++;
			m[N - 1][j] = 0;
		}

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < M; j++)
			m[i][j] = m[i - 1][j];

	for (int j = 0; j < M; j++)
		m[0][j] = 0;

	return ret;
}

int main() {
	int res = 0, cnt = 0;
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &D);
	m.resize(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &m[i][j]);
			if (m[i][j])
				cnt++;
		}
	vector<vector<int>> m_init = m;

	for (int i = 0; i < M - 2; i++)
		for (int j = i + 1; j < M - 1; j++)
			for (int k = j + 1; k < M; k++) {
				int ans = 0;
				int fail_cnt = 0;
				while (ans + fail_cnt < cnt) {
					pair<int, int> a1 = DFS(i);
					pair<int, int> a2 = DFS(j);
					pair<int, int> a3 = DFS(k);

					if (m[a1.first][a1.second] && D >= abs(a1.first - N) + abs(a1.second - i)) {
						m[a1.first][a1.second] = 0;
						ans++;
					}

					if (m[a2.first][a2.second] && D >= abs(a2.first - N) + abs(a2.second - j)) {
						m[a2.first][a2.second] = 0;
						ans++;
					}

					if (m[a3.first][a3.second] && D >= abs(a3.first - N) + abs(a3.second - k)) {
						m[a3.first][a3.second] = 0;
						ans++;
					}

					fail_cnt += move();
				}

				if (ans > res)
					res = ans;
				m = m_init;
			}

	printf("%d", res);
	return 0;
}