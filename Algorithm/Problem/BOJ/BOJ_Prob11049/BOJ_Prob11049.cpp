#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int DP[501][501] = { 0 };
vector<pair<int, int>> matrixes;

int sol(int start, int end) {
	int ret = 1234567891, a;
	if (DP[start][end]) return DP[start][end];
	if (start >= end) return 0;

	for (int i = start; i < end; i++) {
		a = sol(start, i)
			+ sol(i + 1, end)
			+ matrixes[start].first * matrixes[i].second * matrixes[end].second;
		if (a < ret) ret = a;
	}
	DP[start][end] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	matrixes.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &matrixes[i].first, &matrixes[i].second);

	printf("%d", sol(0, N - 1));
	return 0;
}