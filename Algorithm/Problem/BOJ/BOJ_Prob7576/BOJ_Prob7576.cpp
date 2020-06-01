#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, res = 1;
	scanf("%d %d", &M, &N);
	vector<vector<int>> tomato(N, vector<int>(M));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &tomato[i][j]);

	while (1) {
		int cnt = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++) {
				if (tomato[i][j] == res) {
					for (int k = 0; k < 4; k++) {
						int Y = i + dy[k], X = j + dx[k];
						if (Y >= 0 && Y < N && X >= 0 && X < M && !tomato[Y][X])
						{
							tomato[Y][X] = res + 1;
							cnt++;
						}
					}
				}
			}
		if (!cnt) break;
		res++;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (!tomato[i][j])
			{
				printf("-1\n");
				return 0;
			}
	printf("%d\n", res - 1);
	return 0;
}