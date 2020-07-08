#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;
long long meas_time(vector<vector<int>>& graph, vector<int>& time, vector<long long>& DP, int curr) {
	long long ret = 0, ans_temp = 0;
	if (DP[curr]>=0) return DP[curr];
	for (int i = 0; i < graph[curr].size(); i++) {
		ans_temp = meas_time(graph, time, DP, graph[curr][i]);
		if (ans_temp > ret) ret = ans_temp;
	}
	ret += time[curr];
	DP[curr] = ret;
	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	int T, N, K, W;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		vector<vector<int>> graph(N);
		vector<int> time(N);
		vector<long long> DP(N, -1);
		int res = 0;
		for (int i = 0; i < N; i++)
			scanf("%d", &time[i]);
		for (int i = 0; i < K; i++) {
			int head, tail;
			scanf("%d %d", &head, &tail);
			graph[tail - 1].push_back(head - 1);
		}
		scanf("%d", &W);
		printf("%lld\n", meas_time(graph, time, DP, W - 1));
	}
	return 0;
}