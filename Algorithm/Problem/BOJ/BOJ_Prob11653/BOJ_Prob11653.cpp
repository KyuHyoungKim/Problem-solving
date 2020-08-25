#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> find_prime_nums(int N) {
	vector<bool> checked(N + 1);
	vector<int> ret;
	for (int i = 2; i <= (int)sqrt(N); i++) {
		if (checked[i]) continue;
		else ret.push_back(i);

		for (int j = 2; j * i <= N; j++)
			checked[i * j] = true;
	}
	return ret;
}
int main() {
	int N;
	vector<int> prime_nums;
	scanf("%d", &N);
	prime_nums = find_prime_nums(N);

	for (int idx = 0; idx < prime_nums.size() && N > 1;) {
		if (N % prime_nums[idx] == 0) {
			printf("%d\n", prime_nums[idx]);
			N /= prime_nums[idx];
		}
		else
			idx++;
	}

	if (N != 1)
		printf("%d", N);
	return 0;
}