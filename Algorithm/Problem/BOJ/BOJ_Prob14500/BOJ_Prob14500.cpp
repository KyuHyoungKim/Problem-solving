#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;



int main() {
	freopen("input.txt", "r", stdin);
	int N, M, res = 0, temp = 0;
	scanf("%d %d", &N, &M);
	vector<vector<int>> scores(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &scores[i][j]);
	// bar
	// o o o o
	for (int i = 0; i <= N - 1; i++)
		for (int j = 0; j <= M - 4; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i][j + 2] + scores[i][j + 3];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o
	// o
	// o
	// o
	for (int i = 0; i <= N - 4; i++)
		for (int j = 0; j <= M - 1; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i + 2][j] + scores[i + 3][j];
			if (temp > res) res = temp;
			temp = 0;
		}

	// square
	// o o
	// o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i][j + 1] + scores[i + 1][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}

	// green block
	// o
	// o o
	//   o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i + 1][j + 1] + scores[i + 2][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	//   o
	// o o
	// o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j + 1] + scores[i + 1][j + 1] + scores[i + 1][j] + scores[i + 2][j];
			if (temp > res) res = temp;
			temp = 0;
		}
	//   o o
	// o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i + 1][j] + scores[i + 1][j + 1] + scores[i][j + 1] + scores[i][j + 2];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o o
	//   o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i + 1][j + 1] + scores[i + 1][j + 2];
			if (temp > res) res = temp;
			temp = 0;
		}

	// orange block
	// o
	// o
	// o o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i + 2][j] + scores[i + 2][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	//   o
	//   o
	// o o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j + 1] + scores[i + 1][j + 1] + scores[i + 2][j + 1] + scores[i + 2][j];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o o
	//   o
	//   o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i + 1][j + 1] + scores[i + 2][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o o
	// o
	// o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i + 1][j] + scores[i + 2][j];
			if (temp > res) res = temp;
			temp = 0;
		}

	//     o
	// o o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i + 1][j] + scores[i + 1][j + 1] + scores[i + 1][j + 2] + scores[i][j + 2];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o
	// o o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i + 1][j + 1] + scores[i + 1][j + 2];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o o o
	// o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i][j + 2] + scores[i + 1][j];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o o o
	//     o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i][j + 2] + scores[i + 1][j + 2];
			if (temp > res) res = temp;
			temp = 0;
		}

	// purple block
	// o o o
	//   o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i][j] + scores[i][j + 1] + scores[i][j + 2] + scores[i + 1][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	//   o
	// o o o
	for (int i = 0; i <= N - 2; i++)
		for (int j = 0; j <= M - 3; j++) {
			temp = scores[i + 1][j] + scores[i + 1][j + 1] + scores[i + 1][j + 2] + scores[i][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	//   o
	// o o
	//   o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j + 1] + scores[i + 1][j + 1] + scores[i + 2][j + 1] + scores[i + 1][j];
			if (temp > res) res = temp;
			temp = 0;
		}
	// o
	// o o
	// o
	for (int i = 0; i <= N - 3; i++)
		for (int j = 0; j <= M - 2; j++) {
			temp = scores[i][j] + scores[i + 1][j] + scores[i + 2][j] + scores[i + 1][j + 1];
			if (temp > res) res = temp;
			temp = 0;
		}
	printf("%d\n", res);
	return 0;
}