#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int T, N;
	scanf("%d", &T);
	while (T--) {
		int res = 0;
		scanf("%d", &N);
		vector<int> pick(N + 1);
		vector<bool> checked(N + 1);
		for (int i = 1; i <= N; i++) 
			scanf("%d", &pick[i]);
		for (int i = 1; i <= N; i++) {
			if (checked[i]) continue;
			stack<int> st;
			st.push(i);
			checked[i] = true;
			while (!st.empty()) {
				int next = pick[st.top()];
				if (checked[next]) {
					int solo_count = st.size();
					while (!st.empty()) {
						if (st.top() == next) {
							st.pop();
							solo_count = st.size();
							break;
						}
						st.pop();
					}
					res += solo_count;
					break;
				}
				else {
					st.push(next);
					checked[next] = true;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}