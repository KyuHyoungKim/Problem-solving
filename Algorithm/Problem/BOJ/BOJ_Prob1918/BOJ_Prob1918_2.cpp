#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <string.h>
std::stack<char> oper;
char str[101];
void func() {
	printf("%c", oper.top());
	oper.pop();
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%s", str);
	int length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') printf("%c", str[i]);
		else if (str[i] == '(') oper.push(str[i]);
		else if (str[i] == '*' || str[i] == '/') {
			while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) func();
			oper.push(str[i]);
		}
		else {
			while (!oper.empty() && oper.top() != '(') func();
			if (str[i] == ')') oper.pop();
			else if (str[i] == '+' || str[i] == '-') oper.push(str[i]);
		}
	}
	while (!oper.empty()) func();
	return 0;
}