#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, res = 0;
	scanf("%d %d", &M, &N);
	vector<vector<int>> tomato(N, vector<int>(M));
	queue<pair<int, int>> now;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &tomato[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tomato[i][j] == 1)
				now.push(make_pair(i, j));
	while (1)
	{
		queue<pair<int, int>> next;
		while (!now.empty()) {
			int cur_y = now.front().first;
			int cur_x = now.front().second;
			now.pop();
			for (int i = 0; i < 4; i++)
			{
				int Y = cur_y + dy[i], X = cur_x + dx[i];
				if (Y >= 0 && Y < N && X >= 0 && X < M && !tomato[Y][X])
				{
					next.push(make_pair(Y, X));
					tomato[Y][X] = 1;
				}
			}
		}
		now = next;
		if (now.empty())
			break;
		else
			res++;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!tomato[i][j])
			{
				printf("-1\n");
				return 0;
			}
	printf("%d\n", res);
	return 0;
}