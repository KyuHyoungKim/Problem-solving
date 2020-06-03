#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> checked(100000);
queue<int> Next;

int main() {
	freopen("input.txt", "r", stdin);
	int N, K, res = 0, cnt = 0, check = 1;
	scanf("%d %d", &N, &K);
	queue <int> now;
	now.push(N);
	while (check) {
		queue<int> blank;
		Next.swap(blank);
		while (!now.empty()) {
			int here = now.front();
			if (here == K) {
				check = 0;
				cnt++;
			}
			now.pop();
			if (checked[here] && checked[here] != res) continue;
			else checked[here] = res;
			if (here * 2 <= 100000) Next.push(2 * here);
			if (here + 1 <= 100000) Next.push(1 + here);
			if (here > 0) Next.push(here - 1);
		}
		now = Next;
		res++;
	}
	printf("%d\n%d\n", res - 1, cnt);
	return 0;
}