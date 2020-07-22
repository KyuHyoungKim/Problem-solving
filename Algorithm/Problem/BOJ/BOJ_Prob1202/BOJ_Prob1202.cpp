#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool comp_jew(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
class comp_pq {
public :
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	}
};
int main() {
	freopen("input.txt", "r", stdin);
	int N, K;
	long long res = 0;
	scanf("%d %d", &N, &K);
	vector<pair<int, int>> jewelries(N);
	vector<int> sack_capacities(K);
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp_pq> pq;
	for (int i = 0; i < N; i++)
		scanf("%d %d", &jewelries[i].first, &jewelries[i].second);
	for (int i = 0; i < K; i++)
		scanf("%d", &sack_capacities[i]);

	sort(jewelries.begin(), jewelries.end(), comp_jew);
	sort(sack_capacities.begin(), sack_capacities.end());
	
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && sack_capacities[i] >= jewelries[j].first)
			pq.push(jewelries[j++]);

		if (!pq.empty()) {
			res += pq.top().second;
			pq.pop();
		}
	}
	printf("%lld", res);
	return 0;
}