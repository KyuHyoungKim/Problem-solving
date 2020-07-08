#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<string> res;
vector<vector<int>> bit_check(3, vector<int>(9)); // horizontal, vertical, box
vector<string> sudoku(9);
vector<pair<int, int>> blank;

bool solve_sudoku(int cnt) {
	if (cnt == blank.size()) {
		res = sudoku;
		return true;
	}
	int y = blank[cnt].first, x = blank[cnt].second, box = y - y % 3 + x / 3;
	bool a = false;
	for (int i = 1; i <= 9 && !a; i++) {
		if (bit_check[0][y] & 1 << i || bit_check[1][x] & 1 << i || bit_check[2][box] & 1 << i) continue;
		bit_check[0][y] |= 1 << i;
		bit_check[1][x] |= 1 << i;
		bit_check[2][box] |= 1 << i;
		sudoku[y][x] = i + '0';
		a = solve_sudoku(cnt + 1);
		bit_check[0][y] -= 1 << i;
		bit_check[1][x] -= 1 << i;
		bit_check[2][box] -= 1 << i;
		sudoku[y][x] = '0';
	}
	return a;
}
int main() {
	freopen("input.txt", "r", stdin);
	for (int i = 0; i < 9; i++) {
		char input[10];
		scanf("%s", input);
		sudoku[i] = input;
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == '0') blank.push_back(make_pair(i, j));
			else {
				bit_check[0][i] |= 1 << (sudoku[i][j] - '0');
				bit_check[1][j] |= 1 << (sudoku[i][j] - '0');
				bit_check[2][i - i % 3 + j / 3] |= 1 << (sudoku[i][j] - '0');
			}
		}
	}
	solve_sudoku(0);
	for (int i = 0; i < 9; i++)
		printf("%s\n", res[i].c_str());

	return 0;
}