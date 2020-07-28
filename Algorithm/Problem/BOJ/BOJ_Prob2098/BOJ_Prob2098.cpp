#define _CRT_SECURE_NO_WARNINGS
#define INF 123456789
#include <cstdio>
#include <vector>
using namespace std;
int N, graph[16][16] = { 0 }, DP[1<<16][16];

int traverse(int checked, int pos) {
	if (checked == (1 << N) - 1) {
		if (graph[pos][0]) return graph[pos][0];
		return INF;
	}
	if (DP[checked][pos]) return DP[checked][pos];

	int ret = INF, a;
	for (int i = 0; i < N; i++) {
		if (checked & 1<<i || !graph[pos][i]) continue;
		a = traverse(checked | 1 << i, i) + graph[pos][i];
		if (ret > a) ret = a;
	}
	DP[checked][pos] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &graph[i][j]);

	printf("%d", traverse(1, 0));

	return 0;
}