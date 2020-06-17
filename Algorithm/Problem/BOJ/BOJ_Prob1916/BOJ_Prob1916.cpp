#define _CRT_SECURE_NO_WARNINGS
#define INF 100000000
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, head, tail, cost, start, end;
	scanf("%d %d", &N, & M);
	vector<vector<pair<int, int>>> gra(N + 1);
	vector<int> res(N + 1, INF);
	while (M--) {
		scanf("%d %d %d", &head, &tail, &cost);
		gra[head].push_back(make_pair(tail, cost));
	}
	scanf("%d %d", &start, &end);
	priority_queue<pair<int, int>,vector<pair<int,int>>,comp> pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (res[now] < cost) continue;
		else res[now] = cost;

		if (now == end) break;

		for (int i = 0; i < gra[now].size(); i++) {
			int next = gra[now][i].first;
			int next_cost = gra[now][i].second + cost;
			if (res[next] > next_cost) {
				pq.push(make_pair(next, next_cost));
			}
		}
	}
	printf("%d\n", res[end]);
	return 0;
}