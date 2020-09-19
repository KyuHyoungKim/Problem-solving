#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

using namespace std;

const int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
// 0 : ��
// 1 : ��
// 2 : ��
// 3 : ��
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
		// �κ�û�ұ��� �� ��ġ�� û�ҵǾ����� ������ û��
		if (!Map[pos.first][pos.second]) {
			Map[pos.first][pos.second] = 2;
			res++;
		}
		for (int i = 1; i <= 4; i++) {
			// ���ʹ������� ȸ��
			dir--;
			if (dir < 0)
				dir += 4;
			// �ٶ󺸴� �������� ��ĭ ���� ��ġ
			int Next_Y = pos.first + dy[dir];
			int Next_X = pos.second + dx[dir];

			// û������ ���� ������ ������ �̵�
			if (!Map[Next_Y][Next_X]) {
				pos.first = Next_Y;
				pos.second = Next_X;
				break;
			}

			// �� ���� �� û���� ������ �ƴѰ��(û�Ұ� �̹� �Ǿ��ְų� ��)
			if (i == 4) {
				//������ ����(ȸ���� ���� ����)�� ��ġ
				int Back_dir = (dir + 2) % 4;
				int Back_Y = pos.first + dy[Back_dir];
				int Back_X = pos.second + dx[Back_dir];

				// �ڰ� ���� ��� -> ��
				if (Map[Back_Y][Back_X] == 1) {
					printf("%d", res);
					return 0;
				}
				else {// �ڰ� ���� �ƴѰ�� -> ����
					pos.first = Back_Y;
					pos.second = Back_X;
				}
			}
		}
	}
	return 0;
}