#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

vector<int> opers(4), nums;
int N;
int minimum = 1234567891;
int maximum = -minimum;

void sol(int idx, int res);
int operate(int num1, int num2, int oper);

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	nums.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++)
		scanf("%d", &opers[i]);
	sol(1, nums[0]);
	printf("%d\n%d", maximum, minimum);
	return 0;
}

void sol(int idx, int res) {
	if (idx >= N) {
		if (res > maximum) maximum = res;
		if (res < minimum) minimum = res;
	}
	for (int i = 0; i < 4; i++) {
		int res_next;
		if (!opers[i]) continue;
		opers[i]--;
		sol(idx + 1, operate(res, nums[idx], i));
		opers[i]++;
	}
}

int operate(int num1, int num2, int oper) {
	if (oper == 0)
		return num1 + num2;
	else if (oper == 1)
		return num1 - num2;
	else if (oper == 2)
		return num1 * num2;
	else
		return num1 / num2;
}