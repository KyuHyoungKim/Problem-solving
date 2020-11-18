#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);

	int N, M, R;
	int score = 0;
	scanf("%d %d %d", &N, &M, &R);
	vector<vector<int>> board(N + 1, vector<int>(M + 1));
	vector<vector<bool>> res(N + 1, vector<bool>(M + 1, true));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &board[i][j]);

	while (R--) {
		int Y_att, X_att, Y_def, X_def;
		char dir;
		queue<pair<int, int>> q;
		scanf("%d %d %c", &Y_att, &X_att, &dir);
		scanf("%d %d", &Y_def, &X_def);

		if (res[Y_att][X_att])
			q.push(make_pair(Y_att, X_att));
		while (!q.empty()) {
			int Y = q.front().first;
			int X = q.front().second;
			int k = 1;
			int* variable = &X;
			int height = board[Y][X];
			bool dir_flag = false; // false : X, true : Y
			q.pop();
			if (!res[Y][X])
				continue;
			res[Y][X] = false;
			score++;
			if (dir == 'N' || dir == 'S') {
				variable = &Y;
				dir_flag = true;
			}
			if (dir == 'W' || dir == 'N') k *= -1;

			for (int i = 1; i < height; i++) {
				*variable += k;
				if (*variable <= 0 || (dir_flag && *variable > N) || (!dir_flag && *variable > M))
					break;
				if (!res[Y][X])
					continue;
				q.push(make_pair(Y, X));
			}
		}
		res[Y_def][X_def] = true;
	}
	printf("%d\n", score);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			printf("%c ", (res[i][j]) ? 'S' : 'F');
		printf("\n");
	}
	return 0;
}