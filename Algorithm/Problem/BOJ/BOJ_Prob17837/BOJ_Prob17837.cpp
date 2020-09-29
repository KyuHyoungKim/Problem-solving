#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct unit {
	int y;
	int x;
	int dir;
};

const int dy[5] = { 0,0,0,-1,1 }, dx[5] = { 0,1,-1,0,0 };

int main() {
	freopen("input.txt", "r", stdin);
	int N, K, res = 0;
	bool flag = false; // ���� ���� ������ Ȯ���ϱ� ���� boolean ����
	scanf("%d %d", &N, &K);
	vector<vector<int>> board(N + 2, vector<int>(N + 2));
	// ���� ���� �� ĭ������ ���� �����ϱ� ���� 2���� ����
	// N+2���� ���� :	1. �־����� �����ͻ� �ε����� 0���Ͱ� �ƴ� 1���� ����ϴ� ���� ���� �� ���� +1
	//					2. �ε����� �ʰ��ϴ� ��츦 ���� ó���ϴ� �� ���� 1���� �� �߰��ϴ� ���� �� ���� �� ���� +1
	// Value 0 : ���, 1 : ������, 2 : �Ķ���
	vector<vector<stack<int>>> unit_stack(N + 1, vector<stack<int>>(N + 1));
	// �� ĭ���� ���� ���� �����ϱ� ���� 2���� ���� ����
	vector<unit> units(K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
	for (int i = 0; i <= N + 1; i++) {
		//���� ���� �Ѿ�� ��� (index : 0 || N + 1) �Ķ��� ĭ���� ó��
		board[0][i] = 2;
		board[i][0] = 2;
		board[N + 1][i] = 2;
		board[i][N + 1] = 2;
	}
	for (int i = 0; i < K; i++) {
		int y, x; // units ���� �ȿ� �����ϸ鼭 unit_stack�� ���� �� ���Ϸ��� ���� ������ ����
		scanf("%d %d %d", &y, &x, &units[i].dir);
		units[i].y = y;
		units[i].x = x;
		unit_stack[y][x].push(i);
	}

	while (!flag) {
		res++; // �ϼ� +1
		if (res > 1000) { // �ϼ��� 1000�� �Ѿ�ų� ���� �� ���� ��� ó��
			res = -1;
			break;
		}

		bool blue_flag = false; // �Ķ���ĭ�� ���� �� �̵����� �ʰ� �Ѿ�� ��츦 ó���ϱ����� boolean ����
		for (int i = 0; i < K; i++) {
			int Y = units[i].y;
			int X = units[i].x;
			int Y_next = Y + dy[units[i].dir];
			int X_next = X + dx[units[i].dir];

			if (board[Y_next][X_next] == 2) { // �Ķ���ĭ
				if (blue_flag) { // �յڷ� �Ķ����� ���
					blue_flag = false;
					continue;
				}

				// ���� �ٲٰ� blue_flag�� trueó���� �� �̵��� ĭ�� ���� �ٽ� Ȯ���ϱ����� for���� ó������
				if (units[i].dir % 2) 
					units[i].dir++;
				else
					units[i].dir--;
				i--;
				blue_flag = true;
				continue;
			}
			else if (board[Y_next][X_next] == 1) { // ������ ĭ
				queue<int> q;
				while (unit_stack[Y][X].top() != i) {
					// ������ ���� ���� �� ���� stack���� ������ queue�� ����
					q.push(unit_stack[Y][X].top());
					unit_stack[Y][X].pop();
				}
				// ������ �� ������ queue�� ����
				q.push(unit_stack[Y][X].top());
				unit_stack[Y][X].pop();
				while (!q.empty()) {
					// queue�� �ִ� �� ���� ������ unit_stack�� �ٽ� ����
					int moved_unit = q.front();
					q.pop();
					
					unit_stack[Y_next][X_next].push(moved_unit);
					units[moved_unit].y = Y_next;
					units[moved_unit].x = X_next;
				}
			}
			else { // ��� ĭ
				stack<int> q;
				while (unit_stack[Y][X].top() != i) {
					// ������ ���� ���� �� ���� stack���� ������ �ӽ� stack�� ����
					q.push(unit_stack[Y][X].top());
					unit_stack[Y][X].pop();
				}
				// ������ ���� ������ �ӽ� stack�� ����
				q.push(unit_stack[Y][X].top());
				unit_stack[Y][X].pop();

				while (!q.empty()) {
					// �ӽ� stack�� �ִ� �� ���� ������ unit_stack�� �ٽ� ����
					int moved_unit = q.top();
					q.pop();

					unit_stack[Y_next][X_next].push(moved_unit);
					units[moved_unit].y = Y_next;
					units[moved_unit].x = X_next;
				}
			}
			blue_flag = false; // blue_flag �ʱ�ȭ

			if (unit_stack[units[i].y][units[i].x].size() >= 4) {// ���� ���� ����
				flag = true;
				break;
			}
		}
	}

	printf("%d", res);
	return 0;
}