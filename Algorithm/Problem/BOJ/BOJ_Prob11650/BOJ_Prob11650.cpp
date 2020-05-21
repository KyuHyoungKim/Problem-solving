#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main()
{
	int N = 0;
	scanf("%d", &N);
	vector<pair<int, int>> pos(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &pos[i].first, &pos[i].second);

	sort(pos.begin(), pos.end(), comp);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", pos[i].first, pos[i].second);
	return 0;
}