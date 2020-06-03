#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> checked(100000);
int main() {
	freopen("input.txt", "r", stdin);
	int N, K, res = 0;
	scanf("%d %d", & N, &K);
	queue <int> now;
	now.push(N);
	while (!now.empty()) {
		queue<int> next;
		while (!now.empty()) {
			int here = now.front();
			if (here == K) {
				printf("%d", res);
				return 0;
			}
			now.pop();
			if (checked[here]) continue;
			else checked[here]++;
			if (here * 2 <= 100000) next.push(2 * here);
			if (here + 1 <= 100000) next.push(1 + here);
			if (here > 0) next.push(here - 1);
		}
		now = next;
		res++;
	}
	printf("%d", res);
	return 0;
}