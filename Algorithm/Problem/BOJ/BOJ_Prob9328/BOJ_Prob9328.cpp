#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int h, w;
vector<string> maps;
string keys;
vector<vector<pair<int, int>>> doors;
vector<vector<bool>> checked;

bool is_walls(int Y, int X);
queue<pair<int, int>> check_entrance();
void check_keys (queue<pair<int, int>>& q);

int main() {
	freopen("input.txt", "r", stdin);
	int T, dy[4] = { 0,0,-1,1 }, dx[4] = { 1,-1,0,0 };
	scanf("%d", &T);
	while (T--) {
		int res = 0;
		scanf("%d %d", &h, &w);

		maps.resize(h);
		keys.clear();
		vector<vector<pair<int, int>>> doors_init('Z' - 'A' + 1); doors.swap(doors_init);
		vector<vector<bool>> checked_init(h, vector<bool>(w, false)); checked.swap(checked_init);
		queue<pair<int, int>> q;

		for (int i = 0; i < h; i++) {
			cin >> maps[i];
			for (int j = 0; j < w; j++)
				if (maps[i][j] >= 'A' && maps[i][j] <= 'Z')
					doors[maps[i][j] - 'A'].push_back(make_pair(i, j));
		}

		q = check_entrance();
		cin >> keys;
		if (keys == "0") keys.clear();
		check_keys(q);

		while (!q.empty())
		{
			while (!q.empty())
			{
				int now_y = q.front().first;
				int now_x = q.front().second;
				checked[now_y][now_x] = true;
				if (maps[now_y][now_x] >= 'a' && maps[now_y][now_x] <= 'z') {
					keys.push_back(maps[now_y][now_x]);
					maps[now_y][now_x] = '.';
				}
				if (maps[now_y][now_x] == '$') {
					res++;
					maps[now_y][now_x] = '.';
				}
				q.pop();

				for (int i = 0; i < 4; i++) {
					int Y = now_y + dy[i];
					int X = now_x + dx[i];

					if (Y < 0 || Y >= h || X < 0 || X >= w || checked[Y][X]) continue;

					if (maps[Y][X] != '*' && (maps[Y][X] < 'A' || maps[Y][X] > 'Z'))
						q.push(make_pair(Y, X));
					checked[Y][X] = true;
				}
			}
			check_keys(q);
		}
		printf("%d\n", res);
	}
	return 0;
}

bool is_walls(int Y, int X) {
bool ret = true;
	if (maps[Y][X] != '*' && (maps[Y][X] < 'A' || maps[Y][X] > 'Z'))
		ret = false;
	return ret;
}

queue<pair<int, int>> check_entrance() {
	queue<pair<int, int>> q;
	for (int i = 0; i < h; i++) {
		if (!is_walls(i, 0)) q.push(make_pair(i, 0));
		if (!is_walls(i, w - 1)) q.push(make_pair(i, w - 1));
	}
	for (int i = 0; i < w; i++) {
		if (!is_walls(0, i)) q.push(make_pair(0, i));
		if (!is_walls(h - 1, i)) q.push(make_pair(h - 1, i));
	}
	return q;
}

void check_keys(queue<pair<int, int>>& q) {
	for (int i = 0; i < keys.size(); i++) {
		int idx = keys[i] - 'a';
		for (int j = 0; j < doors[idx].size(); j++) {
			int Y = doors[idx][j].first;
			int X = doors[idx][j].second;
			maps[Y][X] = '.';
			if (checked[Y][X]) {
				q.push(make_pair(Y, X));
				checked[Y][X] = false;
			}
			else if (Y == 0 || Y == h - 1 || X == 0 || X == w - 1)
				q.push(make_pair(Y, X));
		}
		doors[idx].clear();
	}
	keys.clear();
}