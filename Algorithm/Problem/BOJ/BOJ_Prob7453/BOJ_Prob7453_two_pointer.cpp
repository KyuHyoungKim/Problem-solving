#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	long long res = 0;
	scanf("%d", &N);
	vector<vector<int>> arrays(4, vector<int>(N));
	vector<int>ABsum(N * N), CDsum(N * N);

	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &arrays[0][i], &arrays[1][i], &arrays[2][i], &arrays[3][i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			ABsum[i * N + j] = arrays[0][i] + arrays[1][j];
			CDsum[i * N + j] = arrays[2][i] + arrays[3][j];
		}

	sort(ABsum.begin(), ABsum.end());
	sort(CDsum.begin(), CDsum.end());
	
	for (int AB = 0, CD = N * N - 1; AB < N * N && CD >= 0;) {
		int sum = ABsum[AB] + CDsum[CD];
		if (!sum) {
			int initial = AB;
			long long ABcnt = 0, CDcnt = 0;

			while (AB < N * N && ABsum[initial] == ABsum[AB]) {
				ABcnt++;
				AB++;
			}

			initial = CD;
			while (CD >= 0 && CDsum[initial] == CDsum[CD]) {
				CDcnt++;
				CD--;
			}

			res += ABcnt * CDcnt;
		}
		else if (sum < 0) AB++;
		else if (sum > 0) CD--;
	}

	printf("%lld", res);
	return 0;
}