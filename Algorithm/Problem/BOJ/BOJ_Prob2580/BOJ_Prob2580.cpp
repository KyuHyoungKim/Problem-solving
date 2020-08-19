#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> board(9, vector<int>(9));
vector<pair<int, int>> blanks;

bool solve(int cnt, vector<int> horizontal, vector<int> vertical, vector<int> square) {
	if (cnt == blanks.size())
		return true;
	int Y = blanks[cnt].first, X = blanks[cnt].second;
	bool check = false;
	for (int i = 1; i <= 9; i++) {
		if (horizontal[X] & 1 << i) continue;
		if (vertical[Y] & 1 << i) continue;
		if (square[(Y / 3) * 3 + X / 3] & 1 << i) continue;

		board[Y][X] = i;
		horizontal[X] |= 1 << i;
		vertical[Y] |= 1 << i;
		square[(Y / 3) * 3 + X / 3] |= 1 << i;
		check = solve(cnt + 1, horizontal, vertical, square);
		if (check) break;
		board[Y][X] = 0;
		horizontal[X] ^= 1 << i;
		vertical[Y] ^= 1 << i;
		square[(Y / 3) * 3 + X / 3] ^= 1 << i;
	}
	return check;
}

int main() {
	freopen("input.txt", "r", stdin);
	vector<int> horizontal(9), vertical(9), square(9);

	for(int i = 0 ; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			scanf("%d", &board[i][j]);
			if (!board[i][j]) {
				blanks.push_back(make_pair(i, j));
				continue;
			}

			horizontal[j] |= 1 << board[i][j];
			vertical[i] |= 1 << board[i][j];
			square[(i / 3)*3 + j / 3] |= 1 << board[i][j];
		}
	solve(0, horizontal, vertical, square);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
	return 0;
}