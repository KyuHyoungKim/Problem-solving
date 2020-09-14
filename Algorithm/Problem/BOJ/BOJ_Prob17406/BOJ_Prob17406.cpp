#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <cstdio>
#include <vector>
using namespace std;

int N, M, K;
vector<vector<int>> mat_origin;
vector<vector<int>> inputs;

void init();
vector<vector<int>> rotate(vector<vector<int>> mata, int r, int c, int s);
int sol(vector<vector<int>> Mat, int cnt, int checked);

int main() {
	freopen("input.txt", "r", stdin);
	init();
	int res = sol(mat_origin, 0, 0);
	printf("%d", res);
	return 0;
}

void init() {
	scanf("%d %d %d", &N, &M, &K);
	vector<vector<int>> mat_init(N + 1, vector<int>(M + 1));
	vector<vector<int>> inputs_init(K, vector<int>(3));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			scanf("%d", &mat_init[i][j]);
	for (int i = 0; i < K; i++)
		scanf("%d %d %d", &inputs_init[i][0], &inputs_init[i][1], &inputs_init[i][2]);
	mat_origin.swap(mat_init);
	inputs.swap(inputs_init);
}


vector<vector<int>> rotate(vector<vector<int>> Mat, int r, int c, int s) {
	pair<int, int> p1 = make_pair(r - s, c - s);
	pair<int, int> p2 = make_pair(r + s, c + s);
	for (int n = 0; 2 * n < p2.second - p1.second && n < p2.first - p1.first; n++) {
		int st = Mat[p1.first + n][p1.second + n];

		for (int i = p1.first + n; i < p2.first - n; i++)
			Mat[i][p1.second + n] = Mat[i + 1][p1.second + n];

		for (int i = p1.second + n; i < p2.second - n; i++)
			Mat[p2.first - n][i] = Mat[p2.first - n][i + 1];

		for (int i = p2.first - n; i > p1.first + n; i--)
			Mat[i][p2.second - n] = Mat[i - 1][p2.second - n];

		for (int i = p2.second - n; i > p1.second + n + 1; i--)
			Mat[p1.first + n][i] = Mat[p1.first + n][i - 1];
		Mat[p1.first + n][p1.second + n + 1] = st;
	}

	return Mat;
}

int sol(vector<vector<int>> Mat, int cnt, int checked) {
	int ret = INF, a;
	if (cnt == K)
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++)
				sum += Mat[i][j];
			if (sum < ret)
				ret = sum;
		}
	else
		for (int i = 0; i < K; i++) {
			if (checked & 1 << i)
				continue;

			a = sol(rotate(Mat, inputs[i][0], inputs[i][1], inputs[i][2]), cnt + 1, checked | 1 << i);
			if (ret > a)
				ret = a;
		}
	return ret;
}