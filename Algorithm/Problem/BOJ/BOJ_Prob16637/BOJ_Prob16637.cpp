#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <iostream>
#include <vector>
using namespace std;

vector<int> nums;
string oper ="+";
int calc(int num1, int num2, int idx) {
	if (oper[idx] == '+')
		return num1 + num2;
	else if (oper[idx] == '-')
		return num1 - num2;
	else if (oper[idx] == '*')
		return num1 * num2;
	else if (num2 == 0)
		return -1234567891;
	else
		return num1 / num2;
}

int sol(int st, int end, int prev) {
	int ret = -INF, a1 = -INF, a2 = -INF;
	if (st > end)
		return prev;

	if (st < end)
		a1 = sol(st + 2, end, calc(prev, calc(nums[st], nums[st + 1], st + 1), st));
	a2 = sol(st + 1, end, calc(prev, nums[st],st));

	ret = (a1 > a2) ? a1 : a2;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, res = 0;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		char input;
		scanf("%c", &input);
		if (i % 2 == 0)
			nums.push_back(input - '0');
		else
			oper += input;
	}
	res = sol(0, nums.size() - 1, 0);
	printf("%d", res);
	return 0;
}