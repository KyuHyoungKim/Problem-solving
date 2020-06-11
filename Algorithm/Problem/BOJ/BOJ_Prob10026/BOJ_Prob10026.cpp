#include <cstdio>
#include <queue>
using namespace std;
char color[100][101] = { '\0' };
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0 };
int N;
void BFS(int i, int j, int check[][101]) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	while (!q.empty()) {
		int now_y = q.front().first, now_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int Y = now_y + dy[i], X = now_x + dx[i];
			if (Y >= 0 && Y < N && X >= 0 && X < N && color[now_y][now_x] == color[Y][X] && !check[Y][X]) {
				q.push(make_pair(Y, X));
				check[Y][X] = 1;
			}
		}
	}
}

int main() {
	int res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", color[i]);

	for (int n = 0; n < 1; n++) {
		int check[100][101] = { 0 };
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (!check[i][j]) {
					BFS(i, j, check);
					res++;
				}
	}
	printf("%d\n", res);

	res = 0;
	int check[100][101] = { 0 };
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (color[i][j] == 'R')
				color[i][j] = 'G';
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (!check[i][j]) {
				BFS(i, j, check);
				res++;
			}
	printf("%d\n", res);


	return 0;
}