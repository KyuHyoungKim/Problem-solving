#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> cables(N);
	vector<int> lis;
	for (int i = 0; i < N; i++)
		scanf("%d %d", &cables[i].first, &cables[i].second);
	sort(cables.begin(), cables.end(), comp);
	lis.push_back(cables[0].second);
	for (int i = 0; i < N; i++) {
		if (cables[i].second > lis.back())
			lis.push_back(cables[i].second);
		else 
			*(lower_bound(lis.begin(), lis.end(), cables[i].second)) = cables[i].second;
	}
	printf("%d", N - lis.size());
	return 0;
}