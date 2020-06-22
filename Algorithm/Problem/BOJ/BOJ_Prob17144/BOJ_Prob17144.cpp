#define _CRT_SECURE_NO_WARNINGS
#define Index_Check X>=0 && X < M && Y >=0 && Y < N && room[Y][X] >=0
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, T, res = 0;
	int dy[4] = { 1, -1, 0 , 0 }, dx[4] = { 0, 0, -1, 1 };
	scanf("%d %d %d", &N, &M, &T);
	vector<vector<int>> room(N, vector<int>(M));
	vector<int> cleaner;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &room[i][j]);
			if (room[i][j] > 0) res += room[i][j];
			else if (room[i][j] < 0) cleaner.push_back(i);
		}
	while (T--) {
		// 확산
		vector<vector<int>> room_next(N, vector<int>(M));
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				room_next[i][j] += room[i][j];
				int Amount = room[i][j] / 5;
				for (int n = 0; n < 4; n++)
				{
					int Y = i + dy[n], X = j + dx[n];
					if (Index_Check)
					{
						room_next[Y][X] += Amount;
						room_next[i][j] -= Amount;
					}
				}
			}
		// 순환
		res -= room_next[cleaner[0] - 1][0];
		res -= room_next[cleaner[1] + 1][0];

		// 윗부분(반시계)
		for (int i = cleaner[0] - 1; i >= 1; --i)  // 위 -> 아래
			room_next[i][0] = room_next[i - 1][0];
		for (int i = 0; i < M - 1; i++) //오 -> 왼
			room_next[0][i] = room_next[0][i + 1];
		for (int i = 0; i < cleaner[0]; i++) //아래 -> 위
			room_next[i][M - 1] = room_next[i + 1][M - 1];
		for (int i = M - 1; i >= 2; i--) //왼 -> 오
			room_next[cleaner[0]][i] = room_next[cleaner[0]][i - 1];
		room_next[cleaner[0]][1] = 0;


		// 아랫부분(시계)
		for (int i = cleaner[1] + 1; i < N - 1; i++) //아래 -> 위
			room_next[i][0] = room_next[i + 1][0];
		for (int i = 0; i < M - 1; i++) //오 -> 왼
			room_next[N - 1][i] = room_next[N - 1][i + 1];
		for (int i = N - 1; i >= cleaner[1]; --i)  // 위 -> 아래
			room_next[i][M - 1] = room_next[i - 1][M - 1];
		for (int i = M - 1; i >= 2; i--) //왼 -> 오
			room_next[cleaner[1]][i] = room_next[cleaner[1]][i - 1];
		room_next[cleaner[1]][1] = 0;

		room.swap(room_next);
	}
	printf("%d", res);
	return 0;
}