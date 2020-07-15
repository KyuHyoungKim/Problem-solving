#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
class comp {
public:
	bool operator()(const pair<int, float>& a, const pair<int, float>& b) {
		return a.second > b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	float res = 0;
	scanf("%d", &N);
	vector<vector<pair<int, float>>> dist(N);
	vector<pair<float, float>> pos(N);
	priority_queue<pair<int, float>, vector<pair<int, float>>, comp> pq;
	vector<bool> checked(N);
	for (int i = 0; i < N; i++) {
		scanf("%f %f", &pos[i].first, &pos[i].second);
		for (int j = 0; j < i; j++) {
			float cost = sqrtf(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
			dist[i].push_back(make_pair(j, cost));
			dist[j].push_back(make_pair(i, cost));
		}
	}
	pq.push(make_pair(0, 0));
	int cnt = 0;
	while (!pq.empty()) {
		int star = pq.top().first;
		float cost = pq.top().second;
		pq.pop();
		if (checked[star]) continue;
		if (cnt == N) break;
		res += cost;
		cnt++;
		checked[star] = true;
		for (int i = 0; i < dist[star].size(); i++) 
			if (!checked[dist[star][i].first])
				pq.push(dist[star][i]);
	}

	printf("%.2f", res);
	return 0;
}