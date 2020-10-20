#define _CRT_SECURE_NO_WARNINGS
#define IDX_MIN 0
#define IDX_MAX 100000
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int, int>>DP(IDX_MAX + 1, { -1,-1 });
queue<pair<int, int>> q;

inline void push_n_check(int pos, int pos_new, int cnt) {
	q.push(make_pair(pos_new, cnt));
	DP[pos_new].first = pos;
	DP[pos_new].second = cnt;
}

int main() {
	int N, K;
	vector<int> res;

	scanf("%d %d", &N, &K);
	q.push(make_pair(N, 0));
	DP[N].first = -1;
	DP[N].second = 0;
	while (!q.empty()) {
		int pos = q.front().first;
		int cnt = q.front().second;
		int pos_new[3];
		q.pop();
		if (pos == K) 
			break;
		pos_new[0] = pos - 1;
		pos_new[1] = pos + 1;
		pos_new[2] = pos * 2;
		for (int i = 0; i < 3; i++)
			if (pos_new[i] >= IDX_MIN && pos_new[i] <= IDX_MAX &&DP[pos_new[i]].second < 0)
				push_n_check(pos, pos_new[i], cnt + 1);
	}

	printf("%d\n", DP[K].second);
	res.push_back(K);
	while (DP[res.back()].first != -1) 
		res.push_back(DP[res.back()].first);

	for (int i = res.size() - 1; i >= 0; i--)
		printf("%d ", res[i]);
	return 0;
}