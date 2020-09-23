#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 }, dx[4] = { 1, 0, -1, 0 };

struct Dragon_Curve {
	int x;
	int y;
	int d;
	int g;
};

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	int Map[101][101] = { 0 };

	scanf("%d", &N);
	vector<Dragon_Curve> curves(N);

	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &curves[i].x, &curves[i].y, &curves[i].d, &curves[i].g);

	for (int i = 0; i < N; i++) {
		int Y = curves[i].y;
		int X = curves[i].x;
		int g = curves[i].g;
		vector<int> dir;
		dir.push_back(curves[i].d);

		Map[Y][X] = 1;
		Y += dy[dir[0]];
		X += dx[dir[0]];
		Map[Y][X] = 1;

		for (int j = 1; j <= g; j++) {
			for (int k = dir.size() - 1; k >= 0; k--) {
				int d = (dir[k] + 1) % 4;
				dir.push_back(d);
				Y += dy[d];
				X += dx[d];
				Map[Y][X] = 1;
			}
		}
	}

	for(int i = 1 ; i <= 100; i++)
		for (int j = 1; j <= 100; j++) {
			if (!Map[i][j])
				continue;
			Map[i][j] = min({ Map[i - 1][j - 1], Map[i - 1][j], Map[i][j - 1] }) + 1;
			if (Map[i][j] > 1)
				res++;
		}

	printf("%d", res);
	return 0;
}