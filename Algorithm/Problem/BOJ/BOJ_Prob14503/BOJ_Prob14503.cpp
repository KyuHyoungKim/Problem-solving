#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
// 0 : 북
// 1 : 동
// 2 : 남
// 3 : 서
int main() {
	freopen("input.txt", "r", stdin);
	int N, M,res = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> Map(N, vector<int>(M));
	pair<int, int> pos;
	int dir;
	
	scanf("%d %d %d", &pos.first, &pos.second, &dir);

	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) 
			scanf("%d", &Map[i][j]);

	while (1) {
		// 로봇청소기의 현 위치가 청소되어있지 않으면 청소
		if (!Map[pos.first][pos.second]) {
			Map[pos.first][pos.second] = 2;
			res++;
		}
		for (int i = 1; i <= 4; i++) {
			// 왼쪽방향으로 회전
			dir--;
			if (dir < 0)
				dir += 4;
			// 바라보는 방향으로 한칸 앞의 위치
			int Next_Y = pos.first + dy[dir];
			int Next_X = pos.second + dx[dir];

			// 청소하지 않은 공간이 있으면 이동
			if (!Map[Next_Y][Next_X]) {
				pos.first = Next_Y;
				pos.second = Next_X;
				break;
			}

			// 네 방향 다 청소할 공간이 아닌경우(청소가 이미 되어있거나 벽)
			if (i == 4) {
				//후진할 방향(회전은 하지 않음)과 위치
				int Back_dir = (dir + 2) % 4;
				int Back_Y = pos.first + dy[Back_dir];
				int Back_X = pos.second + dx[Back_dir];

				// 뒤가 벽인 경우 -> 끝
				if (Map[Back_Y][Back_X] == 1) {
					printf("%d", res);
					return 0;
				}
				else {// 뒤가 벽이 아닌경우 -> 후진
					pos.first = Back_Y;
					pos.second = Back_X;
				}
			}
		}
	}
	return 0;
}