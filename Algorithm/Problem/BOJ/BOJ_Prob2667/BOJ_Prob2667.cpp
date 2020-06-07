#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1,1,0,0 };
	char input[26];
	scanf("%d", &N);
	vector<vector<int>> Map(N, vector<int>(N));
	vector<int> res;
	for (int i = 0; i < N; i++)
	{
		scanf("%s", input);
		for (int j = 0; j < N; j++)
			Map[i][j] = input[j] - '0';
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j]) {
				int cnt = 1;
				queue<pair<int, int>> que;
				que.push(make_pair(i, j));
				Map[i][j] = 0;
				while (!que.empty()) {
					int now_y = que.front().first;
					int now_x = que.front().second;
					que.pop();
					for (int k = 0; k < 4; k++) {
						int Y = now_y + dy[k], X = now_x + dx[k];
						if (X >= 0 && Y >= 0 && X < N && Y < N && Map[Y][X]) {
							que.push(make_pair(Y, X));
							Map[Y][X] = 0;
							cnt++;
						}
					}
				}
				res.push_back(cnt);
			}
		}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}