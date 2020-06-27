#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct Node {
	int y_pos, x_pos, wall_cnt, dist;
};
Node make_Node(int y, int x, int wall, int distance) {
	Node ret;
	ret.y_pos = y; ret.x_pos = x; ret.wall_cnt = wall; ret.dist = distance;
	return ret;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dy[4] = { 0, 0, 1, -1 }, dx[4] = { 1, -1, 0, 0 };
	scanf("%d %d", &N, &M);
	vector<vector<int>> Map(N, vector<int>(M));
	vector<vector<vector<int>>> checked(2, vector<vector<int>>(N, vector<int>(M)));
	for (int i = 0; i < N; i++) {
		char input[1001];
		scanf("%s", input);
		for (int j = 0; j < M; j++)
			Map[i][j] = input[j] - '0';
	}
	if (N == 1 && M == 1) { printf("1\n"); return 0; }
	queue<Node> q;
	q.push(make_Node(0, 0, Map[0][0], 1));
	checked[0][0][0] = -1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int Y = now.y_pos + dy[i];
			int X = now.x_pos + dx[i];
			if (Y < 0 || Y >= N || X < 0 || X >= M) continue;
			if (Y == N - 1 && X == M - 1) {
				printf("%d\n", now.dist + 1);
				return 0;
			}

			int Dist_next = now.dist + 1;
			int wall_count = now.wall_cnt + Map[Y][X];
			if (wall_count >= 2) continue;


			if (!checked[wall_count][Y][X]) {
				q.push(make_Node(Y, X, wall_count, Dist_next));
				checked[wall_count][Y][X] = 1;
			}
		}
	}
	printf("-1\n");
	return 0;
}