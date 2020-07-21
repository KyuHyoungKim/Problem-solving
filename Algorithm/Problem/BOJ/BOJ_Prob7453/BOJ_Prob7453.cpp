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
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &arrays[0][i], &arrays[1][i], &arrays[2][i], &arrays[3][i]);
	vector<int>sums(N * N);
	for (int i = 0, cnt = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int sum = arrays[0][i] + arrays[1][j];
			sums[cnt] = -sum;
			cnt++;
		}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int sum = arrays[2][i] + arrays[3][j];
			long long cnt = upper_bound(sums.begin(), sums.end(), sum) - lower_bound(sums.begin(), sums.end(), sum);
			res += cnt;
		}
			

	printf("%d", res);

	return 0;
}