#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, M, T;

void rotate(vector<vector<int>>& plates, int x, int dir, int k);
void check(vector<vector<int>>& plates);

int main() {
	freopen("input.txt", "r", stdin);

	int res = 0;
	scanf("%d %d %d", &N, &M, &T);
	vector<vector<int>> plates(N + 1, vector<int>(M));
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &plates[i][j]);
	for (int i = 0; i < T; i++) {
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		rotate(plates, x, d, k);
		check(plates);
	}
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			res += plates[i][j];

	printf("%d", res);
	return 0;
}

void rotate(vector<vector<int>>& plates, int x, int dir, int k) {
	for (int i = x; i <= N; i += x) {
		vector<int> temp = plates[i];
		if (dir)
			for (int j = 0; j < M; j++)
				plates[i][j] = temp[(j + k) % M];
		else
			for (int j = M - 1; j >= 0; j--)
				plates[i][j] = temp[(j + M - k) % M];
	}
}

void check(vector<vector<int>>& plates) {
	int sum = 0, cnt = 0;
	bool flag = true;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++) {
			if (!plates[i][j])
				continue;
			int num = plates[i][j];
			sum += num;
			cnt++;
			queue<pair<int, int>> q;

			if (i + 1 <= N && num == plates[i + 1][j]) {
				q.push(make_pair(i + 1, j));
				plates[i][j] = plates[i + 1][j] = 0;
			}
			if (i - 1 > 0 && num == plates[i - 1][j]) {
				q.push(make_pair(i - 1, j));
				plates[i][j] = plates[i - 1][j] = 0;
			}
			if (num == plates[i][(j + 1) % M]) {
				q.push(make_pair(i, (j + 1) % M));
				plates[i][j] = plates[i][(j + 1) % M] = 0;
			}
			if (num == plates[i][(j + M - 1) % M]) {
				q.push(make_pair(i, (j + M - 1) % M));
				plates[i][j] = plates[i][(j + M - 1) % M] = 0;
			}

			while (!q.empty()) {
				flag = false;
				int Y = q.front().first;
				int X = q.front().second;
				q.pop();
				if (Y + 1 <= N && num == plates[Y + 1][X]) {
					q.push(make_pair(Y + 1, X));
					plates[Y + 1][X] = 0;
				}
				if (Y - 1 > 0 && num == plates[Y - 1][X]) {
					q.push(make_pair(Y - 1, X));
					plates[Y - 1][X] = 0;
				}
				if (num == plates[Y][(X + 1) % M]) {
					q.push(make_pair(Y, (X + 1) % M));
					plates[Y][(X + 1) % M] = 0;
				}
				if (num == plates[Y][(X + M - 1) % M]) {
					q.push(make_pair(Y, (X + M - 1) % M));
					plates[Y][(X + M - 1) % M] = 0;
				}
			}
		}

	if (flag) {
		float avg = (float)sum / cnt;
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < M; j++) {
				if (!plates[i][j]) continue;
				if (plates[i][j] > avg)
					plates[i][j]--;
				else if (plates[i][j] < avg)
					plates[i][j]++;
			}
	}
}