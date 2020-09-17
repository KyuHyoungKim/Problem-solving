#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, B, C;
	long long res = 0;
	scanf("%d", &N);
	vector<int> nums(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	scanf("%d %d", &B, &C);
	
	for (int i = 0; i < N; i++) {
		res++;
		nums[i] -= B;
		if (nums[i] > 0) {
			res += nums[i] / C;
			if (nums[i] % C)
				res++;
		}
	}

	printf("%lld", res);
	return 0;
}