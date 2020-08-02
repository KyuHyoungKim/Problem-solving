#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
	return a.first < b.first;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> cables(N); // head, tail
	vector<pair<int, int>> ans(N); // head, idx
	vector<int> lis;
	vector<int> res;
	for (int i = 0; i < N; i++)
		scanf("%d %d", &cables[i].first, &cables[i].second);

	sort(cables.begin(), cables.end(), comp);
	lis.push_back(cables[0].second);
	for (int i = 0; i < N; i++) {
		int idx = lis.size();
		if (lis.back() < cables[i].second) 
			lis.push_back(cables[i].second);
		else {
			idx = lower_bound(lis.begin(), lis.end(), cables[i].second) - lis.begin();
			lis[idx] = cables[i].second;
		}
		ans[i].first = cables[i].first;
		ans[i].second = idx;
	}

	for (int i = N - 1, j = lis.size() - 1; i >= 0; i--) {
		if (ans[i].second == j) 
			j--;
		else 
			res.push_back(ans[i].first);
	}
	sort(res.begin(), res.end());
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d\n", res[i]);
	return 0;
}