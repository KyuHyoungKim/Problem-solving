#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 }, res = 0;
	char dir[2][5] = { {'D','L','U','R'}, {'U','R','D','L'} };
	scanf("%d %d", &N, &M);
	vector<string> map(N);
	vector<vector<bool>> checked(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++) {
		char input[1001];
		scanf("%s", input);
		map[i] = input;
	}
	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (checked[i][j]) continue;

			stack<pair<int, int>> st;
			st.push(make_pair(i, j));
			checked[i][j] = true;
			while (!st.empty()) {
				int Y_now = st.top().first;
				int X_now = st.top().second;
				char val = map[Y_now][X_now];
				st.pop();
				for (int n = 0; n < 4; n++) {
					int Y = Y_now + dy[n];
					int X = X_now + dx[n];
					if (Y < 0 || Y >= N || X < 0 || X >= M || checked[Y][X]) 
						continue;
					
					if (map[Y][X] == dir[0][n] || val == dir[1][n]) {
						st.push(make_pair(Y, X));
						checked[Y][X] = true;
					}
				}
			}
			res++;
		}
	printf("%d", res);
	return 0;
}