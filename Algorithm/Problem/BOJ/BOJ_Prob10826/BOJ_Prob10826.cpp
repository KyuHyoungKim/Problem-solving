#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
using namespace std;
string DP[1000001] = { "0", "1", "1" };

string string_sum(string a, string b) {
	string ret = "";
	long long sum = 0;
	int over = 0, string_size = 16;
	int a_st = a.size() - 16, a_cnt = 16;
	int b_st = b.size() - 16, b_cnt = 16;
	if (a_st < 0) {
		a_cnt = a.size();
		a_st = 0;
	}
	if (b_st < 0) {
		b_cnt = b.size();
		b_st = 0;
	}
	while (a_cnt > 0) {
		sum = over;
		string a_sub = a.substr(a_st, a_cnt);
		string b_sub = b.substr(b_st, b_cnt);

		if (a_st < a_cnt) {
			string_size = a_cnt;
			a_cnt = a_st;
			a_st = 0;
		}
		else a_st -= a_cnt;
		if (b_st < b_cnt) {
			b_cnt = b_st;
			b_st = 0;
		}
		else b_st -= b_cnt;

		if (!a_sub.empty())
			sum += stoll(a_sub);
		if (!b_sub.empty())
			sum += stoll(b_sub);
		over = sum / (long long)1e16;
		sum %= (long long)1e16;

		string sum_string = to_string(sum);
		while (sum_string.size() < string_size)
			sum_string = '0' + sum_string;

		ret = sum_string + ret;
	}
	if (over) ret = to_string(over) + ret;
	return ret;
}

string fibonacci(int n) {
	if (!DP[n].empty()) return DP[n];
	DP[n] = string_sum(fibonacci(n - 1), fibonacci(n - 2));
	return DP[n];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2000; i < n; i += 2000)
		fibonacci(i);
	printf("%s", fibonacci(n).c_str());
	return 0;
}