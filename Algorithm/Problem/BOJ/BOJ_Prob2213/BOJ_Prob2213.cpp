#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, route_idx;// 0 : 방문, 1 : 노방문
vector<int> weights;
vector<vector<int>> graph, DP;
vector<int> trace;

int solution(int prev, int here, bool is_visit) {
	if (DP[here][is_visit] >= 0)
		return DP[here][is_visit];

	int a1, a2, a;

	DP[here][is_visit] = 0;
	if (is_visit) { //방문
		DP[here][is_visit] += weights[here];
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (next == prev) continue;
			DP[here][is_visit] += solution(here, next, !is_visit);
		}
	}
	else { // 노방문
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (next == prev)
				continue;

			a1 = solution(here, next, !is_visit); // 방문
			a2 = solution(here, next, is_visit); // 노방문
			a = (a1 > a2) ? a1 : a2;
			DP[here][is_visit] += a;
		}
	}

	return DP[here][is_visit];
}

void get_trace(int prev, int here, bool is_visit) {
	if (here == 0)
		return;

	if (is_visit) {
		trace.push_back(here);
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			if (next == prev)
				continue;
			get_trace(here, next, !is_visit);
		}
	}
	else {

		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i];
			bool next_visit = false;

			if (next == prev)
				continue;
			if (DP[next][true] > DP[next][false])
				next_visit = true;

			get_trace(here, next, next_visit);
		}

	}
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int a1, a2, res;
	int head, tail;
	weights.resize(N + 1);
	graph.resize(N + 1);
	DP.resize(N + 1, vector<int>(2, -1));

	for (int i = 1; i <= N; i++)
		scanf("%d", &weights[i]);

	while (scanf("%d %d", &head, &tail) != EOF) {
		graph[head].push_back(tail);
		graph[tail].push_back(head);
	}
	a1 = solution(-1, 1, true);
	a2 = solution(-1, 1, false);

	res = (a1 > a2) ? a1 : a2;
	get_trace(-1, 1, a1 > a2);
	sort(trace.begin(), trace.end());

	printf("%d\n", res);
	for (int i = 0; i < trace.size(); i++)
		printf("%d ", trace[i]);
	return 0;
}