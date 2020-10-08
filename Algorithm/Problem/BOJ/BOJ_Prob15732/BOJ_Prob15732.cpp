#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

class rule_info {
public:
	int start, end, interval;
};
int main() {
	freopen("input.txt", "r", stdin);

	int N, K, D, res;
	int left, right, mid;
	scanf("%d %d %d", &N, &K, &D);
	vector<rule_info> rules(K);
	for (int i = 0; i < K; i++)
		scanf("%d %d %d", &rules[i].start, &rules[i].end, &rules[i].interval);

	left = 1;
	right = N;
	while (left <= right) {
		int cnt = 0;
		mid = (left + right) / 2;

		for (int i = 0; i < K; i++) {
			if (rules[i].start > mid)
				continue;
			if (rules[i].end <= mid)
				cnt += 1 + (rules[i].end - rules[i].start) / rules[i].interval;
			else
				cnt += 1 + (mid - rules[i].start) / rules[i].interval;

			if (cnt >= D)
				break;
		}

		if (cnt >= D) {
			right = mid - 1;
			res = mid;
		}
		else
			left = mid + 1;
	}

	printf("%d", res);
	return 0;
}