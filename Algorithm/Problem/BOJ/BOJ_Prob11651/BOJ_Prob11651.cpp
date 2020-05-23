#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second != b.second ? a.second < b.second : a.first < b.first;
}
int main() {
	freopen("input.txt", "r", stdin);
	int N = 0;
	scanf("%d", &N);
	vector<pair<int, int>> Pos(N);
	for (int i = 0; i < N; i++)	scanf("%d %d", &Pos[i].first, &Pos[i].second);
	sort(Pos.begin(), Pos.end(), comp);
	for (int i = 0; i < N; i++) printf("%d %d\n", Pos[i].first, Pos[i].second);
	return 0;
}