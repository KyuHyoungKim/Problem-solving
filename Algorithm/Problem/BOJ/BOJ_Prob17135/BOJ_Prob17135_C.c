#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

const int dy[3] = { 0, -1, 0 }, dx[3] = { -1,0,1 };
int N, M, D, cnt;
int m_init[15][15] = { 0 };

typedef struct pair {
	int first;
	int second;
}pair;
pair make_pair(int First, int Second) {
	pair ret;
	ret.first = First;
	ret.second = Second;
	return ret;
}

pair DFS(int arrow, int m[][15]) {
	pair q[225];
	pair ret;
	int front = 0, idx = 1;
	bool checked[15][15] = { false };
	
	q[front] = make_pair(N - 1, arrow);
	checked[N - 1][arrow] = true;

	while (front < idx) {
		int y = q[front].first;
		int x = q[front].second;
		front++;

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

			q[idx].first = Y;
			q[idx].second = X;
			checked[Y][X] = true;
			idx++;
		}
	}
	return ret;
}
int move(int m[][15]) {
	int ret = 0;
	for(int j = 0; j < M; j++)
		if (m[N - 1][j]) {
			ret++;
			m[N - 1][j] = 0;
		}

	for (int i = N - 1; i > 0; i--)
		for (int j = 0; j < M; j++) 
			if (m[i - 1][j]) {
				m[i][j] = 1;
				m[i - 1][j] = 0;
			}

	return ret;
}
int sol(int arrow1, int arrow2, int arrow3) {
	int m[15][15];
	int ret = 0, fail_cnt = 0;
	memcpy(m, m_init, sizeof(m_init));
	while (ret + fail_cnt < cnt) {
		pair a1 = DFS(arrow1, m);
		int dist1 = abs(a1.first - N) + abs(a1.second - arrow1);
		pair a2 = DFS(arrow2, m);
		int dist2 = abs(a2.first - N) + abs(a2.second - arrow2);
		pair a3 = DFS(arrow3, m);
		int dist3 = abs(a3.first - N) + abs(a3.second - arrow3);

		if (m[a1.first][a1.second] && dist1 <= D) {
			ret++;
			m[a1.first][a1.second] = 0;
		}
		if (m[a2.first][a2.second] && dist2 <= D) {
			ret++;
			m[a2.first][a2.second] = 0;
		}
		if (m[a3.first][a3.second] && dist3 <= D) {
			ret++;
			m[a3.first][a3.second] = 0;
		}

		fail_cnt += move(m);
	}
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &D);
	int res = 0, a;
	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &m_init[i][j]);
			if (m_init[i][j])
				cnt++;
		}

	for(int i = 0 ; i < M -2; i++)
		for(int j = i + 1; j < M - 1; j++)
			for (int k = j + 1; k < M; k++) {
				a = sol(i, j, k);
				if (a > res)
					res = a;
			}

	printf("%d\n", res);
	return 0;
}