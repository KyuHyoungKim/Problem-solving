#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	vector<vector<int>> mat[2];
	for (int i = 0; i < 2; i++) {
		int row, col;
		scanf("%d %d", &row, &col);
		mat[i].resize(row);
		for (int r = 0; r < row; r++) {
			mat[i][r].resize(col);
			for (int c = 0; c < col; c++) {
				scanf("%d", &mat[i][r][c]);
			}
		}
	}

	vector<vector<int>> res(mat[0].size(), vector<int>(mat[1][0].size()));
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			for (int k = 0; k < mat[1].size(); k++)
				res[i][j] += mat[0][i][k] * mat[1][k][j];
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}