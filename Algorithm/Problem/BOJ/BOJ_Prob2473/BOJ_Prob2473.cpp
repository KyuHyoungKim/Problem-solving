#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, res[3] = { 0 };
	long long min_sum = 123456789123456789;
	scanf("%d", &N);
	vector<int> solutions(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &solutions[i]);
	sort(solutions.begin(), solutions.end());
	for (int i = 0; i < N - 2; i++) {
		int j = i + 1, k = N - 1;
		while (j < k) {
			long long sum = (long long)solutions[i] + solutions[j] + solutions[k];
			if (abs(sum) < min_sum) {
				min_sum = abs(sum);
				res[0] = solutions[i];
				res[1] = solutions[j];
				res[2] = solutions[k];
			}
			if (sum < 0) j++;
			else if (sum > 0) k--;
			else break;
		}
		if (!min_sum) break;
	}
	printf("%d %d %d", res[0], res[1], res[2]);
	return 0;
}