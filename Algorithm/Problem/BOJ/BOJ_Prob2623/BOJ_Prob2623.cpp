#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> order(N);
	vector<int> degree(N);
	vector<int> res;
	queue<int> q;
	while (M--) {
		int num, head, tail;
		scanf("%d %d", &num, &head);
		while (--num) {
			scanf("%d", &tail);
			order[head - 1].push_back(tail - 1);
			degree[tail - 1]++;
			head = tail;
		}
	}
	for (int i = 0; i < N; i++)
		if (!degree[i])
			q.push(i);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		res.push_back(curr);
		for (int i = 0; i < order[curr].size(); i++) {
			int Next = order[curr][i];
			degree[Next]--;
			if (!degree[Next]) 
				q.push(Next);
		}
	}
	if (res.size() == N)
		for (int i = 0; i < N; i++)
			printf("%d\n", res[i] + 1);
	else
		printf("0");
	return 0;
}