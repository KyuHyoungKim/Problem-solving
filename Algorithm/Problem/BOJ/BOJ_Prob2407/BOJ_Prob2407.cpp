#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string dp[100][100];



string string_sum(string a, string b) {
	int ten = 0;
	int num1, num2, sum;
	int len = (a.size() > b.size()) ? a.size() : b.size();
	string ret;
	for (int i = 0; i < len; i++) {
		num1 = num2 = 0;
		if (!a.empty()) {
			num1 = a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			num2 = b.back() - '0';
			b.pop_back();
		}

		sum = num1 + num2 + ten;
		ret = to_string(sum % 10) + ret;
		ten = sum / 10;
	}
	if (ten) ret = '1' + ret;
	return ret;
}

string combination(int n, int r) {
	string ret;

	if (!dp[n][r].empty())
		return dp[n][r];

	if (n == r || r == 0)
	{
		dp[n][r] = "1";
		return "1";
	}
	ret = string_sum(combination(n - 1, r), combination(n - 1, r - 1));
	dp[n][r] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);

	cout << combination(N, M);
	return 0;
}