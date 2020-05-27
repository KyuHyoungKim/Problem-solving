#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int K, N;
	int sum = 0;
	long long start = 1, end = 0, middle = 0;
	scanf("%d %d", &K, &N);
	vector<int> lan(K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &lan[i]);
		if (end < lan[i]) end = lan[i];
	}
	while (end - start >= 0) {
		middle = (end + start) / 2;
		sum = 0;
		for (int i = 0; i < K; i++) sum += lan[i] / middle;
		if (sum >= N) start = middle + 1;
		else end = middle - 1;
	}
	middle = (end + start) / 2;
	printf("%lld\n", middle);

	return 0;
}