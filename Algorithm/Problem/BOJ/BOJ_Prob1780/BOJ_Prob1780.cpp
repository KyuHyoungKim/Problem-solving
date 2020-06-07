#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
void find_paper(vector<vector<int>>& paper, int start_x, int start_y, int len, int res[3]) {
	int value = paper[start_y][start_x];
	int i, j;
	if (len == 1) {
		res[value + 1]++;
		return;
	}
	for (i = start_y; i < start_y+len; i++)
		for (j = start_x; j < start_x + len; j++) {
			if (paper[i][j] != value) {
				len /= 3;
				for (int a = 0; a < 3; a++)
					for (int b = 0; b < 3; b++)
						find_paper(paper, start_x + a * len, start_y + b * len, len, res);
				return;
			}
		}
	res[value + 1]++;
	return;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N, res[3] = { 0 };
	scanf("%d", &N);
	vector<vector<int>> paper(N, vector<int>(N));
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			scanf("%d", &paper[i][j]);
	find_paper(paper, 0, 0, N, res);
	printf("%d\n%d\n%d\n", res[0], res[1], res[2]);
	return 0;
}