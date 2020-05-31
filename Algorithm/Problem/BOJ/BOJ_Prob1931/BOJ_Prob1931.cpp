#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	freopen("input.txt", "r", stdin);
	int N = (1 << 31 - 1), time = 0, res = 0;
	scanf("%d", &N);
	vector<pair<int, int>> meeting(N);
	for (int i = 0; i < N; i++) scanf("%d %d", &meeting[i].first, &meeting[i].second);
	sort(meeting.begin(), meeting.end(), comp);
	for(int i = 0 ; i < N; i++) {
		if (meeting[i].first >= time)
		{
			res++;
			time = meeting[i].second;
		}
	}
	printf("%d\n", res);
	return 0;
}