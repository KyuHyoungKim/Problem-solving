#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct comp {
	bool operator() (pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	priority_queue<pair<int, int>,vector<pair<int,int>>,comp> q;	//pos,cnt
	vector<int> res(100001, -1);

	q.push(make_pair(N, 0));
	while (!q.empty()) {
		int now = q.top().first;
		int cnt = q.top().second;
		q.pop();
		if (now == K)
		{
			printf("%d", cnt);
			break;
		}
		int a1 = now * 2, a2 = now + 1, a3 = now - 1;
		if (a1 <= 100000 && (res[a1] < 0 || res[a1] >= 0 && res[a1] > cnt)) {
			q.push(make_pair(a1, cnt));
			res[a1] = cnt;
		}

		if (a2 <= 100000 && (res[a2] < 0 || res[a2] >= 0 && res[a2] > cnt + 1)) {
			q.push(make_pair(a2, cnt + 1));
			res[a2] = cnt + 1;
		}
		if (a3 >= 0 && (res[a3] < 0 || (res[a3] >= 0 && res[a3] > cnt + 1))) {
			q.push(make_pair(a3, cnt + 1));
			res[a3] = cnt + 1;
		}
	}
	return 0;
}