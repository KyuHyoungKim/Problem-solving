#define _CRT_SECURE_NO_WARNINGS
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
	int N, M;
	scanf("%d %d", &N, &M);
	vector<vector<pair<int,int>>> gra(N+1);
	vector<int> res(N + 1, 1234567891);
	priority_queue<pair<int, int>, vector<pair<int, int>>,comp> q;
	
	while (M--) {
		int head, tail, cost;
		scanf("%d %d %d", &head, &tail, &cost);
		gra[head].push_back(make_pair(tail, cost));
		gra[tail].push_back(make_pair(head, cost));
	}
	q.push(make_pair(1, 0));
	while (!q.empty()) {
		int now = q.top().first;
		int cost = q.top().second;
		q.pop();
		if (res[now] < cost) continue;
		res[now] = cost;
		for (int i = 0; i < gra[now].size(); i++)
		{
			int Next = gra[now][i].first;
			int cost_Next = gra[now][i].second + cost;

			if (res[Next] > cost_Next)
				q.push(make_pair(Next, cost_Next));
		}
	}
	printf("%d\n", res[N]);
	return 0;
}