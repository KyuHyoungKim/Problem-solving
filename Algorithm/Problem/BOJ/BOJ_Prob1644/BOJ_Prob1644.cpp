#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> find_prime_num(int max) {
	vector<int> ret;
	vector<bool> nums(max + 1, 1);
	for (int i = 2; i <= sqrt(max); i++) 
		if (nums[i])
			for (int j = 2; j * i <= max; j++)
				nums[i * j] = false;
	for (int i = 2; i <= max; i++)
		if (nums[i]) ret.push_back(i);
	return ret;
}
int main() {
	int N, res = 0;
	scanf("%d", &N);
	vector<int> prime_nums = find_prime_num(N);
	int sum = 0;
	int i = 0, j = 0;
	while (i < prime_nums.size() && j < prime_nums.size()) {
		while (sum < N) {
			sum += prime_nums[j];
			j++;
		}
		while (sum >= N) {
			if (sum == N) res++;
			sum -= prime_nums[i];
			i++;
		}
	}
	printf("%d\n",res);
	return 0;
}