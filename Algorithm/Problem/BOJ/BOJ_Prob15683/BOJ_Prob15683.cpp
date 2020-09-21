#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, -1, 0, 1 };
int N, M, res = 0;
vector<vector<int>> Map;
vector<pair<int, int>> CCTVs;

void init();
int sol(int cctv, int cnt, vector<vector<int>> map);

int main() {
	freopen("input.txt", "r", stdin);
	init();
	res -= sol(0, 0, Map);

	printf("%d", res);
	return 0;
}

void init() {
	scanf("%d %d", &N, &M);
	vector<vector<int>> Map_init(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &Map_init[i][j]);
			if (!Map_init[i][j])
				res++;
			else if (Map_init[i][j] < 6)
				CCTVs.push_back(make_pair(i, j));
		}
	Map.swap(Map_init);
}

int sol(int cctv, int cnt, vector<vector<int>> map) {
	if (cctv >= CCTVs.size())
		return cnt;
	int ret = 0, a;

	int Y = CCTVs[cctv].first;
	int X = CCTVs[cctv].second;
	int CC_type = Map[Y][X];
	if (CC_type == 1) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> Map_temp = map;
			int cnt_temp = cnt;
			int Y_temp = Y;
			int X_temp = X;
			while (1) {
				Y_temp += dy[i];
				X_temp += dx[i];
				if (Y_temp < 0 || Y_temp >= N || X_temp < 0 || X_temp >= M)
					break;
				if (Map_temp[Y_temp][X_temp] == 6)
					break;

				if (!Map_temp[Y_temp][X_temp]) {
					Map_temp[Y_temp][X_temp] = -1;
					cnt_temp++;
				}
			}
			a = sol(cctv + 1, cnt_temp, Map_temp);
			if (ret < a)
				ret = a;
		}
	}
	else if (CC_type == 2) {
		for (int i = 0; i < 2; i++) {
			vector<vector<int>> Map_temp = map;
			int cnt_temp = cnt;
			for (int j = 0; j < 2; j++) {
				int Y_temp = Y;
				int X_temp = X;
				while (1) {
					Y_temp += dy[i + j * 2];
					X_temp += dx[i + j * 2];
					if (Y_temp < 0 || Y_temp >= N || X_temp < 0 || X_temp >= M)
						break;
					if (Map_temp[Y_temp][X_temp] == 6)
						break;

					if (!Map_temp[Y_temp][X_temp]) {
						Map_temp[Y_temp][X_temp] = -1;
						cnt_temp++;
					}
				}
			}
			a = sol(cctv + 1, cnt_temp, Map_temp);
			if (ret < a)
				ret = a;
		}
	}
	else if (CC_type == 3) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> Map_temp = map;
			int cnt_temp = cnt;
			for (int j = 0; j < 2; j++) {
				int Y_temp = Y;
				int X_temp = X;
				int dir = (i + j) % 4;
				while (1) {
					Y_temp += dy[dir];
					X_temp += dx[dir];
					if (Y_temp < 0 || Y_temp >= N || X_temp < 0 || X_temp >= M)
						break;
					if (Map_temp[Y_temp][X_temp] == 6)
						break;

					if (!Map_temp[Y_temp][X_temp]) {
						Map_temp[Y_temp][X_temp] = -1;
						cnt_temp++;
					}
				}
			}
			a = sol(cctv + 1, cnt_temp, Map_temp);
			if (ret < a)
				ret = a;
		}
	}
	else if (CC_type == 4) {
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> Map_temp = map;
			int cnt_temp = cnt;
			for (int j = 0; j < 4; j++) {
				if (i == j)
					continue;
				int Y_temp = Y;
				int X_temp = X;
				while (1) {
					Y_temp += dy[j];
					X_temp += dx[j];
					if (Y_temp < 0 || Y_temp >= N || X_temp < 0 || X_temp >= M)
						break;
					if (Map_temp[Y_temp][X_temp] == 6)
						break;

					if (!Map_temp[Y_temp][X_temp]) {
						Map_temp[Y_temp][X_temp] = -1;
						cnt_temp++;
					}
				}
			}
			a = sol(cctv + 1, cnt_temp, Map_temp);
			if (ret < a)
				ret = a;
		}
	}
	else if (CC_type == 5) {
		for (int i = 0; i < 4; i++) {
			int Y_temp = Y;
			int X_temp = X;
			while (1) {
				Y_temp += dy[i];
				X_temp += dx[i];
				if (Y_temp < 0 || Y_temp >= N || X_temp < 0 || X_temp >= M)
					break;
				if (map[Y_temp][X_temp] == 6)
					break;

				if (!map[Y_temp][X_temp]) {
					map[Y_temp][X_temp] = -1;
					cnt++;
				}
			}
			a = sol(cctv + 1, cnt, map);
			if (ret < a)
				ret = a;
		}
	}

	return ret;
}