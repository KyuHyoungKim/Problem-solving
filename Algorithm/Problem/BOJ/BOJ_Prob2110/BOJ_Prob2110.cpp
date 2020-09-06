#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, C, left, right, mid, res = 0;
	scanf("%d %d", &N, &C);
	vector<int> pos(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &pos[i]);

	sort(pos.begin(), pos.end());
	left = 0;
	right = pos.back();

	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 1;
		int temp = pos[0];
		for (int i = 1; i < N; i++) {
			if (pos[i] < temp + mid)
				continue;
			temp = pos[i];
			cnt++;
		}

		if (cnt >= C) {
			left = mid + 1;
			if (res < mid)
				res = mid;
		}
		else
			right = mid - 1;
	}
	printf("%d", res);
	return 0;
}