#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };
	scanf("%d %d", &N, &M);
	vector<string> map(N);
	vector<pair<int, int>> walls;
	vector<vector<int>> sector(N, vector<int>(M));
	vector<int> sector_area(1);
	vector<vector<bool>> checked(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++)
			if (map[i][j] == '1')
				walls.push_back(make_pair(i, j));
	}
	int sector_cnt = 1;
	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '0' && !checked[i][j]) {
				int area_cnt = 0;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				checked[i][j] = true;

				while (!q.empty()) {
					int Y = q.front().first;
					int X = q.front().second;
					q.pop();
					sector[Y][X] = sector_cnt;
					area_cnt++;
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
				sector_area.push_back(area_cnt);
				sector_cnt++;
			}
			else checked[i][j] = true;
		}

	for (int i = 0; i < walls.size(); i++) {
		int Y = walls[i].first;
		int X = walls[i].second;
		int area = 1;
		vector<int> sector_list;
		for (int i = 0; i < 4; i++) {
			int Y_side = Y + dy[i];
			int X_side = X + dx[i];
			bool sector_check = true;
			if (Y_side < 0 || Y_side >= N || X_side < 0 || X_side >= M || map[Y_side][X_side] != '0') continue;
			int sector_num = sector[Y_side][X_side];
			
			for (int i = 0; i < sector_list.size(); i++)
				if (sector_list[i] == sector_num) {
					sector_check = false;
					break;
				}
			
			if (sector_check) {
				sector_list.push_back(sector_num);
				area += sector_area[sector[Y_side][X_side]];
			}
		}
		area %= 10;
		map[Y][X] = area + '0';
	}
	for (int i = 0; i < N; i++)
		printf("%s\n", map[i].c_str());
	return 0;
}