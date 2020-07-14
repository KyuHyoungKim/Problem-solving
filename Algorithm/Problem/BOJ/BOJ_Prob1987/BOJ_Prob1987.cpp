#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> board;
int R, C, dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
int alphabet(int checked, int y, int x) {
	int ret = 0, a = 0;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i], X = x + dx[i];
		if (Y < 0 || Y >= R || X < 0 || X >= C) continue;
		if (checked & 1 << (board[Y][X] - 'A')) continue;
		
		a = alphabet(checked | 1 << (board[Y][X] - 'A'), Y, X);
		if (a > ret) ret = a;
	}
	ret++;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d\n", &R, &C);
	board.resize(R);
	for (int i = 0; i < R; i++)
		getline(cin, board[i]);
	printf("%d", alphabet(1 << (board[0][0] - 'A'), 0, 0));
	return 0;
}