#define _CRT_SECURE_NO_WARNINGS
#define Cheese 1
#define Air 2
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };

void check_air(vector<vector<int>>& cheeses, int y_pos, int x_pos) {
	queue<pair<int, int>> q;
	q.push(make_pair(y_pos, x_pos));
	cheeses[y_pos][x_pos] = Air;
	while (!q.empty()) {
		int now_y = q.front().first, now_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int Y = now_y + dy[i], X = now_x + dx[i];
			if (Y >= 0 && Y <= N + 1 && X >= 0 && X <= M + 1 && !cheeses[Y][X])
			{
				q.push(make_pair(Y, X));
				cheeses[Y][X] = Air;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int cheese_cnt = 0, res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> cheeses(N + 2, vector<int>(M + 2));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &cheeses[i][j]);
			if (cheeses[i][j]) cheese_cnt++;
		}

	check_air(cheeses, 0, 0);

	while (cheese_cnt > 0) {
		res++;
		vector<vector<int>> cheeses_next;
		cheeses_next = cheeses;
		for(int i = 1 ; i <=N; i++ )
			for (int j = 1; j <= M; j++)
			{
				if (cheeses[i][j] == Cheese)
				{
					int count = 0;
					for (int n = 0; n < 4; n++) {
						int Y = i + dy[n], X = j + dx[n];
						if (cheeses[Y][X] == Air)
							count++;
					}
					if (count >= 2) {
						cheeses_next[i][j] = 0;
						cheese_cnt--;
						check_air(cheeses_next, i, j);
					}
				}
			}
		cheeses = cheeses_next;
	}
	printf("%d\n", res);
	return 0;
}