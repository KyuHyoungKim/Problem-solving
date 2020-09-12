#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first < b.first;
	}
	bool operator()(const int& a, const int& b) {
		return a > b;
	}
};
int main() {
	int N;
	scanf("%d", &N);
	vector<pair<int, int>> lectures(N);
	priority_queue<int,vector<int>,comp> pq;
	for (int i = 0; i < N; i++)
		scanf("%d %d", &lectures[i].first, &lectures[i].second);

	sort(lectures.begin(), lectures.end(), comp());

	pq.push(lectures[0].second);
	for (int i = 1; i < N; i++) {
		int time = pq.top();

		if (lectures[i].first >= time) 
			pq.pop();
		pq.push(lectures[i].second);
	}

	printf("%d", pq.size());
	return 0;
}