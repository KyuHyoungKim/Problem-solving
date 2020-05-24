#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
std::stack<int> st;
int main() {
	freopen("input.txt", "r", stdin);
	std::string res;
	int n = 0, num = 1, input = 0;
	scanf("%d", &n);
	st.push(0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		if (input >= num) {
			while (num <= input) {
				st.push(num++);
				res += '+';
			}
			st.pop();
			res += '-';
		}
		else if (input == st.top()) {
			res += '-';
			st.pop();
		}
		else {
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < res.size(); i++) printf("%c\n", res[i]);
	return 0;
}