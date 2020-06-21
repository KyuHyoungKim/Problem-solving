#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0, dx[3] = { 1, 1, 0 }, dy[3] = { 0, 1, 1 };
	scanf("%d", &N);
	vector<vector<int>> space(N, vector<int>(N));
	stack<vector<int>> st;
	// y_pos, x_pos, condition(0 : horizontal, 1 : digonal, 2: vertical)
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &space[i][j]);
	st.push({ 0,1,0 });
	while (!st.empty()) {
		int pos_y = st.top()[0];
		int pos_x = st.top()[1];
		int condition = st.top()[2];
		st.pop();
		int start, end;

		if (condition == 0) { start = 0; end = 2; }
		else if (condition == 1) { start = 0; end = 3; }
		else { start = 1; end = 3; }

		for (int i = start; i < end; i++) {
			int Y = pos_y + dy[i];
			int X = pos_x + dx[i];
			if (Y >= N || X >= N) continue;
			if (space[Y][X] || (i == 1 && (space[Y - 1][X] || space[Y][X - 1]))) continue;
			if (X == N - 1 && Y == N - 1) {
				res++;
				continue;
			}
			st.push({ Y,X,i });
		}
	}
	printf("%d\n", res);
	return 0;
}