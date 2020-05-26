#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	char str_input;
	while (1) {
		string str;
		while (1) {
			str_input = getchar();
			str += str_input;
			if (str_input == '.') break;
		}
		getchar();
		if (str[0] == '.') break;

		string ret = "yes";
		stack <char> check;

		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '(' || str[i] == '[') check.push(str[i]);
			else if (str[i] == ')') {
				if (check.empty() || check.top() != '(') {
					ret = "no";
					break;
				}
				else check.pop();
			}
			else if (str[i] == ']') {
				if (check.empty() || check.top() != '[') {
					ret = "no";
					break;
				}
				else check.pop();
			}
		}

		if (!check.empty()) ret = "no";
		cout << ret << '\n';
	}
	return 0;
}