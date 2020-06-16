#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, head, tail;
	scanf("%d", &N);
	vector<vector<int>> gra(N);
	vector<int> res(N);
	for (int i = 0; i < N - 1; i++) {
		scanf("%d %d", &head, &tail);
		gra[head - 1].push_back(tail - 1);
		gra[tail - 1].push_back(head - 1);
	}
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < gra[now].size(); i++)
		{
			if (!res[gra[now][i]])
			{
				res[gra[now][i]] = now + 1;
				q.push(gra[now][i]);
			}
		}
	}
	for (int i = 1; i < N; i++)
		printf("%d\n", res[i]);
	return 0;
}