#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N;
bool L_dir[20] = { 0 }, R_dir[20] = { 0 };
bool board[10][10] = { 0 };

int bishop(int Y, int X, int cnt, int color) {
	if (X >= N) {
		Y++;
		if (X%2) X = 0;
		else X = 1;
	}
	if (Y >= N) return cnt;
	int a1 = 0, a2 = 0, ret = 0;

	if (board[Y][X] && !L_dir[N -1 + Y - X] && !R_dir[Y + X]) {
		L_dir[N - 1 + Y - X] = R_dir[Y + X] = true;
		a1 = bishop(Y, X + 2, cnt + 1, color);
		L_dir[N - 1 + Y - X] = R_dir[Y + X] = false;
	}
	a2  = bishop(Y, X + 2, cnt, color);
	ret = (a1 > a2) ? a1 : a2;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int res = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	res += bishop(0, 0, 0, 0);
	res += bishop(0, 1, 0, 1);
	printf("%d", res);
	return 0;
}