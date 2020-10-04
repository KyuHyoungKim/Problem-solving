#define _CRT_SECURE_NO_WARNINGS
#define SHARK 1000
#define EMPTY -1000
#include <cstdio>
#include <vector>
using namespace std;

const int dy[8] = { -1,-1,0,1,1,1,0,-1 }, dx[8] = { 0,-1,-1,-1,0,1,1,1 };

struct fish {
	int y;
	int x;
	int dir;
};

void move_fish(vector<vector<int>>& pool, vector<fish>& fishes, vector<bool>& died);
int move_shark(vector<vector<int>>& pool, vector<fish>& fishes, vector<bool>& died, fish shark);
int solution(vector<vector<int>> pool, vector<fish> fishes, vector<bool> died, fish shark);

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	vector<vector<int>> pool(4, vector<int>(4));
	vector<fish> fishes(17);
	vector<bool> died(17, false);
	fish shark;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int num, dir;
			scanf("%d %d", &num, &dir);
			pool[i][j] = num;
			fishes[num].dir = dir - 1;
			fishes[num].y = i;
			fishes[num].x = j;
		}
	res = pool[0][0];
	pool[0][0] = SHARK;
	died[res] = true;

	shark.y = 0;
	shark.x = 0;
	shark.dir = fishes[res].dir;

	res += solution(pool, fishes, died, shark);
	printf("%d", res);
	return 0;
}

int solution(vector<vector<int>> pool, vector<fish> fishes, vector<bool> died, fish shark) {
	int ret = 0;
	fish shark_next;

	move_fish(pool, fishes, died);
	ret = move_shark(pool, fishes, died, shark);

	return ret;
}

void move_fish(vector<vector<int>>& pool, vector<fish>& fishes, vector<bool>& died) {
	for (int i = 1; i <= 16; i++) {
		if (died[i])
			continue;
		int Y = fishes[i].y;
		int X = fishes[i].x;
		int dir = fishes[i].dir;
		for (int d = 0; d < 8; d++) {
			int dir_next = (dir + d) % 8;
			int Y_next = Y + dy[dir_next];
			int X_next = X + dx[dir_next];
			int target;
			if (Y_next < 0 || Y_next >= 4 || X_next < 0 || X_next >= 4) continue;
			if (pool[Y_next][X_next] == SHARK) continue;

			target = pool[Y_next][X_next];
			fishes[i].dir = dir_next;
			if (target == EMPTY) {
				fishes[i].y = Y_next;
				fishes[i].x = X_next;
			}
			else {
				swap(fishes[target].x, fishes[i].x);
				swap(fishes[target].y, fishes[i].y);
			}
			swap(pool[Y_next][X_next], pool[Y][X]);
			break;
		}
	}
}

int move_shark(vector<vector<int>>& pool, vector<fish>& fishes, vector<bool>& died, fish shark) {
	int ret = 0, a;
	fish shark_next;
	pool[shark.y][shark.x] = EMPTY;
	for (int i = 1; i <= 3; i++) {
		int victim;
		shark_next.y = shark.y + i * dy[shark.dir];
		shark_next.x = shark.x + i * dx[shark.dir];
		if (shark_next.y < 0 || shark_next.y >= 4 || shark_next.x < 0 || shark_next.x >= 4) break;
		if (pool[shark_next.y][shark_next.x] == EMPTY) continue;

		victim = pool[shark_next.y][shark_next.x];
		shark_next.dir = fishes[victim].dir;
		pool[shark_next.y][shark_next.x] = SHARK;
		died[victim] = true;

		a = victim + solution(pool, fishes, died, shark_next);
		if (a > ret)
			ret = a;

		pool[shark_next.y][shark_next.x] = victim;
		died[victim] = false;
	}
	return ret;
}