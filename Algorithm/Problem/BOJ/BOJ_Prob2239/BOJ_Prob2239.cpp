#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> res;
bool check_horizon(vector<vector<int>>& sudoku, int y_pos, int value);
bool check_vertical(vector<vector<int>>& sudoku, int x_pos, int value);
bool check_block(vector<vector<int>>& sudoku, int y_pos, int x_pos, int value);
bool solve_sudoku(vector<vector<int>> sudoku, vector<pair<int,int>>& blank, int pos) {
	if (pos == blank.size()) {
		res = sudoku;
		return true;
	}
	int y = blank[pos].first, x = blank[pos].second;
	bool a = false;
	for (int i = 1; i <= 9 && !a; i++) {
		if (!check_horizon(sudoku, y, i) && !check_vertical(sudoku, x, i) && !check_block(sudoku, y, x, i)) {
			sudoku[y][x] = i;
			a = solve_sudoku(sudoku, blank, pos + 1);
			sudoku[y][x] = 0;
		}
	}
	return a;
}
int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> sudoku(9, vector<int>(9));
	vector<pair<int, int>> blank;
	for (int i = 0; i < 9; i++) {
		char input[10];
		scanf("%s", input);
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = input[j] - '0';
			if (!sudoku[i][j]) blank.push_back(make_pair(i, j));
		}
	}
	solve_sudoku(sudoku, blank, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d", res[i][j]);
		printf("\n");
	}
	return 0;
}

bool check_horizon(vector<vector<int>>& sudoku, int y_pos, int value) {
	for (int i = 0; i < 9; i++)
		if (sudoku[y_pos][i] == value)
			return true;
	return false;
}
bool check_vertical(vector<vector<int>>& sudoku, int x_pos, int value) {
	for (int i = 0; i < 9; i++)
		if (sudoku[i][x_pos] == value)
			return true;
	return false;
}
bool check_block(vector<vector<int>>& sudoku, int y_pos, int x_pos, int value) {
	int Y = y_pos - y_pos % 3, X = x_pos - x_pos % 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (sudoku[Y + i][X + j] == value)
				return true;
	return false;
}