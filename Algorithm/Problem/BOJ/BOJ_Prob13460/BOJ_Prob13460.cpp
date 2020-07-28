#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, M, dy[4] = { 0, 0, -1, 1 }, dx[4] = { -1, 1, 0, 0 };
// ¿Þ , ¿À , À§, ¾Æ·¡
class board_info {
public:
	vector<string> board;
	int ball_pos[2][2]; // R : 0, B : 1
	int result = 0;
};

board_info move(board_info info, int direction) {
	int st = 0, en = 1;

	if (info.ball_pos[0][0] == info.ball_pos[1][0] && 
		(direction == 0 && info.ball_pos[0][1] > info.ball_pos[1][1] 
			|| direction == 1 && info.ball_pos[0][1] < info.ball_pos[1][1]))
		swap(st, en);

	if (info.ball_pos[0][1] == info.ball_pos[1][1] && 
		(direction == 2 && info.ball_pos[0][0] > info.ball_pos[1][0] ||
			direction == 3 && info.ball_pos[0][0] < info.ball_pos[1][0]))
		swap(st, en);

	for (int i = st, k = en - st; ; i += k) {
		int Y = info.ball_pos[i][0];
		int X = info.ball_pos[i][1];
		while (1) {
			int Y_new = Y + dy[direction], X_new = X + dx[direction];
			if (Y_new < 0 || Y_new >= N || X_new < 0 || X_new >= M) break;
			if (info.board[Y_new][X_new] == 'O') {
				if (i == 0)
				{
					info.result = 1;
					info.board[Y][X] = '.';
					break;
				}
				else
				{
					info.result = -1;
					return info;
				}
			}
			if (info.board[Y_new][X_new] != '.') break;
			swap(info.board[Y][X], info.board[Y_new][X_new]);
			Y = Y_new;
			X = X_new;
		}
		info.ball_pos[i][0] = Y;
		info.ball_pos[i][1] = X;
		if (i == en) break;
	}

	return info;
}
int play_game(board_info info, int cnt, int prev_dir) {
	if (cnt == 10) return 100;
	int ret = 100, a;
	for (int i = 0; i < 4; i++) {
		if (prev_dir == i) continue;

		board_info info_new = move(info, i);
		if (info_new.result != 0) {
			if (info_new.result < 0) continue;
			if (info_new.result > 0) {
				return cnt + 1;
			}
		}
		a = play_game(info_new, cnt + 1, i);
		if (a < ret) ret = a;
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	board_info info;
	vector<string> board(N);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
		int R = board[i].find('R');
		int B = board[i].find('B');
		if (R >= 0) {
			info.ball_pos[0][0] = i;
			info.ball_pos[0][1] = R;
		}
		if (B >= 0) {
			info.ball_pos[1][0] = i;
			info.ball_pos[1][1] = B;
		}
	}
	info.board = board;

	int res = play_game(info, 0, -1);
	if (res == 100) printf("-1");
	else printf("%d", res);

	return 0;
}