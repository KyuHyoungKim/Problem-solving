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
	bool flag = false; // 턴을 끝낼 것인지 확인하기 위한 boolean 변수
	scanf("%d %d", &N, &K);
	vector<vector<int>> board(N + 2, vector<int>(N + 2));
	// 게임 판의 각 칸마다의 색을 저장하기 위한 2차원 벡터
	// N+2개인 이유 :	1. 주어지는 데이터상 인덱스를 0부터가 아닌 1부터 사용하는 것이 편할 것 같아 +1
	//					2. 인덱스를 초과하는 경우를 따로 처리하는 것 보다 1줄을 더 추가하는 것이 더 편할 것 같아 +1
	// Value 0 : 흰색, 1 : 빨간색, 2 : 파란색
	vector<vector<stack<int>>> unit_stack(N + 1, vector<stack<int>>(N + 1));
	// 각 칸마다 쌓인 말을 저장하기 위한 2차원 스택 벡터
	vector<unit> units(K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &board[i][j]);
	for (int i = 0; i <= N + 1; i++) {
		//게임 판을 넘어가는 경우 (index : 0 || N + 1) 파란색 칸으로 처리
		board[0][i] = 2;
		board[i][0] = 2;
		board[N + 1][i] = 2;
		board[i][N + 1] = 2;
	}
	for (int i = 0; i < K; i++) {
		int y, x; // units 벡터 안에 저장하면서 unit_stack에 쌓을 때 편하려고 따로 변수로 지정
		scanf("%d %d %d", &y, &x, &units[i].dir);
		units[i].y = y;
		units[i].x = x;
		unit_stack[y][x].push(i);
	}

	while (!flag) {
		res++; // 턴수 +1
		if (res > 1000) { // 턴수가 1000이 넘어가거나 끝낼 수 없는 경우 처리
			res = -1;
			break;
		}

		bool blue_flag = false; // 파란색칸을 만날 때 이동하지 않고 넘어가는 경우를 처리하기위한 boolean 변수
		for (int i = 0; i < K; i++) {
			int Y = units[i].y;
			int X = units[i].x;
			int Y_next = Y + dy[units[i].dir];
			int X_next = X + dx[units[i].dir];

			if (board[Y_next][X_next] == 2) { // 파란색칸
				if (blue_flag) { // 앞뒤로 파란색인 경우
					blue_flag = false;
					continue;
				}

				// 방향 바꾸고 blue_flag를 true처리한 후 이동할 칸의 색을 다시 확인하기위해 for문의 처음으로
				if (units[i].dir % 2) 
					units[i].dir++;
				else
					units[i].dir--;
				i--;
				blue_flag = true;
				continue;
			}
			else if (board[Y_next][X_next] == 1) { // 빨간색 칸
				queue<int> q;
				while (unit_stack[Y][X].top() != i) {
					// 차례인 말이 나올 때 까지 stack에서 꺼내서 queue에 삽입
					q.push(unit_stack[Y][X].top());
					unit_stack[Y][X].pop();
				}
				// 차례인 말 꺼내서 queue에 삽입
				q.push(unit_stack[Y][X].top());
				unit_stack[Y][X].pop();
				while (!q.empty()) {
					// queue에 있는 것 전부 꺼내서 unit_stack에 다시 쌓음
					int moved_unit = q.front();
					q.pop();
					
					unit_stack[Y_next][X_next].push(moved_unit);
					units[moved_unit].y = Y_next;
					units[moved_unit].x = X_next;
				}
			}
			else { // 흰색 칸
				stack<int> q;
				while (unit_stack[Y][X].top() != i) {
					// 차례인 말이 나올 때 까지 stack에서 꺼내서 임시 stack에 쌓음
					q.push(unit_stack[Y][X].top());
					unit_stack[Y][X].pop();
				}
				// 차례인 말을 꺼내서 임시 stack에 쌓음
				q.push(unit_stack[Y][X].top());
				unit_stack[Y][X].pop();

				while (!q.empty()) {
					// 임시 stack에 있는 것 전부 꺼내서 unit_stack에 다시 쌓음
					int moved_unit = q.top();
					q.pop();

					unit_stack[Y_next][X_next].push(moved_unit);
					units[moved_unit].y = Y_next;
					units[moved_unit].x = X_next;
				}
			}
			blue_flag = false; // blue_flag 초기화

			if (unit_stack[units[i].y][units[i].x].size() >= 4) {// 게임 종료 조건
				flag = true;
				break;
			}
		}
	}

	printf("%d", res);
	return 0;
}