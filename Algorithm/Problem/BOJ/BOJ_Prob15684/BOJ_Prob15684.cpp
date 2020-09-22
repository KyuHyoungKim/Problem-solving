#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, H, res = INF;
vector<pair<int, int>> lines;
vector<vector<int>> state;
vector<bool> visited;
bool check();
int find_num(int height, int line);
void num_change(int num1, int num2, int start);
vector<bool> visit(int line_idx);

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d %d %d", &N, &M, &H);
	lines.resize(M);
	visited.resize(H * (N - 1));
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &lines[i].first, &lines[i].second);
		lines[i].first--;
		lines[i].second--;
		visit(lines[i].second * H + lines[i].first);
	}
	state.resize(N);
	for (int i = 0; i < N; i++) {
		state[i].resize(H);
		for (int j = 0; j < H; j++)
			state[i][j] = i;
	}

	for (int i = 0; i < M; i++) {
		int num1 = find_num(lines[i].first, lines[i].second);
		int num2 = find_num(lines[i].first, lines[i].second + 1);
		for (int j = lines[i].first; j < H; j++)
			swap(state[num1][j], state[num2][j]);
	}

	if (check())
		res = 0;
	else
	{
		int idx_max = H * (N - 1);
		for (int i = 0; i < idx_max; i++) {
			if (visited[i])
				continue;

			int height_i = i % H;
			int line_i = i / H;
			int num1_i = find_num(height_i, line_i);
			int num2_i = find_num(height_i, line_i + 1);
			int cnt = 1;
			vector<bool> visited_i = visit(i);

			num_change(num1_i, num2_i, height_i);

			for (int j = i; j < idx_max; j++) {
				bool flag_j = false;
				vector<bool> visited_j;
				int height_j = j % H;
				int line_j = j / H;
				int num1_j = find_num(height_j, line_j);
				int num2_j = find_num(height_j, line_j + 1);
				if (!visited[j]) {
					cnt++;
					num_change(num1_j, num2_j, height_j);
					flag_j = true;
					visited_j = visit(j);
				}
				for (int k = j; k < idx_max; k++) {
					bool flag_k = false;
					vector<bool> visited_k;
					int height_k = k % H;
					int line_k = k / H;
					int num1_k = find_num(height_k, line_k);
					int num2_k = find_num(height_k, line_k + 1);
					if (!visited[k]) {
						cnt++;
						num_change(num1_k, num2_k, height_k);
						flag_k = true;
						visited_k = visit(k);
					}

					if (res > cnt && check()) {
						res = cnt;
					}

					if (flag_k) {
						num_change(num1_k, num2_k, height_k);
						visited[k] = false;
						if (visited_k[0])
							visited[k - H] = false;
						if (visited_k[1])
							visited[k + H] = false;
						cnt--;
					}
				}

				if (flag_j) {
					num_change(num1_j, num2_j, height_j);
					visited[j] = false;
					if (visited_j[0])
						visited[j - H] = false;
					if (visited_j[1])
						visited[j + H] = false;
					cnt--;
				}
			}
			num_change(num1_i, num2_i, height_i);
			visited[i] = false;
			if (visited_i[0])
				visited[i - H] = false;
			if (visited_i[1])
				visited[i + H] = false;

		}
	}
	if (res == INF)
		res = -1;

	printf("%d", res);
	return 0;
}

bool check() {
	int ret = true;
	for (int j = 0; j < N; j++)
		if (state[j][H - 1] != j) {
			ret = false;
			break;
		}
	return ret;
}

int find_num(int height, int line) {
	for (int j = 0; j < N; j++)
		if (state[j][height] == line) {
			return j;
		}
	return -1;
}

void num_change(int num1, int num2, int start) {
	for (int i = start; i < H; i++)
		swap(state[num1][i], state[num2][i]);
}

vector<bool> visit(int line_idx) {
	vector<bool> ret(2, false);
	visited[line_idx] = true;
	if (line_idx >= H && !visited[line_idx - H]) {
		visited[line_idx - H] = true;
		ret[0] = true;
	}
	if (line_idx + H < H * (N - 1) && !visited[line_idx + H]) {
		visited[line_idx + H] = true;
		ret[1] = true;
	}
	return ret;
}