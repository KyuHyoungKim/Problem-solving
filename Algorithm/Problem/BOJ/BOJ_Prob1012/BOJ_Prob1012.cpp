#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int>> pos;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void func(int x, int y) {
	pos[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		if (pos[y + dy[i]][x + dx[i]])
			func(x + dx[i], y + dy[i]);
	}
}
int main(void)
{
	freopen("input.txt", "r", stdin);
	int T = 0, M = 0, N = 0, K = 0, X = 0, Y = 0, cnt = 0;
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		scanf("%d %d %d", &M, &N, &K);
		vector<vector<int>> pos_blank(N+2,vector<int>(M+2));
		pos = pos_blank;
		for (int j = 0; j < K; j++)
		{
			scanf("%d %d", &X, &Y);
			pos[Y + 1][X + 1] = 1;
		}
		for (int y = 1; y <= N; y++)
			for (int x = 1; x <= M; x++)
				if (pos[y][x]) {
					cnt++;
					func(x, y);
				}
		printf("%d\n", cnt);
	}
	return 0;
}