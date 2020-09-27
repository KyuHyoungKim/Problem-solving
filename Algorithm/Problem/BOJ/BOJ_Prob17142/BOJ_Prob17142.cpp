#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

const int dy[4] = { -1 ,1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };
int res = INF;
int N, M, blank_cnt = 0;
vector<vector<int>> Map;
vector<pair<int, int>> Viruses;
vector<int> selected;

int BFS(vector<vector<int>> map) {
	int ret = 0;
	int cnt = -M;
	queue<pair<int, int>> q;
	for (int i = 0; i < M; i++) {
		q.push(Viruses[selected[i]]);
		map[Viruses[selected[i]].first][Viruses[selected[i]].second] = 1;
	}
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		int time = map[y][x];
		q.pop();
		if (time > ret)
			ret = time;

		if (time >= 0)
			cnt++;
		else
			time *= -1;

		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];
			if (Y < 0 || Y >= N || X < 0 || X >= N || map[Y][X] > 0 || map[Y][X] < -1)
				continue;
			if (map[Y][X] < 0)
				map[Y][X] *= (time + 1);
			else 
				map[Y][X] = time + 1;
			q.push(make_pair(Y, X));
		}
	}
	ret--;
	if (cnt != blank_cnt)
		ret = INF;
	return ret;
}

void solution(int cnt, int idx) {
	if (cnt == M) {
		int ans = BFS(Map);
		if (ans < res)
			res = ans;
		return;
	}
	if (idx >= Viruses.size())
		return;
	for (int i = idx; i < Viruses.size(); i++) {
		selected[cnt] = i;
		solution(cnt + 1, i + 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	Map.resize(N);
	selected.resize(M);
	for (int i = 0; i < N; i++) {
		Map[i].resize(N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &Map[i][j]);
			if (Map[i][j] == 2) {
				Map[i][j] = -1;
				Viruses.push_back(make_pair(i, j));
			}
			else if (Map[i][j] == 0)
				blank_cnt++;
		}
	}
	solution(0, 0);
	if (res == INF)
		res = -1;
	printf("%d", res);
	return 0;
}