#define _CRT_SECURE_NO_WARNINGS
#define INF 1234567891
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string str;
vector<vector<int>> Pelindrome_check;
vector<int> DP;
int check_palindrome(int start, int end) {
	if (start > end) 
		return 1;
	if (Pelindrome_check[start][end]) 
		return Pelindrome_check[start][end];

	int ret = 0;
	if (str[start] == str[end])
		ret = check_palindrome(start + 1, end - 1);
	else
		ret = -1;

	Pelindrome_check[start][end] = ret;
	return ret;
}
int split_palindrome(int start) {
	if (start == str.size()) return 0;
	if (DP[start]) return DP[start];
	int ret = INF, a;
	for (int i = start; i < str.size(); i++) {
		if (check_palindrome(start, i) < 0) continue;

		a = split_palindrome(i + 1);
		if (ret > a) ret = a;
	}
	DP[start] = ret + 1;
	return DP[start];
}
int main() {
	freopen("input.txt", "r", stdin);
	cin >> str;
	Pelindrome_check.resize(str.size(), vector<int>(str.size()));
	DP.resize(str.size());
	printf("%d", split_palindrome(0));
	return 0;
}