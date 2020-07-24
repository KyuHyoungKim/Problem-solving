#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<int>> graph(N);
	vector<int> head_cnt(N);
	queue<int> q;
	while (M--) {
		int head, tail;
		scanf("%d %d", &head, &tail);
		graph[head - 1].push_back(tail - 1);
		head_cnt[tail - 1]++;
	}

	for (int i = 0; i < N; i++)
		if (!head_cnt[i]) q.push(i);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		printf("%d ", curr + 1);

		for (int i = 0; i < graph[curr].size(); i++) {
			int next_num = graph[curr][i];
			head_cnt[next_num]--;
			if (!head_cnt[next_num])
				q.push(next_num);
		}
	}
	return 0;
}