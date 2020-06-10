#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int M, N, H;
class pos {
public:
	int x = 0;
	int y = 0;
	int z = 0;
};
pos make_pos(int z_, int y_, int x_) {
	pos ret;
	ret.x = x_;
	ret.y = y_;
	ret.z = z_;
	return ret;
}
bool Index_check(int X, int Y, int Z) {
	bool ret = true;
	if (X < 0 || Y < 0 || Z < 0) return false;
	if (X >= M || Y >= N || Z >= H) return false;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int res = 1;
	int dx[6] = { -1, 1, 0, 0, 0, 0 }, dy[6] = { 0, 0, -1, 1, 0, 0 }, dz[6] = { 0, 0, 0, 0, -1, 1 };
	scanf("%d %d %d", &M, &N, &H);
	vector<vector<vector<int>>> Tomato(H, vector<vector<int>>(N, vector<int>(M)));
	queue<pos> q;
	for (int h = 0; h < H; h++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		scanf("%d", &Tomato[h][i][j]);
		if (Tomato[h][i][j] == 1) q.push(make_pos(h, i, j));
	}

	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			int X = now.x + dx[i], Y = now.y + dy[i], Z = now.z + dz[i];
			if (Index_check(X, Y, Z) && Tomato[Z][Y][X] == 0) {
				q.push(make_pos(Z, Y, X));
				Tomato[Z][Y][X] = Tomato[now.z][now.y][now.x] + 1;
				if (Tomato[Z][Y][X] > res) res = Tomato[Z][Y][X];
			}
		}
	}
	for (int h = 0; h < H; h++) for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
		if (!Tomato[h][i][j]) {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",res - 1);
	return 0;
}