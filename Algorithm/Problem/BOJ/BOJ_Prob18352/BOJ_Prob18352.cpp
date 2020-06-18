#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, K, X;
	scanf("%d %d %d %d", &N, &M, &K, &X);
	vector<vector<int>> gra(N+1);
	vector<int>res(N+1,-1);
	queue<int> q;
	while (M--) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		gra[head].push_back(tail);
	}
	
	q.push(X);
	res[X] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < gra[now].size(); i++)
		{
			int Next = gra[now][i];
			if (res[Next] < 0)
			{
				q.push(Next);
				res[Next] = res[now] + 1;
			}
		}
	}
	int check = 0;
	for (int i = 1; i <= N; i++) {
		if (res[i] == K)
		{
			printf("%d\n", i);
			check = 1;
		}
	}
	if (!check) printf("-1\n");
	return 0;
}