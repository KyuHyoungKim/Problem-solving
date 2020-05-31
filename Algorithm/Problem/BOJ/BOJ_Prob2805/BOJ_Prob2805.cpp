#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, start = 0, end = 0, mid = 0;
	scanf("%d %d", &N, &M);
	vector<long long> trees(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &trees[i]);
		if (end < trees[i]) end = trees[i];
	}
	while (start <= end) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid)
				sum = sum + (trees[i] - mid);
		}
		if (sum >= M)
			start = mid + 1;
		else
			end = mid - 1;
	}
	mid = (start + end) / 2;
	printf("%d\n", mid);
	return 0;
}