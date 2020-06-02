#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	char exp_c[51];
	scanf("%s", exp_c);
	string exp = exp_c, num;
	int oper = 1, res = 0;
	for (int i = 0; i < exp.size(); i++) {
		if (isdigit(exp[i]))
			num += exp[i];
		else {
			res += stoi(num) * oper;
			if (exp[i] == '-') oper = -1;
			num.clear();
		}
	}
	if(!num.empty())
		res += stoi(num) * oper;
	printf("%d\n", res);
	return 0;
}