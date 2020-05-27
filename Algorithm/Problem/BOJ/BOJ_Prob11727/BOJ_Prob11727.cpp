#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
string dp[256] = { "1", "1", "3" };
string string_sum(string a, string b) {
	string ret;
	int len = (a.size() >= b.size()) ? a.size() : b.size();
	int ten = 0, num1 = 0, num2 = 0, sum = 0;
	for (int i = 0; i < len; i++) {
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
string tiling(int N) {
	if (!dp[N].empty()) return dp[N];
	dp[N] = string_sum(string_sum(tiling(N - 2), tiling(N - 2)), tiling(N - 1));
	return dp[N];
}
int main() {
	int N = 0, res = 0;
	string input;
	while (1) {
		getline(cin, input);
		if (input.empty()) break;
		N = stoi(input);
		cout << tiling(N) << '\n';
	}
	return 0;
}