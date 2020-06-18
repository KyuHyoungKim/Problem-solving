#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct comp {
	bool operator () (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, M, start, end;
	scanf("%d %d", &N, &M);
	vector<vector<pair<int,int>>> gra(N + 1);
	vector<int> res(N + 1, - 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	while (M--) {
		int head, tail, cost;
		scanf("%d %d %d", &head, &tail, &cost);
		gra[head].push_back({ tail,cost });
		gra[tail].push_back({ head,cost });
	}
	scanf("%d %d", &start, &end);
	pq.push({ start,0 });
	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (res[now] > 0 && res[now] < cost) continue;
		res[now] = cost;
		for (int i = 0; i < gra[now].size(); i++)
		{
			int Next = gra[now][i].first;
			int cost_Next = cost + gra[now][i].second;
			if (res[Next] < 0 || res[Next] > cost_Next)
				pq.push(make_pair(Next, cost_Next));
		}
	}
	printf("%d\n", res[end]);
	return 0;
}