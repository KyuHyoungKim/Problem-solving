#include <iostream>
#include <stack>
#include <string>
int main() {
	std::stack<char> oper;
	std::string str, res;
	std::cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') oper.push(str[i]);
		else if (str[i] == '+' || str[i] == '-') {
			while (!oper.empty() && oper.top() != '(')
			{
				res += oper.top();
				oper.pop();
			}
			oper.push(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/'))
			{
				res += oper.top();
				oper.pop();
			}
			oper.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!oper.empty() && oper.top() != '(') {
				res += oper.top();
				oper.pop();
			}
			oper.pop();
		}
		else res += str[i];
	}
	while (!oper.empty()) {
		res += oper.top();
		oper.pop();
	}
	std::cout << res;
	return 0;
}