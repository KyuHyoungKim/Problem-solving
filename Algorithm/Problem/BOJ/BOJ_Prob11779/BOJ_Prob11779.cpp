#define _CRT_SECURE_NO_WARNINGS
#define INF 100000000
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
struct comp {
	bool operator()(tuple<int, int, int>& a, tuple<int, int, int>& b) {
			return get<1>(a) > get<1>(b);
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, start, end;
	scanf("%d %d", &N, &M);
	vector<vector<pair<int, int>>> gra(N + 1);
	vector<pair<int,int>> res(N + 1,make_pair(INF,0));	// cost, prev_node
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> pq; // pos, cost, Prev
	vector<int> path;
	while (M--) {
		int head, tail, cost;
		scanf("%d %d %d", &head, &tail, &cost);
		gra[head].push_back(make_pair(tail, cost));
	}
	scanf("%d %d", &start, &end);
	pq.push(make_tuple(start, 0, start));
	while (!pq.empty()) {
		int now = get<0>(pq.top());
		int cost = get<1>(pq.top());
		int Prev = get<2>(pq.top());
		pq.pop();
		if (res[now].first < cost) continue;
		res[now].first = cost;
		res[now].second = Prev;
		for (int i = 0; i < gra[now].size(); i++) {
			int Next = gra[now][i].first;
			int next_cost = gra[now][i].second + cost;
			if (res[Next].first > next_cost) pq.push(make_tuple(Next, next_cost, now));
		}
	}
	printf("%d\n", res[end].first);
	int node = end;
	path.push_back(end);
	while (path.back() != start) path.push_back(res[path.back()].second);
	printf("%d\n", path.size());
	for (int i = path.size() - 1; i >= 0; --i) printf("%d ", path[i]);
	return 0;
}