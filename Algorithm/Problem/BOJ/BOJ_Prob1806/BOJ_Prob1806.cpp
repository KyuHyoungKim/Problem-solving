#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, S, sum = 0, res = 100000000;
	scanf("%d %d", &N, &S);
	vector<int> nums(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0, j = 0; i < N && j < N;) {
		if (sum < S) {
			sum += nums[j];
			j++;
		}
		while (sum >= S) {
			if (j - i < res) res = j - i;
			sum -= nums[i];
			i++;
		}
	}
	if (res == 100000000) res = 0;
	printf("%d\n", res);
	return 0;
}