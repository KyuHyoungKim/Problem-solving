#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int st, en, N, M;
	scanf("%d %d %d %d", &st, &en, &N, &M);
	vector<vector<int>> gra(N + 1);
	vector<int> res(N+1,-1);
	queue<int> q;
	while (M--) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		gra[head].push_back(tail);
		gra[tail].push_back(head);
	}
	q.push(st);
	res[st] = 0;
	while (!q.empty()) {
		int now = q.front();
		int dist = res[now];
		q.pop();
		res[now] = dist;
		if (now == en) break;
		for (int i = 0; i < gra[now].size(); i++) {
			int Next = gra[now][i];
			if (res[Next] < 0) {
				q.push(Next);
				res[Next] = dist + 1;
			}
		}
	}
	printf("%d\n", res[en]);
	return 0;
}