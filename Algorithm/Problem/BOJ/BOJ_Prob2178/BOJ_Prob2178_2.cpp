#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int N, M;
	int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };
	scanf("%d %d", &N, &M);
	char input[101];
	vector<vector<int>> maze(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		scanf("%s", input);
		for (int j = 0; j < M; j++)
			maze[i][j] = input[j] - '0';
	}
	queue<pair<int, int>> curr;
	curr.push(make_pair(0, 0));
	while (!curr.empty()) {
		pair<int, int> now = curr.front();
		curr.pop();
		for (int i = 0; i < 4; i++) {
			int Y = now.first + dy[i];
			int X = now.second + dx[i];
			if (X >= 0 && X < M && Y >= 0 && Y < N && maze[Y][X] == 1) {
				if (!(Y == 0 && X == 0)) {
					maze[Y][X] = maze[now.first][now.second] + 1;
					curr.push(make_pair(Y, X));
				}
			}
			if (X == M - 1 && Y == N - 1) {
				printf("%d\n", maze[N - 1][M - 1]);
				return 0;
			}
		}
	}
	return 0;
}